/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:13:52 by ocviller          #+#    #+#             */
/*   Updated: 2026/02/13 15:24:32 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	zero_one(t_data *data, int y, int i)
{
	if (data->info.filled[y][i] != '1' && data->info.filled[y][i] != '0'
		&& data->info.filled[y][i] != 'X')
		return (0);
	return (1);
}

int	nl_inmap(t_data *data)
{
	int	i;

	i = 0;
	while (data->info.map[i])
	{
		if (!ft_strcmp(data->info.map[i], "\0"))
			return (0);
		i++;
	}
	return (1);
}

int	count_sp(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			count++;
		i++;
	}
	return (count);
}
