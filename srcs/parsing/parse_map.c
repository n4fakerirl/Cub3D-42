/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:09:46 by ocviller          #+#    #+#             */
/*   Updated: 2026/02/17 17:03:34 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	wrong_pos(t_data *data, int i, int y)
{
	while (data->info.map[y])
	{
		i = 0;
		while (data->info.map[y][i])
		{
			countalnum(data, data->info.map[y][i], y);
			i++;
		}
		y++;
	}
	if (!msg_pos(data))
		return (0);
	return (1);
}

int	orientation(t_data *data, int y)
{
	int	i;
	int	count;

	count = 0;
	while (data->info.map[y])
	{
		i = 0;
		while (data->info.map[y][i])
		{
			if (data->info.map[y][i] == 'N' || data->info.map[y][i] == 'S'
				|| data->info.map[y][i] == 'W' || data->info.map[y][i] == 'E')
				count++;
			else if (!wrong_pos(data, 0, 0))
				return (0);
			i++;
		}
		y++;
	}
	if (count > 1)
		return (ft_error("only one start position is needed"), 0);
	else if (count < 1)
		return (ft_error("map doesnt have any start position"), 0);
	return (1);
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
		while (data->info.filled[y][i] && ft_isspace(data->info.filled[y][i]))
			i++;
		while (len - 1 > i && ft_isspace(data->info.filled[y][len - 1]))
			len--;
		if (!(data->info.filled[y][i] == '1' && data->info.filled[y][len
			- 1] == '1') && y <= data->info.lstline_pos)
			return (0);
		y++;
	}
	return (1);
}

int	parse_map(t_data *data)
{
	if (!is_map(data))
		return (0);
	if (!find_size(data))
		return (0);
	if (!useless_inmap(data, 0, 0))
		return (0);
	if (!nl_inmap(data))
		return (ft_error("empty line in map"), 0);
	add_spaces(data, 0);
	if (!copy_tab(data))
		return (ft_error("malloc error"), 0);
	find_player(data);
	flood_fill(data, data->info.p_posx, data->info.p_posy);
	if (!rows(data))
		return (ft_error("map is not fully closed"), 0);
	if (!columns(data))
		return (ft_error("map is not fully closed"), 0);
	if (!check_space(data))
		return (ft_error("map is not fully closed"), 0);
	if (!orientation(data, 0))
		return (0);
	return (1);
}

// for (int i = 0; data->info.map[i]; i++)
// 		printf("map[%d][%s]\n", i, data->info.map[i]);
// 	printf("FIRST LINE : %d\nLAST LINE %d\n", data->info.fstline_pos,
		// data->info.lstline_pos);