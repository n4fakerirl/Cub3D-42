/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 20:08:43 by gule-bat          #+#    #+#             */
/*   Updated: 2026/02/09 19:57:21 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	rc_dda_dir_selector(t_data *data, t_vec *sd, t_vec dlt, t_vec *dir)
{
	if (dir->f_x < 0)
	{
		sd->x = -1;
		sd->f_x = (data->player.p_x - dlt.x * FACTOR) * dlt.f_x / FACTOR;
	}
	else
	{
		sd->x = 1;
		sd->f_x = ((dlt.x + 1.0) * FACTOR - data->player.p_x) * dlt.f_x
			/ FACTOR;
	}
	if (dir->f_y < 0)
	{
		sd->y = -1;
		sd->f_y = (data->player.p_y - dlt.y * FACTOR) * dlt.f_y / FACTOR;
	}
	else
	{
		sd->y = 1;
		sd->f_y = ((dlt.y + 1.0) * FACTOR - data->player.p_y) * dlt.f_y
			/ FACTOR;
	}
}

void	dda_loop_content(t_vec *sd, t_vec dlt, t_vec *dir, t_vec *mv)
{
	if (sd->f_x < sd->f_y)
	{
		sd->f_x += dlt.f_x;
		mv->f_x += 0.1 * sd->x;
		dir->x = 0;
	}
	else
	{
		sd->f_y += dlt.f_y;
		mv->f_y += ((0.1 * sd->y));
		dir->x = 1;
	}
}

void	line_calc_dda(t_data *data, t_vec *dir, t_vec *mv, float *txt)
{
	t_vec	dlt;
	t_vec	sd;

	(void)txt;
	ft_memset(&dlt, 0, sizeof(t_vec));
	dlt.x = (int)(data->player.p_x) / FACTOR;
	dlt.y = (int)(data->player.p_y) / FACTOR;
	if (dir->f_x != 0)
		dlt.f_x = fabs(FACTOR / dir->f_x);
	else
		dlt.f_x = INFINITY;
	if (dir->f_y != 0)
		dlt.f_y = fabs(FACTOR / dir->f_y);
	else
		dlt.f_y = INFINITY;
	rc_dda_dir_selector(data, &sd, dlt, dir);
	while (!contact(data, mv->f_x, mv->f_y, 0))
		dda_loop_content(&sd, dlt, dir, mv);
	if (dir->x)
		mv->x = sd.y;
	else
		mv->x = sd.x;
}

float	fish_eye_eater(t_data *data, t_vec mv, t_vec fov, t_vec fov_p)
{
	float	raw;
	float	angle;

	(void)fov;
	raw = lenght(mv.f_x - data->player.p_x, mv.f_y - data->player.p_y);
	angle = fov_p.f_x - data->player.fov;
	return (raw * cosf(angle));
}
