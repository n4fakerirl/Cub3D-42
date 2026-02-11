/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:42:37 by ocviller          #+#    #+#             */
/*   Updated: 2026/02/11 12:43:12 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	run_read(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!line)
			break ;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

void	last_line(t_data *data, char *line, int j)
{
	int		i;
	int		flag;
	char	*search;

	search = NULL;
	i = 0;
	flag = 1;
	search = ft_strchr(line, '1');
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '\n' && line[i] != ' '
			&& line[i] != '\t')
			flag = 0;
		else if (!search)
			flag = 0;
		i++;
	}
	if (data->info.flag == 1 && flag == 1)
		data->info.lstline_pos = j;
}
