/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_cam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:26:39 by gule-bat          #+#    #+#             */
/*   Updated: 2025/12/09 19:26:39 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	line_calc(t_data *data, t_vec *fov, t_vec *mv, t_vec fov_p)
{
	(void)fov_p;
	while (!contact(data, mv->f_x + ((SPEED * fov->f_x)),
			mv->f_y + ((SPEED * fov->f_y)), 0))
	{
		if ((mv->f_x / 4 >= data->info.map_x - 1
				|| mv->f_y / 4 >= data->info.map_y - 1))
			break ;
		mv->f_x += ((SPEED * fov->f_x));
		mv->f_y += ((SPEED * fov->f_y));
	}
}

int	sup_max_color(int color)
{
	if (color > 255)
		return (255);
	if (color < 0)
		return (0);
	return (color);
}

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

float	lenslesslenght(t_data *data, t_vec mv)
{
	t_vec	dlt;
	t_vec	angle;

	dlt.f_x = mv.f_x - data->player.p_x;
	dlt.f_y = mv.f_y - data->player.p_y;
	angle.f_x = atan2(dlt.f_y, dlt.f_x) - data->player.fov;
	angle.f_y = lenght(dlt.f_x, dlt.f_y) * cos(angle.f_x);
	return (angle.f_y);
}

void	ray_cast_cam(t_data *data)
{
	t_vec	fov;
	t_vec	mv;
	t_vec	fov_p;
	t_vec	dist;
	t_vec	i;

	dist.x = 0;
	fov_p.f_x = (data->player.fov - ((PI)) / 8);
	fov_p.f_y = (data->player.fov + ((PI)) / 8);
	i.f_x = PI / 4 / X_AXIS;
	while (dist.x < X_AXIS)
	{
		i.x = ORANGE;
		vector_sin_cos_plus(&fov, data, &mv, fov_p.f_x);
		line_calc(data, &fov, &mv, fov_p);
		dist.f_x = lenslesslenght(data, mv);
		dist.y = (FACTOR / dist.f_x) * (X_AXIS / 2);
		if (dist.x >= (X_AXIS / 3) && dist.x <= dist.x - (X_AXIS / 3))
			i.x = color_range(i.x, 2 * dist.f_x);
		if (dist.x >= (X_AXIS / 2) - 50 && dist.x <= 50 + dist.x - (X_AXIS / 2))
			i.x++;
		line_print_y(data, dist.x, dist.y, color_range(RED, (dist.f_x) / 3));
		fov_p.f_x += i.f_x;
		dist.x++;
	}
}
