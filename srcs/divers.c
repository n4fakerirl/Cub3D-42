/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:56:20 by ocviller          #+#    #+#             */
/*   Updated: 2025/10/28 11:54:19 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

void	print_data(t_data *data)
{
	int	i;

	i = 0;
	printf("=== WHOLE FILE ===\n");
	while (data->info.full_file[i])
	{
		printf("%s", data->info.full_file[i]);
		i++;
	}
	printf("\n=== ORIENTATION ===\n");
	printf("NORTH == %s\nSOUTH == %s\nWEST == %s\nEAST == %s\n", data->txt->no,
		data->txt->so, data->txt->we, data->txt->ea);
	print_int(data);
}
