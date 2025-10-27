/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:39:05 by ocviller          #+#    #+#             */
/*   Updated: 2025/10/27 19:55:38 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	fc_check(t_data *data)
{
	int	i;
	int	f;
	int	c;

	i = 0;
	f = 0;
	c = 0;
	while (data->info.full_file[i])
	{
		if (!ft_strncmp(data->info.full_file[i], "F", 1))
			f++;
		else if (!ft_strncmp(data->info.full_file[i], "C", 1))
			c++;
		i++;
	}
	if (c == 1 && f == 1)
		return (1);
	return (perror("invalid texture"), 0);
}

int	init_fc_cl(t_data *data)
{
	data->txt->floor = calloc(sizeof(int), 3);
	if (!data->txt->floor)
		return (1);
	data->txt->ceiling = calloc(sizeof(int), 3);
	if (!data->txt->ceiling)
		return (1);
	return (0);
}

int	grab_fc(t_data *data, char *file, char c)
{
	char	**tmp;
	int		i;

	tmp = split(file, ", ");
	if (!tmp)
		return (0);
	i = 0;
	if (c == 'F')
	{
		while (i < 3)
		{
			data->txt->floor[i] = ft_atoi(tmp[i + 1]);
			i++;
		}
	}
	else if (c == 'C')
	{
		while (i < 3)
		{
			data->txt->ceiling[i] = ft_atoi(tmp[i + 1]);
			i++;
		}
	}
	return (1);
}

int	get_fc(t_data *data)
{
	int		i;
	char	**file;

	if (init_fc_cl(data))
		return (0);
	if (!fc_check(data))
		return (0);
	i = 0;
	file = data->info.full_file;
	while (file[i])
	{
		if (!ft_strncmp(file[i], "F", 1))
		{
			if (!grab_fc(data, file[i], 'F'))
				return (0);
		}
		else if (!ft_strncmp(file[i], "C", 1))
		{
			if (!grab_fc(data, file[i], 'C'))
				return (0);
		}
		i++;
	}
	return (1);
}
