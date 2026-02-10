/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:49:30 by ocviller          #+#    #+#             */
/*   Updated: 2026/02/10 09:02:12 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

size_t	len_tab(char *str)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			len += 4;
		else
			len++;
		i++;
	}
	return (len);
}

int	nbr_endl(const char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '\n' || s[i] == '\r')
			count++;
		i++;
	}
	return (count);
}

char	*dup_n(const char *s)
{
	int		i;
	int		j;
	int		srclen;
	char	*dest;

	i = 0;
	j = 0;
	srclen = ft_strlen(s);
	dest = malloc(sizeof(char) * ((srclen + 1) - nbr_endl(s)));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		if (s[i] != '\n' && s[i] != '\r')
		{
			dest[j] = s[i];
			j++;
		}
		i++;
	}
	dest[j] = '\0';
	return (dest);
}

int	useless_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalpha(str[i]) && str[i] != '1' && str[i] != '0'
			&& !ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	copy_tab(t_data *data)
{
	int	y;

	y = 0;
	free_tab(data->info.map);
	data->info.map = NULL;
	data->info.map = malloc(sizeof(char *) * (data->info.map_y + 1));
	if (!data->info.map)
		return (0);
	while (data->info.filled[y])
	{
		data->info.map[y] = ft_strdup(data->info.filled[y]);
		if (!data->info.map[y])
			return (0);
		y++;
	}
	data->info.map[y] = NULL;
	return (1);
}
