/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:04:33 by ocviller          #+#    #+#             */
/*   Updated: 2026/02/10 12:44:46 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	good_format(int i, char *file)
{
	int	count_dot;
	int	count_slash;

	count_dot = 0;
	count_slash = 0;
	while (file[i] && (file[i] == '.' || file[i] == '/'))
	{
		if (file[i] == '.')
			count_dot++;
		else if (file[i] == '/')
			count_slash++;
		i++;
	}
	if (count_dot != 1 || count_slash != 1)
		return (ft_error("usage: ./txt.xpm"), -1);
	return (i);
}

char	*ft_union(char *str)
{
	int		len;
	char	*dest;
	int		i;
	int		y;

	len = ft_strlen(str) - count_sp(str);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	y = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			dest[y] = str[i];
			y++;
		}
		i++;
	}
	dest[y] = '\0';
	return (dest);
}

char	**make_tab(char *file)
{
	char	*line;
	char	**tmp;

	line = ft_union(file);
	if (!line)
		return (ft_error("malloc error"), NULL);
	tmp = split(line, ",", 0, 0);
	if (!tmp)
		return (free(line), ft_error("malloc error"), NULL);
	free(line);
	return (tmp);
}

int	atoi_rgb(const char *nptr, int i, int sign)
{
	int	result;

	result = 0;
	while (nptr[i])
	{
		if (!ft_isalnum(nptr[i]) && !ft_isspace(nptr[i]) && nptr[i] != '-'
			&& nptr[i] != '+')
			return (-1);
		i++;
	}
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	return (result * sign);
}

void	rgb_error(char **tmp)
{
	free_tab(tmp);
	ft_error("RGB must be set between 0 and 255, digits only");
}
