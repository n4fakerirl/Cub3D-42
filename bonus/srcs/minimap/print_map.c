/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 01:35:32 by gule-bat          #+#    #+#             */
/*   Updated: 2026/02/09 19:55:43 by ocviller         ###   ########.fr       */
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
	return ;
}
// else if ((c == '0'))
// my_mlx_pixel_put(im, x, y, BLACK);

int	scaled_pxl_minimap(t_data *data, int x, int y, char c)
{
	int	i;
	int	j;
	int	factor;

	factor = FACTOR * 1.2;
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

int	minimap_tree(t_data *data, t_vec xy, int x2, int *color)
{
	if (xy.x == 0 && data->info.map[xy.y][xy.x] == '\t')
	{
		xy.x++;
		return (0);
	}
	else if (data->info.map[xy.y][xy.x] == '1')
	{
		*color = ORANGE;
		scaled_pxl(data, x2, xy.y, *color);
		*color = 0;
		xy.x++;
	}
	else
		xy.x++;
	return (1);
}

void	print_game_map(t_data *data, t_vec vec)
{
	t_vec	xy;
	int		x2;
	char	**map;
	int		color;

	(void)vec;
	color = 0;
	map = data->info.map;
	xy.y = 0;
	if (!map)
		return ;
	while (map[xy.y])
	{
		xy.x = 0;
		x2 = xy.x;
		while (map[xy.y][xy.x] != '\0')
		{
			if (minimap_tree(data, xy, x2, &color) == 1)
				x2++;
			else
				x2 += 8;
			xy.x++;
		}
		xy.y++;
	}
}
