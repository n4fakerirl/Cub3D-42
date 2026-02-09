/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 20:18:31 by gule-bat          #+#    #+#             */
/*   Updated: 2026/02/09 19:57:44 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	color_range(int color, float f)
{
	int	r;
	int	g;
	int	b;

	r = ((color >> 16) & 0xFF) / f;
	g = ((color >> 8) & 0xFF) / f;
	b = (color & 0xFF) / f;
	r = sup_max_color(r);
	g = sup_max_color(g);
	b = sup_max_color(b);
	return ((r << 16) | (g << 8) | b);
}

t_img	*which_side(int a, int b, t_data *data)
{
	if (a == 1)
	{
		if (b == 1)
			return (data->txt->n);
		else
			return (data->txt->s);
	}
	else
	{
		if (b == 1)
			return (data->txt->e);
		else
			return (data->txt->w);
	}
	return (NULL);
}

int	flash_txt(t_vec dist, int color, t_vec tx_info)
{
	int	min;
	int	max;
	int	c;

	min = (128 * 4) / dist.y;
	max = (128 * 6) / dist.y;
	if (dist.x > (min) && dist.x < (max) && dist.y > 7)
	{
		if (dist.x >= (128 * (4.3)) && dist.x <= 128 * (5.7))
		{
			if (dist.y > 14)
				dist.y /= 3;
			c = color_range(WHITE, color * (tx_info.f_x / 16));
			return (c);
		}
		c = color_range(WHITE, color * (tx_info.f_x / 15));
		return (c);
	}
	return (color_range(color, (tx_info.f_x / 6)));
}

void	line_print_y_tx(t_data *data, t_vec tx_info, t_vec dist, t_img *txt)
{
	float	i;
	float	o;
	t_vec	s;

	s.x = 0;
	i = ((Y_AXIS - dist.y) / 2);
	o = i + dist.y;
	if (i < 0)
		i = 1;
	if (o >= Y_AXIS)
		o = (Y_AXIS - 1);
	s.f_x = (float)txt->height / dist.y;
	s.f_y = (i - (Y_AXIS / 2) + dist.y / 2) * s.f_x;
	while (i <= o)
	{
		s.y = (int)s.f_y & (txt->height - 1);
		s.f_y += s.f_x;
		s.x = *(int *)(txt->addr + s.y * txt->line_length + tx_info.x
				* (txt->bpp / 8));
		scaled_pxl_line(data, tx_info.y, i, flash_txt(dist, s.x, tx_info));
		i += 1;
	}
}

void	calc_textures(t_data *data, t_vec dist, t_vec fov, t_vec mv)
{
	float	wall;
	t_vec	txt;
	t_img	*tx_bf;

	tx_bf = which_side(fov.x, mv.x, data);
	if (tx_bf == NULL)
		close_window(data);
	if (fov.x == 0)
		wall = ((mv.f_y * 2.0) / 8.0);
	else
		wall = ((mv.f_x * 2.0) / 8.0);
	wall -= floorf(wall);
	txt.x = (int)(wall * (float)tx_bf->width);
	if (txt.x < 0)
		txt.x = 0;
	if (txt.x >= tx_bf->width)
		txt.x = tx_bf->width - 1;
	txt.y = dist.x;
	txt.f_x = dist.f_x;
	line_print_y_tx(data, txt, dist, tx_bf);
}
