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

	x = (int)(floor(f_x * 2.0) / 2.0) / 4;
	y = (int)(floor(f_y * 2.0) / 2.0) / 4;
	if ((x >= data->info.map_x || y >= data->info.map_y) || (x < 0 || y < 0))
		return (1);
	if (!data->info.map[y][x])
		return (1);
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

void	skybox(t_data *data)
{
	t_vec	i;

	i.x = 0;
	i.y = 0;
	while (i.x < X_AXIS)
	{
		i.y = 0;
		i.f_x = get_color(data->txt->ceiling[0],
				data->txt->ceiling[1], data->txt->ceiling[2]);
		while (i.y < Y_AXIS)
		{
			if (i.y >= Y_AXIS / 2)
				i.f_x = BLACK * data->player.fov;
			my_mlx_pixel_put(data->mx.img_st, i.x, i.y, i.f_x);
			i.y++;
		}
		i.x++;
	}
	mlx_put_image_to_window(data->mx.mlx, data->mx.win,
		data->mx.img_st->img, 0, 0);
	return ;
}

int	engine(t_data *data)
{
	t_vec	vec;
	t_vec	player_i;

	(void)vec;
	vec.x = X_AXIS / 2;
	vec.y = Y_AXIS / 2;
	player_coord(data);
	clear_pic(data);
	mlx_put_image_to_window(data->mx.mlx, data->mx.win,
		data->mx.img_st->img, 0, 0);
	skybox(data);
	ray_cast_cam(data);
	print_game_map(data, vec);
	scaled_pxl(data, data->player.p_x, data->player.p_y, GREEN);
	ray_cast(data, vec, player_i);
	mlx_put_image_to_window(data->mx.mlx, data->mx.win,
		data->mx.img_st->img, 0, 0);
	usleep(600);
	return (1);
}
