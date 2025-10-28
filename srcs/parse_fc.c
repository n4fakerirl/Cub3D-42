/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:39:05 by ocviller          #+#    #+#             */
/*   Updated: 2025/10/28 17:01:13 by ocviller         ###   ########.fr       */
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
	return (ft_error("invalid texture"), 0);
}

int	split_size(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	if (i == 4)
		return (1);
	return (0);
}

int	grab_c(t_data *data, char *file)
{
	char	**tmp;
	int		i;

	tmp = split(file, ", ");
	if (!tmp)
		return (0);
	if (!split_size(tmp))
		return (free_tab(tmp), ft_error("Only 3 parameters needed"), 0);
	i = 0;
	while (i < 3)
	{
		data->txt->ceiling[i] = ft_atoi(tmp[i + 1]);
		if (data->txt->ceiling[i] < 0 || data->txt->ceiling[i] > 255)
			return (free_tab(tmp),
				ft_error("RGB must be set between 0 and 255"), 0);
		i++;
	}
	free_tab(tmp);
	return (1);
}

int	grab_f(t_data *data, char *file)
{
	char	**tmp;
	int		i;

	tmp = split(file, ", ");
	if (!tmp)
		return (0);
	if (!split_size(tmp))
		return (free_tab(tmp), ft_error("Only 3 parameters needed"), 0);
	i = 0;
	while (i < 3)
	{
		data->txt->floor[i] = ft_atoi(tmp[i + 1]);
		if (data->txt->floor[i] < 0 || data->txt->floor[i] > 255)
			return (free_tab(tmp),
				ft_error("RGB must be set between 0 and 255"), 0);
		i++;
	}
	free_tab(tmp);
	return (1);
}

int	get_fc(t_data *data)
{
	int		i;
	char	**file;

	if (!fc_check(data))
		return (0);
	i = 0;
	file = data->info.full_file;
	while (file[i])
	{
		if (!ft_strncmp(file[i], "F", 1))
		{
			if (!grab_f(data, file[i]))
				return (0);
		}
		else if (!ft_strncmp(file[i], "C", 1))
		{
			if (!grab_c(data, file[i]))
				return (0);
		}
		i++;
	}
	return (1);
}
