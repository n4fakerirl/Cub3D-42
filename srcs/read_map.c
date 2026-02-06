/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:03:37 by ocviller          #+#    #+#             */
/*   Updated: 2026/02/06 16:59:31 by ocviller         ###   ########.fr       */
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

int nbr_endl(const char *s)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

char	*dup_noend(const char *s)
{
	int		i;
	int		j;
	int		srclen;
	char	*dest;

	i = 0;
	j = 0;
	srclen = ft_strlen(s);
	dest = malloc(sizeof(char) * ((srclen + 1) - nbr_endl(s)));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		if (s[i] != '\n' && s[i] != '\r')
		{
			dest[j] = s[i];
			j++;
		}
		i++;
	}
	dest[j] = '\0';
	return (dest);
}

int	get_file(t_data *data, int size, int i, int j)
{
	int		fd2;
	char	*line;

	fd2 = open(data->info.file, O_RDONLY);
	if (fd2 < 0)
		return (1);
	while (i < size)
	{
		line = get_next_line(fd2);
		if (!line)
			break ;
		if (line[0] != '\n' && line[0] != '\0' && line[0] != '\r')
		{
			data->info.full_file[j] = dup_noend(line);
			j++;
		}
		free(line);
		i++;
	}
	data->info.full_file[j] = NULL;
	close(fd2);
	return (0);
}

int	read_infile(int fd, t_data *data)
{
	int	i;
	int	len;

	len = ft_strlen(data->info.file) - 4;
	if (ft_strcmp(data->info.file + len, ".cub"))
		return (ft_error("map isn't a .cub file"), 1);
	i = get_size_file(fd);
	if (i < 7)
		return (1);
	data->info.full_file = ft_calloc(i + 1, sizeof(char *));
	if (!data->info.full_file)
		return (1);
	if (get_file(data, i + 1, 0, 0))
		return (1);
	//for (int i = 0; data->info.full_file[i]; i++)
		//printf("%s", data->info.full_file[i]);
	return (0);
}
