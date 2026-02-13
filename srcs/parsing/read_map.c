/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:03:37 by ocviller          #+#    #+#             */
/*   Updated: 2026/02/13 12:59:59 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_size_file(int fd)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		i++;
	}
	close(fd);
	return (i);
}

char	*skip_nl(t_data *data, int *i, int fd2)
{
	char	*res;
	char	*line;

	line = get_next_line(fd2);
	data->info.flag = 1;
	while ((*i) < data->info.size && (line[0] == '\n' || line[0] == '\0'
			|| line[0] == '\r'))
	{
		free(line);
		line = get_next_line(fd2);
		if (!line)
			break ;
		(*i)++;
	}
	if (!line)
		return (NULL);
	res = dup_n(line);
	if (!res)
		return (free(line), NULL);
	free(line);
	return (res);
}

int	match_line(t_data *data, char *line, int fd2)
{
	if (data->info.j < 6)
		data->info.full_file[data->info.j] = dup_cut(line);
	else if (data->info.j > 6)
		data->info.full_file[data->info.j] = dup_n(line);
	if (!data->info.full_file[data->info.j])
		return (m_error(line, data, fd2), 0);
	last_line(data, line, data->info.j, 0);
	data->info.j++;
	return (1);
}

int	get_file(t_data *data, int i, int fd2)
{
	char	*line;

	while (++i < data->info.size)
	{
		line = get_next_line(fd2);
		if (!line)
			break ;
		if (try_line(line, data->info.flag))
		{
			if (!match_line(data, line, fd2))
				return (1);
		}
		if (data->info.flag == 0 && data->info.j == 6)
		{
			data->info.full_file[data->info.j] = skip_nl(data, &i, fd2);
			if (!data->info.full_file[data->info.j])
				return (m_error(line, data, fd2), 1);
			data->info.j++;
		}
		free(line);
	}
	return (data->info.full_file[data->info.j] = NULL, close(fd2), 0);
}

int	read_infile(int fd, t_data *data)
{
	int	len;
	int	fd2;

	len = ft_strlen(data->info.file) - 4;
	if (ft_strcmp(data->info.file + len, ".cub"))
		return (close(fd), ft_error("map isn't a .cub file"), 1);
	data->info.size = get_size_file(fd);
	if (data->info.size < 7)
		return (ft_error("map or textures missing"), 1);
	data->info.full_file = ft_calloc(data->info.size + 1, sizeof(char *));
	if (!data->info.full_file)
		return (ft_error("malloc error"), 1);
	data->info.size++;
	fd2 = open(data->info.file, O_RDONLY);
	if (fd2 < 0)
		return (ft_error("can't open file"), 1);
	if (get_file(data, -1, fd2))
		return (1);
	return (0);
}
