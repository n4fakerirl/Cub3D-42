/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:49:30 by ocviller          #+#    #+#             */
/*   Updated: 2025/11/06 11:53:31 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_error(char *message)
{
	ft_putstr_fd("cub3d: error: ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
}

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

char	*dup_n(char *str)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dest = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!dest)
		return (NULL);
	while (str[i])
	{
		if (str[i] != '\n')
		{
			dest[j] = str[i];
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
		if (str[i] != 'N' && str[i] != 'S' && str[i] != 'W' && str[i] != 'E'
			&& str[i] != '1' && str[i] != '0' && !ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}
