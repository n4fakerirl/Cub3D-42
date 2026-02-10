/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:25:18 by ocviller          #+#    #+#             */
/*   Updated: 2026/02/10 09:06:43 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	try_line(char *line, int flag)
{
	if ((line[0] != '\n' && line[0] != '\0' && line[0] != '\r') || (flag == 1))
		return (1);
	return (0);
}

char	*trimming(char *line)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*dest;

	start = 0;
	end = ft_strlen(line);
	i = 0;
	while (line[start] && ft_isspace(line[start]))
		start++;
	while (end > start && ft_isspace(line[end - 1]))
		end--;
	dest = malloc(sizeof(char) * (end - start + 1));
	if (!dest)
		return (NULL);
	while (start < end)
	{
		dest[i] = line[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*dup_cut(char *line)
{
	char	*dest;
	char	*tmp;

	(void)line;
	dest = trimming(line);
	if (!dest)
		return (NULL);
	tmp = dup_n(dest);
	if (!tmp)
		return (free(dest), NULL);
	free(dest);
	return (tmp);
}

int	check_space(t_data *data)
{
	int	y;
	int	i;

	y = 0;
	while (data->info.filled[y])
	{
		i = 0;
		while (data->info.filled[y][i])
		{
			if (data->info.filled[y][i] == '0')
			{
				if (!zero_one(data, y + 1, i))
					return (0);
				if (!zero_one(data, y - 1, i))
					return (0);
				if (!zero_one(data, y, i + 1))
					return (0);
				if (!zero_one(data, y, i - 1))
					return (0);
			}
			i++;
		}
		y++;
	}
	return (1);
}
