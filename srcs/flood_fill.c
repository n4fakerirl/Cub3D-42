/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:35:55 by ocviller          #+#    #+#             */
/*   Updated: 2025/11/06 12:53:36 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	find_player(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->info.map[y])
	{
		x = 0;
		while (data->info.map[y][x])
		{
			if (data->info.map[y][x] == 'W' || data->info.map[y][x] == 'S'
				|| data->info.map[y][x] == 'N' || data->info.map[y][x] == 'E')
			{
				data->info.p_posx = x;
				data->info.p_posy = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	flood_fill(t_data *data, int x, int y)
{
	if (x < 0 || x >= data->info.map_x || y < 0 || y >= data->info.map_y)
		return ;
	if (data->info.filled[y][x] == '1' || data->info.filled[y][x] == 'X')
		return ;
	data->info.filled[y][x] = 'X';
	flood_fill(data, x + 1, y);
	flood_fill(data, x - 1, y);
	flood_fill(data, x, y + 1);
	flood_fill(data, x, y - 1);
}
