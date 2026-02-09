/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:03:37 by ocviller          #+#    #+#             */
/*   Updated: 2026/02/09 20:38:28 by ocviller         ###   ########.fr       */
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

char	*skip_nl(t_data *data, int *i, int *flag, int fd2)
{
	char	*res;

	data->info.line = "\n";
	(*flag) = 1;
	while ((*i) < data->info.size && (data->info.line[0] == '\n' || data->info.line[0] == '\0'
			|| data->info.line[0] == '\r'))
	{
		data->info.line = get_next_line(fd2);
		if (!data->info.line)
			break ;
		(*i)++;
	}
	res = dup_n(data->info.line);
	if (!res)
		return (free(data->info.line), NULL);
	free(data->info.line);
	return (res);
}

int	dup_in_map(int *j, t_data *data, int fd2)
{
	if ((*j) < 6)
		data->info.full_file[(*j)] = dup_cut(data->info.line);
	else
		data->info.full_file[(*j)] = dup_n(data->info.line);
	if (!data->info.full_file[(*j)])
		return (m_error(data, *j, fd2), 0);
	(*j)++;
	return (1);
}

int	get_file(t_data *data, int flag, int i, int j)
{
	int	fd2;

	fd2 = open(data->info.file, O_RDONLY);
	if (fd2 < 0)
		return (ft_error("can't open file"), 1);
	while (i < data->info.size)
	{
		data->info.line = get_next_line(fd2);
		if (!data->info.line)
			break ;
		if (try_line(data->info.line, flag))
		{
			if (dup_in_map(&j, data, fd2) == 0)
				return (1);
		}
		if (flag == 0 && j > 6)
		{
			data->info.full_file[j] = skip_nl(data, &i, &flag, fd2);
			if (!data->info.full_file[j])
				return (m_error(data, j, fd2), 1);
			j++;
		}
		i++;
	}
	return (data->info.full_file[j] = NULL, close(fd2), 0);
}

int	read_infile(int fd, t_data *data)
{
	int	len;

	len = ft_strlen(data->info.file) - 4;
	if (ft_strcmp(data->info.file + len, ".cub"))
		return (ft_error("map isn't a .cub file"), 1);
	data->info.size = get_size_file(fd);
	if (data->info.size < 7)
		return (ft_error("map or textures missing"), 1);
	data->info.full_file = ft_calloc(data->info.size + 1, sizeof(char *));
	if (!data->info.full_file)
		return (ft_error("malloc error"), 1);
	data->info.size++;
	if (get_file(data, 0, 0, 0))
		return (1);
	return (0);
}
