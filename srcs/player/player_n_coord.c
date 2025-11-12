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
	if (!contact(data, data->player.p_x + (csv * 2), data->player.p_y
			+ (snv * 2), 0) && (data->player.z && data->player.p_y
			- SPEED >= 0))
	{
		data->player.p_x += csv;
		data->player.p_y += snv;
	}
	if (!contact(data, data->player.p_x - (csv * 2), data->player.p_y - (snv
				* 2), 1) && data->player.s && data->player.p_y + SPEED <= (Y_AXIS / 10 - 1))
	{
		data->player.p_x -= csv;
		data->player.p_y -= snv;
	}
	if (!contact(data, data->player.p_x + (csv * 2), data->player.p_y + (snv
				* 2), 2) && data->player.q && data->player.p_x - SPEED >= 0)
	{
		data->player.p_x += csv;
		data->player.p_y -= snv;
	}
	if (!contact(data, data->player.p_x - (csv * 2), data->player.p_y + (snv
				* 2), 3) && data->player.d && data->player.p_x + SPEED <= (X_AXIS / 10) - 1)
	{
		data->player.p_x -= csv;
		data->player.p_y += snv;
	}
}
