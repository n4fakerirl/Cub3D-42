/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 18:24:40 by ocviller          #+#    #+#             */
/*   Updated: 2026/02/17 15:37:22 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ext_check(t_data *data, int i)
{
	int	no;
	int	so;
	int	we;
	int	ea;

	no = 0;
	so = 0;
	we = 0;
	ea = 0;
	while (data->info.full_file[i])
	{
		if (!ft_strncmp(data->info.full_file[i], "NO", 2))
			no++;
		else if (!ft_strncmp(data->info.full_file[i], "SO", 2))
			so++;
		else if (!ft_strncmp(data->info.full_file[i], "WE", 2))
			we++;
		else if (!ft_strncmp(data->info.full_file[i], "EA", 2))
			ea++;
		i++;
	}
	if (!parse_ext(no, so, we, ea))
		return (0);
	return (1);
}

int	is_xpm(char *file)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (file[i])
	{
		if (file[i] == '.')
		{
			if (flag == 1)
				break ;
			else if (flag == 0)
				flag = 1;
		}
		i++;
	}
	return (i);
}

int	check_ext(char *file, int len, int flag)
{
	char	*ext;
	int		i;

	ext = NULL;
	if (len == 2 && !ft_strncmp(file, "./", 2))
		return (ft_error("path to the texture not found"), 0);
	i = is_xpm(file);
	ext = ft_strdup(file + i);
	if (!ext)
		return (ft_error("malloc error"), 0);
	if (!ft_strcmp(ext, ""))
		return (ft_error("path to the texture doesn't have any extension"),
			free(ext), 0);
	if (ft_strncmp(ext, ".xpm", 4))
		return (wrong_ext(ext), free(ext), 0);
	free(ext);
	return (1);
}

int	store_ext(t_data *data, char c, int i, char *file)
{
	if (c == 'N')
	{
		data->txt->no = ft_strdup(file + i);
		if (!data->txt->no)
			return (0);
	}
	else if (c == 'S')
	{
		data->txt->so = ft_strdup(file + i);
		if (!data->txt->so)
			return (0);
	}
	else if (c == 'W')
	{
		data->txt->we = ft_strdup(file + i);
		if (!data->txt->we)
			return (0);
	}
	else if (c == 'E')
	{
		data->txt->ea = ft_strdup(file + i);
		if (!data->txt->ea)
			return (0);
	}
	return (1);
}

int	grab_ext(t_data *data, char *file, char c, int l)
{
	int	i;
	int	len;

	len = ft_strlen(file);
	i = 0;
	while (file[i] && ft_isspace(file[i]))
		i++;
	i = good_format(i, file);
	if (i == -1)
		return (0);
	if (!check_ext(file, len))
		return (0);
	if (l > 5)
		return (ft_error("useless line in file or map isn't last"), 0);
	if (!store_ext(data, c, i, file))
		return (ft_error("malloc error"), 0);
	return (1);
}

int	txt_init(t_data *data, int i)
{
	char	**file;

	if (!ext_check(data, 0))
		return (1);
	file = data->info.full_file;
	while (file[i])
	{
		if (!ft_strncmp(file[i], "NO", 2) && !grab_ext(data, file[i] + 3, 'N',
				i))
			return (1);
		else if (!ft_strncmp(file[i], "SO", 2) && !grab_ext(data, file[i] + 3,
				'S', i))
			return (1);
		else if (!ft_strncmp(file[i], "WE", 2) && !grab_ext(data, file[i] + 3,
				'W', i))
			return (1);
		else if (!ft_strncmp(file[i], "EA", 2) && !grab_ext(data, file[i] + 3,
				'E', i))
			return (1);
		i++;
	}
	return (0);
}
