/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 01:35:32 by gule-bat          #+#    #+#             */
/*   Updated: 2025/10/30 01:35:32 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	pxl_type(t_data *data, int x, int y, int c)
{
	t_img	*im;

	im = data->mx.img_st;
	if ((c == 'N') || (c == 'S') || (c == 'W') || (c == 'E'))
		my_mlx_pixel_put(im, x, y, GREEN);
	else if (c == '1')
		my_mlx_pixel_put(im, x, y, WHITE);
	else if ((c == '0'))
		my_mlx_pixel_put(im, x, y, BLACK);
	else
		my_mlx_pixel_put(im, x, y, BLACK);
	return ;
}

int	scaled_pxl(t_data *data, int x, int y, char c)
{
	int		i;
	int		j;
	int		factor;

	factor = FACTOR;
	i = 0;
	j = 0;
	while (i < factor)
	{
		j = 0;
		while (j < factor)
		{
			pxl_type(data, x * factor + j, y * factor + i, c);
			j++;
		}
		i++;
	}
	return (1);
}

void	tab_to_pixel(t_data *data, int *x, int *y, int c)
{
	int	z;

	z = 0;
	while (z < 8)
	{
		scaled_pxl(data, (*x) + z, *y, c);
		z++;
	}
	*x += 1;
}

t_vec	vec_offset(int x, int y)
{
	t_vec	v;

	v.x = (((X_AXIS - x) / FACTOR) / 2);
	v.y = (((Y_AXIS - y) / FACTOR) / 2);
	return (v);
}

void	print_map(t_data *data, t_vec vec)
{
	t_vec	xy;
	int		x2;
	char	**map;

	map = data->info.map;
	xy.y = 0;
	while (map[xy.y])
	{
		xy.x = 0;
		x2 = xy.x;
		while (map[xy.y][xy.x] != '\0')
		{
			if (xy.x == 0 && map[xy.y][xy.x] == '\t')
			{
				tab_to_pixel(data, &xy.x, &xy.y, '0');
				x2 += 8;
			}
			else
			{
				scaled_pxl(data, x2, xy.y, map[xy.y][xy.x]);
				xy.x++;
				x2++;
			}
		}
		xy.y++;
	}
	vec = vec_offset(x2, xy.y);
	mlx_put_image_to_window(data->mx.mlx, data->mx.win, data->mx.img_st->img,
		vec.x / (FACTOR / 2), vec.y / (FACTOR / 2));
}
