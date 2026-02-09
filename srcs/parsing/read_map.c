/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nova <nova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:03:37 by ocviller          #+#    #+#             */
/*   Updated: 2026/02/09 18:14:36 by nova             ###   ########.fr       */
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
	char	*line;
	char	*res;

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
	res = dup_n(line);
	if (!res)
		return (free(line), NULL);
	free(line);
	return (res);
}

int	try_line(char *line, int flag)
{
	if ((line[0] != '\n' && line[0] != '\0' && line[0] != '\r') || (flag == 1))
		return (1);
	return (0);
}

char	*trimming(char *line)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*dest;

	start = 0;
	end = ft_strlen(line);
	i = 0;
	while (line[start] && ft_isspace(line[start]))
		start++;
	while (end > start && ft_isspace(line[end - 1]))
		end--;
	dest = malloc(sizeof(char) * (end - start + 1));
	if (!dest)
		return (NULL);
	while (start < end)
	{
		dest[i] = line[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

char *dup_cut(char *line)
{
	char *dest;

	dest = trimming(line);
	if (!dest)
		return (NULL);
	char *tmp;
	tmp = dup_n(dest);
	if (!tmp)
		return (free(dest), NULL);
	free(dest);
	return (tmp);
}

int	get_file(t_data *data, int flag, int i, int j)
{
	int		fd2;
	char	*line;

	fd2 = open(data->info.file, O_RDONLY);
	if (fd2 < 0)
		return (ft_error("can't open file"), 1);
	while (i < data->info.size)
	{
		line = get_next_line(fd2);
		if (!line)
			break ;
		if (try_line(line, flag))
		{
			if (j < 6)
				data->info.full_file[j] = dup_cut(line);
			else
				data->info.full_file[j] = dup_n(line);
			if (!data->info.full_file[j])
				return (m_error(line, data, j, fd2), 1);
			j++;
		}
		if (flag == 0 && j > 6)
		{
			data->info.full_file[j] = skip_nl(data, &i, &flag, fd2);
			if (!data->info.full_file[j])
				return (m_error(line, data, j, fd2), 1);
			j++;
		}
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
		return (ft_error("map or textures missing"), 1);
	data->info.full_file = ft_calloc(data->info.size + 1, sizeof(char *));
	if (!data->info.full_file)
		return (ft_error("malloc error"), 1);
	data->info.size++;
	if (get_file(data, 0, 0, 0))
		return (1);
	return (0);
}
