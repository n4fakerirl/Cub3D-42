/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:09:46 by ocviller          #+#    #+#             */
/*   Updated: 2025/11/06 11:54:46 by ocviller         ###   ########.fr       */
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
	while (data->info.map[y])
		y++;
	while (data->info.map[y - 1][i])
	{
		if (data->info.map[y - 1][i] != '1' && !ft_isspace(data->info.map[y
				- 1][i]))
			return (0);
		i++;
	}
	i = 0;
	while (data->info.map[0][i])
	{
		if (data->info.map[0][i] != '1' && !ft_isspace(data->info.map[0][i]))
			return (0);
		i++;
	}
	return (1);
}

int	each_col(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (ft_isspace(str[i]))
		i++;
	while (ft_isspace(str[len - 1]))
		len--;
	if (!(str[i] == '1' && str[len - 1] == '1'))
		return (0);
	return (1);
}

int	columns(t_data *data)
{
	int	i;

	i = 0;
	while (data->info.map[i])
	{
		if (!each_col(data->info.map[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parse_map(t_data *data)
{
	if (!rows(data))
		return (ft_error("map is not fully closed"), 0);
	if (!columns(data))
		return (ft_error("map is not fully closed"), 0);
	if (!orientation(data))
		return (0);
	if (!find_size(data))
		return (0);
	add_spaces(data, 0);
	return (1);
}
