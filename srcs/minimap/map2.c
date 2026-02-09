/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 01:11:23 by gule-bat          #+#    #+#             */
/*   Updated: 2025/11/06 01:11:23 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	scaled_pxl(t_data *data, int x, int y, int c)
{
	int		i;
	int		j;
	int		factor;

	factor = FACTOR / 4;
	if (c != GREEN)
		factor *= 4;
	i = 0;
	j = 0;
	if (x < 0 || y < 0)
		return (0);
	while (i < factor)
	{
		j = 0;
		while (j < factor)
		{
			my_mlx_pixel_put(data->mx.img_st, x * factor + j,
				y * factor + i, c);
			j++;
		}
		i++;
	}
	return (1);
}
// factor *= 2;
// if pr faire apparaitre le joueur ms bancal imo

void	tab_to_pixel(t_data *data, int *x, int *y, int c)
{
	int	z;

	z = 0;
	while (z < 8)
	{
		scaled_pxl_minimap(data, (*x) + z, *y, c);
		z++;
	}
	*x += 1;
}
