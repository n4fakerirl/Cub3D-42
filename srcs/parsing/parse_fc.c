/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:55:02 by ocviller          #+#    #+#             */
/*   Updated: 2026/02/10 12:07:36 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	fc_check(t_data *data, int i)
{
	int	f;
	int	c;

	f = 0;
	c = 0;
	while (data->info.full_file[i])
	{
		if (!ft_strncmp(data->info.full_file[i], "F", 1))
		{
			if (i > 5)
				return (ft_error("useless line in file or map isn't last"), 0);
			f++;
		}
		else if (!ft_strncmp(data->info.full_file[i], "C", 1))
		{
			if (i > 5)
				return (ft_error("useless line in file or map isn't last"), 0);
			c++;
		}
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

	tmp = make_tab(file);
	if (!tmp)
		return (0);
	if (!split_size(tmp))
		return (free_tab(tmp), ft_error("only 3 parameters needed"), 0);
	i = 0;
	while (i < 3)
	{
		if (tmp[0][1] != '\0')
			return (free_tab(tmp), ft_error("only identifier C needed."), 0);
		data->txt->ceiling[i] = atoi_rgb(tmp[i + 1], 0, 0);
		if (data->txt->ceiling[i] < 0 || data->txt->ceiling[i] > 255)
			return (rgb_error(tmp), 0);
		i++;
	}
	free_tab(tmp);
	return (1);
}

int	grab_f(t_data *data, char *file)
{
	char	**tmp;
	int		i;

	tmp = make_tab(file);
	if (!tmp)
		return (0);
	if (!split_size(tmp))
		return (free_tab(tmp), ft_error("only 3 parameters needed"), 0);
	i = 0;
	while (i < 3)
	{
		if (tmp[0][1] != '\0')
			return (free_tab(tmp), ft_error("only identifier F needed."), 0);
		data->txt->floor[i] = atoi_rgb(tmp[i + 1], 0, 0);
		if (data->txt->floor[i] < 0 || data->txt->floor[i] > 255)
			return (rgb_error(tmp), 0);
		i++;
	}
	free_tab(tmp);
	return (1);
}

int	get_fc(t_data *data)
{
	int		i;
	char	**file;

	if (!fc_check(data, 0))
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
