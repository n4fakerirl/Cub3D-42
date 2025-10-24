/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 18:24:40 by ocviller          #+#    #+#             */
/*   Updated: 2025/10/24 18:25:25 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	search_extension(char *str, const char *ext)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strncmp(&str[i], ext, ft_strlen(ext)))
			return (1);
		i++;
	}
	return (0);
}

int	extline(char *file, t_data *data, int i)
{
	char	*tmp;

	tmp = ft_strdup(file + 5);
	if (!tmp)
		return (-1);
	data->info.txt_file[i] = tmp;
	return (1);
}

int	txt_init(t_data *data)
{
	int		i;
	int		count;
	char	**file;

	i = 0;
	count = 0;
	file = data->info.full_file;
	data->info.txt_file = ft_calloc(sizeof(char *), 5);
	if (!data->info.txt_file)
		return (1);
	while (file[i])
	{
		if (file[i][4] == '/' && search_extension(file[i], ".xpm") == 1)
		{
			if (count >= 4)
				return (perror("invalid texture"), 1);
			if (extline(file[i], data, i) == -1)
				return (perror("malloc error"), 1);
			count++;
		}
		i++;
	}
	if (count != 4)
		return (perror("invalid texture"), 1);
	return (0);
}
