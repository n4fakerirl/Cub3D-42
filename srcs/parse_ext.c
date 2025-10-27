/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 18:24:40 by ocviller          #+#    #+#             */
/*   Updated: 2025/10/27 19:36:22 by ocviller         ###   ########.fr       */
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
	if (no == 1 && so == 1 && we == 1 && ea == 1)
		return (1);
	return (perror("invalid texture"), 0);
}

void	grab_ext(t_data *data, char *file, char c)
{
	int	i;

	i = 0;
	while (ft_isspace(file[i]))
		i++;
	if (c == 'N')
		data->txt->no = ft_strdup(file + i + 2);
	else if (c == 'S')
		data->txt->so = ft_strdup(file + i + 2);
	else if (c == 'W')
		data->txt->we = ft_strdup(file + i + 2);
	else if (c == 'E')
		data->txt->ea = ft_strdup(file + i + 2);
}

int	txt_init(t_data *data)
{
	int		i;
	char	**file;

	if (!ext_check(data, 0))
		return (1);
	data->txt = malloc(sizeof(t_txt));
	if (!data->txt)
		return (1);
	i = 0;
	file = data->info.full_file;
	while (file[i])
	{
		if (!ft_strncmp(file[i], "NO", 2))
			grab_ext(data, file[i] + 2, 'N');
		else if (!ft_strncmp(file[i], "SO", 2))
			grab_ext(data, file[i] + 2, 'S');
		else if (!ft_strncmp(file[i], "WE", 2))
			grab_ext(data, file[i] + 2, 'W');
		else if (!ft_strncmp(file[i], "EA", 2))
			grab_ext(data, file[i] + 2, 'E');
		i++;
	}
	return (0);
}
