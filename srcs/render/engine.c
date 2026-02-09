/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 01:47:02 by gule-bat          #+#    #+#             */
/*   Updated: 2026/02/09 19:57:26 by ocviller         ###   ########.fr       */
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

void	skybox(t_data *data)
{
	t_vec	i;

	i.x = 0;
	i.y = 0;
	while (i.x < X_AXIS)
	{
		i.y = 0;
		i.f_x = get_color(data->txt->ceiling[0], data->txt->ceiling[1],
				data->txt->ceiling[2]);
		while (i.y < Y_AXIS)
		{
			if (i.y >= Y_AXIS / 2)
				i.f_x = get_color(data->txt->floor[0], data->txt->floor[1],
						data->txt->floor[2]);
			my_mlx_pixel_put(data->mx.img_st, i.x, i.y, i.f_x);
			i.y++;
		}
		i.x++;
	}
	mlx_put_image_to_window(data->mx.mlx, data->mx.win, data->mx.img_st->img, 0,
		0);
	return ;
}

// my_mlx_pixel_put(data->mx.img_st, i.x,
// i.y, i.f_x - (i.f_x/8) - (i.x<<i.y)+(i.y>>i.x));

void	print_img_manual(t_data *data, t_img *img)
{
	t_vec	y;
	int		px;

	y.y = 0;
	px = 0;
	if (!(img->addr))
		return ;
	while (y.y < Y_AXIS)
	{
		y.x = 0;
		while (y.x < X_AXIS)
		{
			px = *(int *)(img->addr + y.y * img->line_length + y.x * (img->bpp
						/ 8));
			if ((px & 0xFF000000) != 0xFF000000)
				my_mlx_pixel_put(data->mx.img_st, y.x, y.y, px);
			y.x++;
		}
		y.y++;
	}
}

int	engine(t_data *data)
{
	t_vec	vec;
	t_vec	player_i;

	player_i.f_x = 0;
	player_i.f_y = 0;
	vec.x = X_AXIS / 2;
	vec.y = Y_AXIS / 2;
	player_coord(data);
	clear_pic(data);
	mlx_put_image_to_window(data->mx.mlx, data->mx.win, data->mx.img_st->img, 0,
		0);
	skybox(data);
	ray_cast_cam(data);
	print_game_map(data, vec);
	ray_cast(data, vec, player_i);
	return (1);
}

// scaled_pxl(data, data->player.p_x, data->player.p_y, GREEN);