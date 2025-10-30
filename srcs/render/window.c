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
	mlx_destroy_image(data->mx.mlx, data->mx.img_st->img);
	mlx_destroy_window(data->mx.mlx, data->mx.win);
	mlx_destroy_display(data->mx.mlx);
	free(data->mx.mlx);
	free(data->mx.img_st);
	free_struct(data);
	exit(0);
	return (0);
}
