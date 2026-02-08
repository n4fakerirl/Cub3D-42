/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:09:46 by ocviller          #+#    #+#             */
/*   Updated: 2026/02/08 13:44:42 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	orientation(t_data *data)
{
	int	i;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (data->info.map[y])
	{
		i = 0;
		while (data->info.map[y][i])
		{
			if (data->info.map[y][i] == 'N' || data->info.map[y][i] == 'S'
				|| data->info.map[y][i] == 'W' || data->info.map[y][i] == 'E')
				count++;
			i++;
		}
		y++;
	}
	if (count == 1)
		return (1);
	else if (count > 1)
		return (ft_error("Only one start position is needed"), 0);
	else
		return (ft_error("Map doesnt have any start position"), 0);
}

int	rows(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (data->info.filled[y])
		y++;
	while (data->info.filled[y - 1][i])
	{
		if (data->info.filled[y - 1][i] != '1'
			&& !ft_isspace(data->info.filled[y - 1][i]))
			return (0);
		i++;
	}
	i = 0;
	while (data->info.filled[0][i])
	{
		if (data->info.filled[0][i] != '1'
			&& !ft_isspace(data->info.filled[0][i]))
			return (0);
		i++;
	}
	return (1);
}

int	columns(t_data *data)
{
	int	i;
	int	y;
	int	len;

	y = 0;
	while (data->info.filled[y])
	{
		i = 0;
		len = ft_strlen(data->info.filled[y]);
		while (ft_isspace(data->info.filled[y][i]))
			i++;
		while (ft_isspace(data->info.filled[y][len - 1]))
			len--;
		if (!(data->info.filled[y][i] == '1' && data->info.filled[y][len
			- 1] == '1'))
			return (0);
		y++;
	}
	return (1);
}

int	zero_one(t_data *data, int y, int i)
{
	if (data->info.filled[y][i] != '1' && data->info.filled[y][i] != '0')
		return (0);
	return (1);
}

int	check_space(t_data *data)
{
	int	y;
	int	i;

	y = 0;
	while (data->info.filled[y])
	{
		i = 0;
		while (data->info.filled[y][i])
		{
			if (data->info.filled[y][i] == '0')
			{
				if (!zero_one(data, y + 1, i))
					return (0);
				if (!zero_one(data, y - 1, i))
					return (0);
				if (!zero_one(data, y, i + 1))
					return (0);
				if (!zero_one(data, y, i - 1))
					return (0);
			}
			i++;
		}
		y++;
	}
	return (1);
}

int	nl_inmap(t_data *data)
{
	int	i;

	i = 0;
	while (data->info.full_file[i])
	{
		if (!ft_strcmp(data->info.full_file[i], "\0"))
			return (0);
		i++;
	}
	return (1);
}

int	parse_map(t_data *data)
{
	if (!orientation(data))
		return (0);
	if (!find_size(data))
		return (0);
	add_spaces(data, 0);
	copy_tab(data);
	find_player(data);
	flood_fill(data, data->info.p_posx, data->info.p_posy);
	if (!nl_inmap(data))
		return (ft_error("empty line in map"), 0);
	if (!rows(data))
		return (ft_error("map is not fully closed"), 0);
	if (!columns(data))
		return (ft_error("map is not fully closed"), 0);
	if (!check_space(data))
		return (ft_error("map is not fully closed"), 0);
	return (1);
}
