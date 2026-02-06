/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_n_coord.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:15:58 by gule-bat          #+#    #+#             */
/*   Updated: 2025/11/12 18:15:58 by gule-bat         ###   ########.fr       */
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

void	coord_calculator(t_data *data, float csv, float snv)
{
	float sides_x = cos(data->player.fov - PI/2) * SPEED;
	float sides_y = sin(data->player.fov - PI/2) * SPEED;
	if (!contact(data, data->player.p_x + (csv * 3), data->player.p_y
			+ (snv * 3), 0) && (data->player.z && data->player.p_y
			- SPEED >= 2))
	{
		data->player.p_x += csv;
		data->player.p_y += snv;
	}
	if (!contact(data, data->player.p_x - (csv * 3), data->player.p_y
			- (snv * 3), 1) && (data->player.s
			&& data->player.p_y + SPEED <= (Y_AXIS - 1)))
	{
		data->player.p_x -= csv;
		data->player.p_y -= snv;
	}
	if (!contact(data, data->player.p_x + (sides_x * 3), data->player.p_y
			- (snv * 3), 2) && data->player.q 
			&& data->player.p_x - SPEED >= 0)
	{
		data->player.p_x += sides_x;
		data->player.p_y += sides_y;
	}
	if (!contact(data, data->player.p_x - (sides_x * 3), data->player.p_y
			+ (snv * 3), 3) && data->player.d 
			&& data->player.p_x + SPEED <= (X_AXIS / 10) - 1)
	{
		data->player.p_x -= sides_x;
		data->player.p_y -= sides_y;
	}
}

void	player_coord(t_data *data)
{
	float	v_fov;
	float	csv;
	float	snv;

	v_fov = 0.03;
	csv = cos(data->player.fov) * SPEED;
	snv = sin(data->player.fov) * SPEED;
	player_coord_fov(data, v_fov);
	coord_calculator(data, csv, snv);
}
