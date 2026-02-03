/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_cam_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:26:51 by gule-bat          #+#    #+#             */
/*   Updated: 2025/12/09 19:26:51 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	scaled_pxl_line(t_data *data, int x, int y, int c)
{
	int		i;
	int		j;
	int		factor;

	factor = FACTOR / 10;
	i = 0;
	j = 0;
	while (i < factor)
	{
		j = 0;
		while (j < factor)
		{
			my_mlx_pixel_put(data->mx.img_st, x * factor + j,
				y * factor + i, c);
			j++;
		}
		i++;
	}
	return (1);
}

void	line_print_y(t_data *data, int xpos, float wall, int color)
{
	float	i;
	float	o;

	i = ((Y_AXIS - wall) / 2);
	o = i + wall;
	if (i < 0)
		i = 1;
	if (o >= Y_AXIS)
		o = (Y_AXIS - 1);
	while (i <= o)
	{
		scaled_pxl_line(data, xpos, i, color);
		i += 1;
	}
}

void	vector_sin_cos_plus(t_vec *vec, t_data *data, t_vec *plr_i, float fov)
{
	vec->f_x = cos(fov);
	vec->f_y = sin(fov);
	plr_i->f_x = data->player.p_x + ((0.1 * vec->f_x));
	plr_i->f_y = data->player.p_y + ((0.1 * vec->f_y));
}
