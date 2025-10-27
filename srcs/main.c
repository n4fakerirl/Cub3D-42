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
		return (perror("Error fd"), 1);
	data->info.file = infile;
	if (read_infile(fd, data))
		return (1);
	if (txt_init(data))
		return (1);
	if (!get_fc(data))
		return (1);
	print_data(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	if (argc != 2)
		return (perror("Error: ./cub3d map_in_valid_format\n"), 0);
	parsing_start(argv[1], &data);
	// free_struct(&data);
	return (0);
}
