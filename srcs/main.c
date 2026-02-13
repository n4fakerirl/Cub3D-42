/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:57:51 by ocviller          #+#    #+#             */
/*   Updated: 2026/02/13 14:22:51 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	parsing_start(char *infile, t_data *data)
{
	int	fd;
	int	i;

	i = 0;
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
	if (!create_map(data, 6, 0))
		return (1);
	while (data->info.map[i])
	{
		last_line(data, data->info.map[i], i, 1);
		i++;
	}
	if (!parse_map(data))
		return (1);
	print_data(data);
	return (0);
}

// print_data(data);

void	get_fov(t_data *data)
{
	if (data->info.map[data->info.p_posy][data->info.p_posx] == 'S')
		data->player.fov = PI / 2;
	else if (data->info.map[data->info.p_posy][data->info.p_posx] == 'N')
		data->player.fov = (3 * PI) / 2;
	else if (data->info.map[data->info.p_posy][data->info.p_posx] == 'W')
		data->player.fov = 2 * PI;
	else if (data->info.map[data->info.p_posy][data->info.p_posx] == 'E')
		data->player.fov = PI;
}

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (ft_error("malloc error"), NULL);
	ft_memset(data, 0, sizeof(t_data));
	data->txt = malloc(sizeof(t_txt));
	if (!data->txt)
		return (ft_error("malloc error"), free(data), NULL);
	ft_memset(data->txt, 0, sizeof(t_txt));
	data->txt->floor = calloc(sizeof(int), 3);
	if (!data->txt->floor)
		return (ft_error("malloc error"), free(data->txt), free(data), NULL);
	data->txt->ceiling = calloc(sizeof(int), 3);
	if (!data->txt->ceiling)
	{
		ft_error("malloc error");
		return (free(data->txt->floor), free(data->txt), free(data), NULL);
	}
	ft_bzero(&data->player, sizeof(t_player));
	data->player.p_x = (X_AXIS / 2) / FACTOR;
	data->player.p_y = (Y_AXIS / 2) / FACTOR;
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
	if (init_mx(data))
		return (ft_error("mlx crash"), close_window(data), 1);
	mlx_loop(data->mx.mlx);
	free_struct(data);
	return (0);
}
