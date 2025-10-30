/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 01:32:57 by gule-bat          #+#    #+#             */
/*   Updated: 2025/10/30 01:32:57 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_mx(t_data *data)
{
	data->mx.mlx = mlx_init();
	if (!data->mx.mlx)
		return (1);
	data->mx.win = mlx_new_window(data->mx.mlx, X_AXIS, Y_AXIS, "cube");
	if (!data->mx.win)
		return (1);
	data->mx.img_st = malloc(sizeof(t_img));
	if (!data->mx.img_st)
		return (1);
	ft_memset(data->mx.img_st, 0, sizeof(t_img));
	data->mx.img_st->img = mlx_new_image(data->mx.mlx, X_AXIS, Y_AXIS);
	data->mx.img_st->addr = mlx_get_data_addr(data->mx.img_st->img,
			&data->mx.img_st->bpp,
			&data->mx.img_st->line_length,
			&data->mx.img_st->endian);
	mlx_hook(data->mx.win, 17, 0, close_window, data);
	return (0);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color >> 0;
}
