/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nova <nova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:56:20 by ocviller          #+#    #+#             */
/*   Updated: 2026/02/09 18:05:45 by nova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_error(char *message)
{
	ft_putstr_fd("cub3d: error: ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
}

void	m_error(char *line, t_data *data, int j, int fd2)
{
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd2);
	}
	free(line);
	close(fd2);
	data->info.full_file[j] = NULL;
	ft_error("malloc error");
}

void	print_int(t_data *data)
{
	int	i;

	i = 0;
	printf("=== FLOOR && CEILING ===\nF = ");
	while (i < 3)
	{
		if (i != 2)
			printf("%d,", data->txt->floor[i]);
		else
			printf("%d", data->txt->floor[i]);
		i++;
	}
	printf("\n");
	printf("C = ");
	i = 0;
	while (i < 3)
	{
		if (i != 2)
			printf("%d,", data->txt->ceiling[i]);
		else
			printf("%d", data->txt->ceiling[i]);
		i++;
	}
	printf("\n");
}

void	print_maps(t_data *data)
{
	int	i;

	i = 0;
	printf("=== GAME MAP ===\n");
	while (data->info.map[i])
	{
		printf("'%s'\n", data->info.map[i]);
		i++;
	}
	i = 0;
	printf("=== NEW MAP ===\n");
	while (data->info.filled[i])
	{
		printf("'%s'\n", data->info.filled[i]);
		i++;
	}
}

void	print_data(t_data *data)
{
	int	i;

	i = 0;
	printf("=== WHOLE FILE ===\n");
	while (data->info.full_file[i])
	{
		printf("%s\n", data->info.full_file[i]);
		i++;
	}
	printf("\n=== ORIENTATION ===\n");
	printf("NORTH == %s\nSOUTH == %s\nWEST == %s\nEAST == %s\n", data->txt->no,
		data->txt->so, data->txt->we, data->txt->ea);
	print_int(data);
	print_maps(data);
}
