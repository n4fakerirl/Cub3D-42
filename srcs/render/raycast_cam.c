/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_cam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:26:39 by gule-bat          #+#    #+#             */
/*   Updated: 2025/12/09 19:26:39 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	line_calc(t_data *data, t_vec *fov, t_vec *mv, t_vec fov_p)
{
	(void)fov_p;
	while (!contact(data, mv->f_x + ((0.1 * fov->f_x)),
			mv->f_y + ((0.1 * fov->f_y)), 0))
	{
		if ((mv->f_x / 4 >= data->info.map_x - 1
				|| mv->f_y / 4 >= data->info.map_y - 1))
			break ;
		mv->f_x += ((0.1 * fov->f_x));
		mv->f_y += ((0.1 * fov->f_y));
	}
}

void	flash(t_data *data, t_vec dist)
{
	static int	min;
	static int	max;
	int			mid;

	mid = 0;
	min = (128 * 4) / dist.y;
	max = (128 * 6) / dist.y;
	if (dist.x > (min) && dist.x < (max) && dist.y > 7)
	{
		mid = (dist.y / 3);
		if (dist.x >= (128 * (4.3)) && dist.x <= 128 * (5.7))
		{
			if (dist.y > 14)
				dist.y /= 3;
			mid = dist.y + dist.y / 3;
			line_print_y(data, dist.x, mid, color_range(WHITE, dist.f_x / 16));
			return ;
		}
		line_print_y(data, dist.x, mid, color_range(WHITE, dist.f_x / 15));
	}
}

void	ray_cast_cam(t_data *data)
{
	t_vec	fov;
	t_vec	mv;
	t_vec	fov_p;
	t_vec	dist;
	t_vec	i;

	dist.x = 0;
	fov_p.f_x = (data->player.fov - ((PI)) / 6);
	fov_p.f_y = (data->player.fov + ((PI)) / 6);
	i.f_x = PI / 3 / X_AXIS;
	while (dist.x < X_AXIS)
	{
		vector_sin_cos_plus(&fov, data, &mv, fov_p.f_x);
		line_calc_dda(data, &fov, &mv, NULL);
		dist.f_x = fish_eye_eater(data, mv, fov, fov_p);
		dist.y = (FACTOR / dist.f_x) * (Y_AXIS / 2);
		calc_textures(data, dist, fov, mv);
		flash(data, dist);
		fov_p.f_x += i.f_x;
		dist.x++;
	}
}

		// dist.f_x = lenslesslenght(data, mv);
		// dist.y = Y_AXIS / dist.f_x;