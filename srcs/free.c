/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:47:46 by ocviller          #+#    #+#             */
/*   Updated: 2025/11/06 11:52:53 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_tab(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free_null(t_data *data, int i)
{
	while (--i >= 0)
		free(data->info.filled[i]);
	free(data->info.filled);
	ft_error("Memory allocation failed");
}

void	free_int_tab(int **tab, int size)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_struct(t_data *data)
{
	if (data->info.full_file)
		free_tab(data->info.full_file);
	if (data->info.map)
		free_tab(data->info.map);
	if (data->txt->ceiling)
		free(data->txt->ceiling);
	if (data->txt->floor)
		free(data->txt->floor);
	if (data->txt->no)
		free(data->txt->no);
	if (data->txt->so)
		free(data->txt->so);
	if (data->txt->we)
		free(data->txt->we);
	if (data->txt->ea)
		free(data->txt->ea);
	if (data->txt)
		free(data->txt);
	free(data);
	return ;
}
