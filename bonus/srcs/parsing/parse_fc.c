/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:55:02 by ocviller          #+#    #+#             */
/*   Updated: 2026/02/13 15:08:03 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	fc_check(t_data *data, int i, int f, int c)
{
	int	fl;
	int	cl;

	fl = 0;
	cl = 0;
	while (data->info.full_file[i])
	{
		if (!ft_strncmp(data->info.full_file[i], "F", 1))
		{
			f++;
			fl = i;
		}
		else if (!ft_strncmp(data->info.full_file[i], "C", 1))
		{
			c++;
			cl = i;
		}
		i++;
	}
	if (!enough_fc(c, f))
		return (0);
	if (fl > 5 || cl > 5)
		return (ft_error("useless line in file or map isn't last"), 0);
	return (1);
}

int	split_size(char **split, char c)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	if (i == 4)
		return (1);
	if (i < 4 && c == 'C')
		ft_error("not enough ceiling parameters, 3 needed");
	else if (i > 4 && c == 'C')
		ft_error("too many ceiling parameters, 3 needed");
	if (i < 4 && c == 'F')
		ft_error("not enough floor parameters, 3 needed");
	else if (i > 4 && c == 'F')
		ft_error("too many floor parameters, 3 needed");
	return (0);
}

int	grab_c(t_data *data, char *file)
{
	char	**tmp;
	int		i;

	tmp = make_tab(file);
	if (!tmp)
		return (0);
	if (!split_size(tmp, 'C'))
		return (free_tab(tmp), 0);
	i = 0;
	while (i < 3)
	{
		if (tmp[0][1] != '\0')
			return (free_tab(tmp), ft_error("only identifier C needed."), 0);
		data->txt->ceiling[i] = atoi_rgb(tmp[i + 1], 0, 1);
		if (data->txt->ceiling[i] < 0 || data->txt->ceiling[i] > 255)
			return (rgb_error(tmp, 0), 0);
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
	if (!split_size(tmp, 'F'))
		return (free_tab(tmp), 0);
	i = 0;
	while (i < 3)
	{
		if (tmp[0][1] != '\0')
			return (free_tab(tmp), ft_error("only identifier F needed."), 0);
		data->txt->floor[i] = atoi_rgb(tmp[i + 1], 0, 1);
		if (data->txt->floor[i] < 0 || data->txt->floor[i] > 255)
			return (rgb_error(tmp, 1), 0);
		i++;
	}
	free_tab(tmp);
	return (1);
}

int	get_fc(t_data *data)
{
	int		i;
	char	**file;

	if (!fc_check(data, 0, 0, 0))
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
