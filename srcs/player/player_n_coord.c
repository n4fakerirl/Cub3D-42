/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_n_coord.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:15:58 by gule-bat          #+#    #+#             */
/*   Updated: 2026/02/17 10:22:25 by gule-bat         ###   ########.fr       */
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

void	coord_add_or_sub_x(t_data *data, float x, float y, int side)
{
	float	hb;

	hb = 0.5;
	if (((contact(data, data->player.p_x + x + (hb), data->player.p_y + y, 0)
				&& side == 0) || (contact(data, data->player.p_x + x - (hb),
					data->player.p_y + y, 0) && side == 0))
		|| (contact(data, data->player.p_x - x,
				data->player.p_y - y - (hb), 0) && side == 1) || (contact(data,
				data->player.p_x - x, data->player.p_y - y + hb, 0)
			&& side == 1))
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
	if (!contact(data, data->player.p_x + (csv), data->player.p_y + (snv), 0)
		&& (data->player.z && data->player.p_y - SPEED >= 0))
		coord_add_or_sub_x(data, csv, snv, 0);
	if (!contact(data, data->player.p_x - (csv), data->player.p_y - (snv), 1)
		&& (data->player.s && data->player.p_y + SPEED <= (Y_AXIS - 1)))
		coord_add_or_sub_x(data, csv, snv, 1);
	if (!contact(data, data->player.p_x + (sides_x), data->player.p_y
			+ (sides_y), 2) && data->player.q && data->player.p_x - SPEED >= 0)
		coord_add_or_sub_x(data, sides_x, sides_y, 0);
	if (!contact(data, data->player.p_x - (sides_x), data->player.p_y
			- (sides_y), 3) && data->player.d && data->player.p_x
		+ SPEED <= (X_AXIS)-1)
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
