/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:42:37 by ocviller          #+#    #+#             */
/*   Updated: 2026/02/19 10:50:14 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map_line(char *str)
{
	int		i;
	char	*search;

	i = 0;
	search = NULL;
	search = ft_strchr(str, '1');
	if (!search)
		return (0);
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '\t' && str[i] != ' ' && str[i] != '\n'
			&& str[i] != '\r')
			return (0);
		i++;
	}
	return (1);
}

void	first_and_last(t_data *data, char **map)
{
	int	i;

	i = 0;
	data->info.fstline_pos = -1;
	data->info.lstline_pos = -1;
	while (map[i])
	{
		if (is_map_line(map[i]))
		{
			if (data->info.fstline_pos == -1)
				data->info.fstline_pos = i;
			else if (i > 0 && space_str(map[i - 1]) && map[i + 1]
				&& !space_str(map[i + 1]))
				data->info.fstline_pos = i;
			else if (i > 0 && !space_str(map[i - 1]) && ((map[i + 1]
						&& space_str(map[i + 1])) || !map[i + 1]))
				data->info.lstline_pos = i;
		}
		i++;
	}
}

int	in_between(t_data *data, int line)
{
	int	flag;

	flag = 0;
	if (line > data->info.lstline_pos)
	{
		while (data->info.full_file[line])
		{
			if (!space_str(data->info.full_file[line]))
				flag = 1;
			line++;
		}
	}
	if (flag == 1)
		return (0);
	return (1);
}

int	correct_line(char *line)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	while (line[i])
	{
		c = line[i];
		if (c != '1' && c != '0' && !ft_isspace(c) && c != 'W' && c != 'N'
			&& c != 'S' && c != 'E')
			return (0);
		i++;
	}
	return (1);
}
