/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:36:44 by gule-bat          #+#    #+#             */
/*   Updated: 2025/12/09 19:36:44 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	sup_max_color(int color)
{
	if (color > 255)
		return (255);
	if (color < 0)
		return (0);
	return (color);
}

float	lenght(float x, float y)
{
	float	dist;

	dist = 0;
	dist = sqrt(x * x + y * y);
	return (dist);
}

int	get_color(int r, int g, int b)
{
	int	color;

	color = 255 << 24;
	color = color | (r << 16);
	color = color | (g << 8);
	color = color | (b);
	return (color);
}

void	clear_pic(t_data *data)
{
	t_vec	v;

	v.y = 0;
	while (v.y < Y_AXIS)
	{
		v.x = 0;
		while (v.x < X_AXIS)
		{
			my_mlx_pixel_put(data->mx.img_st, v.x, v.y, BLACK);
			v.x++;
		}
		v.y++;
	}
}

void	ray_cast(t_data *data, t_vec vec, t_vec player_i)
{
	float	fov;
	float	fovm;

	fov = (data->player.fov - ((PI)) / 8);
	fovm = (data->player.fov + ((PI)) / 8);
	vec.f_x = cos(data->player.fov);
	vec.f_y = sin(data->player.fov);
	player_i.f_x = data->player.p_x + ((SPEED * vec.f_x));
	player_i.f_y = data->player.p_y + ((SPEED * vec.f_y));
	while ((fov - fovm) <= 0)
	{
		vector_sin_cos_plus(&vec, data, &player_i, fov);
		while (!contact(data, player_i.f_x + ((SPEED * vec.f_x)),
				player_i.f_y + ((SPEED * vec.f_y)), 0))
		{
			scaled_pxl(data, player_i.f_x, player_i.f_y, GREEN);
			player_i.f_x += ((SPEED * vec.f_x));
			player_i.f_y += ((SPEED * vec.f_y));
			if ((player_i.f_x / 8 >= data->info.map_x - 1
					|| player_i.f_y / 8 >= data->info.map_y - 1))
				break ;
		}
		fov += 0.01;
	}
}
