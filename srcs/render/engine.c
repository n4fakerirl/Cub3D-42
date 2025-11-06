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

void	player_coord(t_data *data)
{
	int		v;
	t_vec	pos;
	// float	cos;
	// float	sin;
	// cos = 0;
	// sin = 0;

	pos.x = data->player.p_x;
	pos.y = data->player.p_y;
	v = 1;
	if (data->player.z && pos.y - v >= 0)
		data->player.p_y -= v;
	if (data->player.s && pos.y + v <= 71)
		data->player.p_y += v;
	if (data->player.q && pos.x - v >= 0)
		data->player.p_x -= v;
	if (data->player.d && pos.x + v <= 127)
		data->player.p_x += v;
	printf("x = %f, y = %f\n", data->player.p_x, data->player.p_y);
}
// limites dans if pr les limites de l'ecran donc temp

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

int	engine(t_data *data)
{
	t_vec	vec;

	vec.x = X_AXIS / 2;
	vec.y = Y_AXIS / 2;
	player_coord(data);
	clear_pic(data);
	mlx_put_image_to_window(data->mx.mlx, data->mx.win,
		data->mx.img_st->img, 0, 0);
	scaled_pxl(data, data->player.p_x, data->player.p_y, GREEN);
	print_game_map(data, vec);
	print_map(data, vec);
	mlx_put_image_to_window(data->mx.mlx, data->mx.win,
		data->mx.img_st->img, 0, 0);
	return (1);
}

// ft_memset(data->mx.img_st->addr, 0x000000,
//(data->mx.img_st->height * data->mx.img_st->width));
