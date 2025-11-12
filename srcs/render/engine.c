/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 01:47:02 by gule-bat          #+#    #+#             */
/*   Updated: 2025/10/30 01:47:02 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	contact(t_data *data, float f_x, float f_y, int c)
{
	int	x;
	int	y;

	x = (int)f_x / 4;
	y = (int)f_y / 4;
	if (c == 1 && data->info.map[y][x] == '1')
		return (1);
	if (c == 3 && data->info.map[y][x] == '1')
		return (1);
	if (c == 0 && data->info.map[y][x] == '1')
		return (1);
	if (c == 2 && data->info.map[y][x] == '1')
		return (1);
	return (0);
}

void	player_coord(t_data *data)
{
	float	v_fov;
	float	csv;
	float	snv;

	v_fov = 0.07;
	csv = cos(data->player.fov) * SPEED;
	snv = sin(data->player.fov) * SPEED;
	player_coord_fov(data, v_fov);
	coord_calculator(data, csv, snv);
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
	vec.f_x = cos(data->player.fov);
	vec.f_y = sin(data->player.fov);
	player_i.f_x = data->player.p_x + ((0.3 * vec.f_x));
	player_i.f_y = data->player.p_y + ((0.3 * vec.f_y));
	while (1)
	{
		if (contact(data, player_i.f_x + ((0.3 * vec.f_x)),
				player_i.f_y + ((0.3 * vec.f_y)), 0))
			break ;
		scaled_pxl(data, player_i.f_x, player_i.f_y, GREEN);
		player_i.f_x += ((0.3 * vec.f_x));
		player_i.f_y += ((0.3 * vec.f_y));
	}
}

int	engine(t_data *data)
{
	t_vec	vec;
	t_vec	player_i;

	vec.x = X_AXIS / 2;
	vec.y = Y_AXIS / 2;
	player_coord(data);
	clear_pic(data);
	mlx_put_image_to_window(data->mx.mlx, data->mx.win,
		data->mx.img_st->img, 0, 0);
	print_game_map(data, vec);
	print_map(data, vec);
	scaled_pxl(data, data->player.p_x, data->player.p_y, GREEN);
	ray_cast(data, vec, player_i);
	mlx_put_image_to_window(data->mx.mlx, data->mx.win,
		data->mx.img_st->img, 0, 0);
	usleep(6000);
	return (1);
}
