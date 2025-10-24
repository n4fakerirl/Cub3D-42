/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:10:06 by gule-bat          #+#    #+#             */
/*   Updated: 2025/10/17 15:10:06 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_size(int fd)
{
	char    *line;
	int     i;

	line = NULL;
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		free(line);
		i++;
	}
	close(fd);
	return (i);
}


int	get_file(t_data *data, int size, char **file)
{
	int		fd2;
	int		i;

	i = 0;
	fd2 = open(data->info.file, O_RDONLY);
	if (fd2 < 0)
		return (1);
	while (i < size)
	{
		file[i] = get_next_line(fd2);
		if (!file[i])
			break ;
		printf("%s", file[i]);
		i++;
	}
	file[i] = NULL;
	close(fd2);
	data->info.full_file = file; 
	return (0);
}

int read_infile(int fd, char **file, t_data *data)
{
	int     i;

	i = get_size(fd); // first opened fd closed;
	if (i < 7)
		return (1);
	file = ft_calloc(i+1, sizeof(char *)); // calloc to allocate the size of the double tab;
	if (!file)
		return (1);
	if (get_file(data, i+1, file)) // copy file text to file buffer by reopening + gnl, fd closed;
		return (1);
	// for (int x = 0; x < i; x++)
		// free(file[x]);
	// free(file);
	// data->info.sizey = i;
	return (0);
}

int	search_extension(char *str, const char *ext)	//return 0 if the extension is in the file, put "." before extension
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (!ft_strncmp(&str[i], ext, ft_strlen(ext)))
			return (1);
		i++;
	}
	return (0);
}

void	free_2d(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_int_2d(int **str, int size)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (i < size)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	txt_init(t_data *data)
{
	int	i;
	char *tmp;
	char **file;

	i = 0;
	file = data->info.full_file;
	tmp = NULL;
	data->info.txt_file = ft_calloc(sizeof(char *), 5); // N S E W (1 buffer par coordonnée)
	if (!data->info.txt_file)
		return (1);
	while (file[i] && i < 4)
	{
		if (file[i][4] == '/' && search_extension(file[i], ".xpm") == 1)
		{
			tmp = ft_strdup(&file[i][5]);
			if (!tmp)
				return (1);
			data->info.txt_file[i] = tmp;
		}
		else
			return (perror("invalid texture"), 1);
		i++;
	}
	return (0);
}

int	init_fc_cl(t_data *data)
{
	data->info.fl_cl = ft_calloc(sizeof(int *), 2); // N S E W (1 buffer par coordonnée)
	if (!data->info.txt_file)
		return (1);
	data->info.fl_cl[0] = calloc(sizeof(int), 3);
	if (!data->info.fl_cl[0])
		return (1);
	data->info.fl_cl[1] = calloc(sizeof(int), 3);
	if (!data->info.fl_cl[1])
		return (1);
	return (0);
}

int	get_fc(t_data *data)
{
	int	i;
	char **tmp;
	char **file;
	int		j;
	int		k;
	int		l;

	j = 2;
	i = 0;
	l = 0;
	k = 0;
	file = data->info.full_file;
	tmp = NULL;
	if (init_fc_cl(data))
		return (1);
	while (file[i] && ft_strncmp(file[i], "F", ft_strlen("F")) != 0)
		i++;
	// if ((file[i+1] && file[i+1][0] != 'C'))
		// return (1);
	while (l < 2)
	{
		if (ft_isdigit(file[i+l][j]))
		{
			k = 0;
			tmp = ft_split(&file[i+l][j], ',');
			while (k < 3)
			{
				data->info.fl_cl[l][k] = ft_atoi(tmp[k]);
				printf("%d\n", data->info.fl_cl[l][k]);
				k++;
			}
			free_2d(tmp);
		}
		l++;
	}
	return (0);
}

int parsing_etc(char *infile, t_data *data)
{
	int fd;
	char    **file;

	file = NULL;
	fd = open(infile, O_RDONLY);
	if (fd < 0)
		return (perror("Error fd"), 1);
	data->info.file = infile;
	if (read_infile(fd, file, data)) // reading all the file to put it in a 2d buffer, int fd closed here
		return (1);
	if (txt_init(data)) // get textures
		return (1);
	if (get_fc(data))
		return (1);
	return (0);
}

void	free_struct(t_data *data)
{
	// int i;
	// int j;

	// i = 0;
	// j = 0;
	free_2d(data->info.full_file);
	free_2d(data->info.txt_file);
	free_int_2d(data->info.fl_cl, 2);
	return ;
}

int main(int argc, char **argv)
{
	t_data  data;

	ft_memset(&data, 0, sizeof(t_data));
	if (argc != 2)
		return (perror("Error: ./cub3d map_in_valid_format\n"), 0);
	parsing_etc(argv[1], &data);
	free_struct(&data);
	return (0);
}