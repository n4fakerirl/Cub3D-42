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
		return (free_struct(data), ft_putstr_fd("mlx crash\n", 2), 1);
	// engine(data);
	// mlx_loop(data->mx.mlx);
	free_struct(data);
	return (0);
}
