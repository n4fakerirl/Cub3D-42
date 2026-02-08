/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:03:37 by ocviller          #+#    #+#             */
/*   Updated: 2026/02/08 18:02:18 by ocviller         ###   ########.fr       */
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

void	skip_nl(t_data *data, int *i, int *flag, int fd2)
{
	char	*line;

	line = "\n";
	(*flag) = 1;
	while ((*i) < data->info.size && (line[0] == '\n' || line[0] == '\0'
			|| line[0] == '\r'))
	{
		line = get_next_line(fd2);
		if (!line)
			break ;
		(*i)++;
	}
	free(line);
}

int	try_line(char *line, int flag)
{
	if ((line[0] != '\n' && line[0] != '\0' && line[0] != '\r') || (flag == 1))
		return (1);
	return (0);
}

void m_error(char *line, t_data *data, int j, int fd2)
{
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd2);
	}
	free(line);
	close(fd2);
	data->info.full_file[j] = NULL;
	ft_error("failed malloc");
}

int	get_file(t_data *data, int flag, int i, int j)
{
	int		fd2;
	char	*line;

	fd2 = open(data->info.file, O_RDONLY);
	if (fd2 < 0)
		return (ft_error("cannot open file"), 1);
	while (i < data->info.size)
	{
		line = get_next_line(fd2);
		if (!line)
			break;
		if (try_line(line, flag))
		{
			data->info.full_file[j] = NULL;//dup_n(line);
			if (!data->info.full_file[j])
				return (m_error(line, data, j, fd2), 1);
			j++;
		}
		if (flag == 0 && j > 6)
			skip_nl(data, &i, &flag, fd2);
		free(line);
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
		return (1);
	data->info.full_file = ft_calloc(data->info.size + 1, sizeof(char *));
	if (!data->info.full_file)
		return (1);
	data->info.size++;
	if (get_file(data, 0, 0, 0))
		return (1);
	return (0);
}
