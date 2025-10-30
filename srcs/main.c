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

int	useless_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 'N' && str[i] != 'S' && str[i] != 'W' && str[i] != 'E'
			&& str[i] != '1' && str[i] != '0' && !ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	create_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->info.full_file[6 + i])
		i++;
	data->info.map = malloc(sizeof(char *) * (i + 1));
	if (!data->info.map)
		return (0);
	i = 0;
	while (data->info.full_file[6 + i])
	{
		data->info.map[i] = ft_strdup(data->info.full_file[6 + i]);
		if (!data->info.map[i])
			return (free_tab(data->info.map), 0);
		if (!useless_line(data->info.map[i]))
			return (data->info.map[++i] = NULL,
				ft_error("useless line in file or map isn't last"), 0);
		i++;
	}
	data->info.map[i] = NULL;
	return (1);
}

int	parsing_start(char *infile, t_data *data)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd < 0)
		return (ft_error("can't open file"), 1);
	data->info.file = infile;
	if (read_infile(fd, data))
		return (1);
	if (txt_init(data, 0))
		return (1);
	if (!get_fc(data))
		return (1);
	if (!create_map(data))
		return (1);
	if (!parse_map(data))
		return (1);
	print_data(data);
	return (0);
}

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	ft_memset(data, 0, sizeof(t_data));
	data->txt = malloc(sizeof(t_txt));
	if (!data->txt)
		return (free(data), NULL);
	ft_memset(data->txt, 0, sizeof(t_txt));
	data->txt->floor = calloc(sizeof(int), 3);
	if (!data->txt->floor)
		return (free(data->txt), free(data), NULL);
	data->txt->ceiling = calloc(sizeof(int), 3);
	if (!data->txt->ceiling)
		return (free(data->txt->floor), free(data->txt), free(data), NULL);
	return (data);
}

int	main(int argc, char **argv)
{
	t_data	*data;	

	if (argc != 2)
		return (ft_error("./cub3d map_in_valid_format"), 1);
	data = init_data();
	if (!data)
		return (1);
	if (parsing_start(argv[1], data) == 1)
		return (free_struct(data), 1);
	init_mx(data);
	engine(data);
	mlx_loop(data->mx.mlx);
	free_struct(data);
	return (0);
}
