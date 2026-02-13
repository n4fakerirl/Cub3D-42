/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:42:37 by ocviller          #+#    #+#             */
/*   Updated: 2026/02/13 13:10:50 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	blank_line(int mpfull, char *line, t_data *data)
{
	if (mpfull == 0)
	{
		if (space_str(line))
			data->info.nl_full = 1;
	}
	else if (mpfull == 1)
	{
		if (space_str(line))
			data->info.nl_map = 1;
	}
}

void	last_line(t_data *data, char *line, int j, int mpfull)
{
	int		i;
	int		flag;
	char	*search;

	search = NULL;
	i = 0;
	flag = 1;
	search = ft_strchr(line, '1');
	blank_line(mpfull, line, data);
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '\n' && line[i] != ' '
			&& line[i] != '\t')
			flag = 0;
		else if (!search)
			flag = 0;
		i++;
	}
	if (data->info.flag == 1 && flag == 1)
	{
		if (mpfull == 0 && data->info.nl_full == 0)
			data->info.lstline_pos = j;
		else if (mpfull == 1 && data->info.nl_map == 0)
			data->info.lstline_pos = j;
	}
}

int	in_between(t_data *data, int line)
{
	int	flag;

	flag = 0;
	if (line > data->info.lstline_pos)
	{
		while (data->info.full_file[line])
		{
			if (!space_str(data->info.full_file[line]))
				flag = 1;
			line++;
		}
	}
	if (flag == 1)
		return (0);
	return (1);
}
