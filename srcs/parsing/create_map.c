/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>                    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:39:22 by ocviller          #+#    #+#             */
/*   Updated: 2026/02/11 12:39:24 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	find_size(t_data *data)
{
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (data->info.map[y])
	{
		if (data->info.map_x < (int)len_tab(data->info.map[y]))
			data->info.map_x = (int)len_tab(data->info.map[y]);
		y++;
	}
	data->info.map_y = y;
	data->info.filled = malloc(sizeof(char *) * (data->info.map_y + 1));
	if (!data->info.filled)
		return (ft_error("malloc error"), 0);
	while (i < data->info.map_y)
	{
		data->info.filled[i] = malloc(sizeof(char) * (data->info.map_x + 1));
		if (!data->info.filled[i])
			return (ft_error("malloc error"), 0);
		i++;
	}
	data->info.filled[i] = NULL;
	return (1);
}

int	space_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	create_map(t_data *data, int y, int i)
{
	while (data->info.full_file[y + i])
		i++;
	data->info.map = malloc(sizeof(char *) * (i + 1));
	if (!data->info.map)
		return (ft_error("malloc error"), 0);
	i = 0;
	while (data->info.full_file[y + i])
	{
		if (y + i > data->info.lstline_pos && space_str(data->info.full_file[y
					+ i]))
		{
			y++;
			continue ;
		}
		else if (y + i <= data->info.lstline_pos
			|| !space_str(data->info.full_file[y + i]))
			data->info.map[i] = ft_strdup(data->info.full_file[y + i]);
		if (!data->info.map[i])
			return (ft_error("malloc error"), 0);
		i++;
	}
	data->info.map[i] = NULL;
	return (1);
}

int	fill_tab(t_data *data, int y, int *i, int *j)
{
	int	tabs;

	tabs = 4;
	if (data->info.map[y][*(i)] == '\t')
	{
		while (tabs > 0)
		{
			data->info.filled[y][*(j)] = ' ';
			(*j)++;
			tabs--;
		}
		(*i)++;
		return (1);
	}
	return (0);
}

void	add_spaces(t_data *data, int y)
{
	int	i;
	int	j;

	while (data->info.map[y])
	{
		j = 0;
		i = 0;
		while (data->info.map[y][i])
		{
			if (!fill_tab(data, y, &i, &j))
			{
				data->info.filled[y][j] = data->info.map[y][i];
				j++;
				i++;
			}
		}
		while (j < data->info.map_x)
		{
			data->info.filled[y][j] = ' ';
			j++;
		}
		data->info.filled[y][j] = '\0';
		y++;
	}
}
