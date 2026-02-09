/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 01:30:51 by gule-bat          #+#    #+#             */
/*   Updated: 2025/10/30 01:30:51 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	close_window(t_data *data)
{
	if (data->mx.mlx && data->mx.img_st->img)
		mlx_destroy_image(data->mx.mlx, data->mx.img_st->img);
	free_txt(data);
	if (data->mx.mlx && data->mx.win)
		mlx_destroy_window(data->mx.mlx, data->mx.win);
	if (data->mx.mlx)
		mlx_destroy_display(data->mx.mlx);
	if (data->mx.mlx)
		free(data->mx.mlx);
	if (data->mx.img_st)
		free(data->mx.img_st);
	free_struct(data);
	exit(0);
	return (0);
}
