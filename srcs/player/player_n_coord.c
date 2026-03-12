/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_n_coord.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:15:58 by gule-bat          #+#    #+#             */
/*   Updated: 2026/03/12 10:30:37 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	player_coord_fov(t_data *data, float v_fov)
{
	if (data->player.l)
		data->player.fov -= v_fov;
	if (data->player.r)
		data->player.fov += v_fov;
	if (data->player.fov > 2 * PI)
		data->player.fov = 0;
	if (data->player.fov < 0)
		data->player.fov = 2 * PI;
}

int	map_limits(t_data *data, float x, float y)
{
	int	try_x;
	int	try_y;

	try_x = (int)(floor(x * 2.0) / 2.0) / 4;
	try_y = (int)(floor(y * 2.0) / 2.0) / 4;
	if ((try_x >= data->info.map_x || try_y >= data->info.map_y) || (try_x < 0
			|| try_y < 0))
		return (0);
	return (1);
}

void	coord_add_or_sub_x(t_data *data, float x, float y, int side)
{
	float	hb;

	hb = 0.5;
	if (side == 0 && !map_limits(data, (data->player.p_x + x + hb),
			(data->player.p_y + y + hb)))
		return ;
	if (side == 1 && !map_limits(data, (data->player.p_x - x + hb),
			(data->player.p_y - y + hb)))
		return ;
	if (side == 0 && ((data->player.p_x + x || data->player.p_y + y) < 1))
		return ;
	if (side == 1 && ((data->player.p_x - x || data->player.p_y - y) < 1))
		return ;
	if (side == 0)
	{
		data->player.p_x += x;
		data->player.p_y += y;
	}
	else
	{
		data->player.p_x -= x;
		data->player.p_y -= y;
	}
}

void	coord_calculator(t_data *data, float csv, float snv)
{
	float	sides_x;
	float	sides_y;

	sides_y = sin(data->player.fov - PI / 2) * SPEED / 2;
	sides_x = cos(data->player.fov - PI / 2) * SPEED / 2;
	if (data->player.z)
		coord_add_or_sub_x(data, csv, snv, 0);
	if (data->player.s)
		coord_add_or_sub_x(data, csv, snv, 1);
	if (data->player.q)
		coord_add_or_sub_x(data, sides_x, sides_y, 0);
	if (data->player.d)
		coord_add_or_sub_x(data, sides_x, sides_y, 1);
}

void	player_coord(t_data *data)
{
	float	v_fov;
	float	csv;
	float	snv;

	v_fov = 0.04;
	csv = cos(data->player.fov) * SPEED;
	snv = sin(data->player.fov) * SPEED;
	player_coord_fov(data, v_fov);
	coord_calculator(data, csv, snv);
}
