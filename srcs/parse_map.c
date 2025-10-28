/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:09:46 by ocviller          #+#    #+#             */
/*   Updated: 2025/10/28 16:49:43 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	rows(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (data->info.map[y])
		y++;
	while (data->info.map[y - 1][i])
	{
		if (data->info.map[y - 1][i] != '1' && !ft_isspace(data->info.map[y
				- 1][i]))
			return (0);
		i++;
	}
	i = 0;
	while (data->info.map[0][i])
	{
		if (data->info.map[0][i] != '1' && !ft_isspace(data->info.map[0][i]))
			return (0);
		i++;
	}
	return (1);
}

int	each_col(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (ft_isspace(str[i]))
		i++;
	while (ft_isspace(str[len - 1]))
		len--;
	if (!(str[i] == '1' && str[len - 1] == '1'))
		return (0);
	return (1);
}

int	columns(t_data *data)
{
	int	i;

	i = 0;
	while (data->info.map[i])
	{
		if (!each_col(data->info.map[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parse_map(t_data *data)
{
	if (!rows(data))
		return (ft_error("map is not fully closed"), 0);
	if (!columns(data))
		return (ft_error("map is not fully closed"), 0);
	return (1);
}
