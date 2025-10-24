/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:47:46 by ocviller          #+#    #+#             */
/*   Updated: 2025/10/24 17:09:15 by ocviller         ###   ########.fr       */
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
	free_tab(data->info.full_file);
	free_tab(data->info.txt_file);
	free_int_tab(data->info.fl_cl, 2);
	return ;
}
