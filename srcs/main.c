/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: gule-bat <gule-bat@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/10/17 15:10:06 by gule-bat          #+#    #+#             */
/*   Updated: 2025/10/17 15:10:06 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	init_fc_cl(t_data *data)
{
	data->info.fl_cl = ft_calloc(sizeof(int *), 2);
	if (!data->info.fl_cl)
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
	int i;
	char **tmp;
	char **file;
	int j;
	int k;
	int l;

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
		if (ft_isdigit(file[i + l][j]))
		{
			k = 0;
			tmp = ft_split(&file[i + l][j], ',');
			while (k < 3)
			{
				data->info.fl_cl[l][k] = ft_atoi(tmp[k]);
				printf("%d\n", data->info.fl_cl[l][k]);
				k++;
			}
			free_tab(tmp);
		}
		l++;
	}
	return (0);
}

int	parsing_start(char *infile, t_data *data)
{
	int fd;
	char **file;

	file = NULL;
	fd = open(infile, O_RDONLY);
	if (fd < 0)
		return (perror("Error fd"), 1);
	data->info.file = infile;
	if (read_infile(fd, data))
		return (1);
	if (txt_init(data))
		return (1);
	if (get_fc(data))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data data;

	ft_memset(&data, 0, sizeof(t_data));
	if (argc != 2)
		return (perror("Error: ./cub3d map_in_valid_format\n"), 0);
	parsing_start(argv[1], &data);
	free_struct(&data);
	return (0);
}
