/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:34:40 by ocviller          #+#    #+#             */
/*   Updated: 2026/02/10 12:43:31 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	separator(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		else
			charset++;
	}
	return (0);
}

int	len_words(char *str, char *charset)
{
	int	word;

	word = 0;
	while (*str)
	{
		while (*str && separator(*str, charset))
			str++;
		if (*str)
			word++;
		while (*str && !separator(*str, charset))
			str++;
	}
	return (word);
}

char	*ft_strdup_sep(char *str, char *charset, int i)
{
	int		len;
	char	*word;

	len = 0;
	if (alphastr(str))
	{
		while (str[len] && ft_isalpha(str[len]))
			len++;
	}
	else
	{
		while (str[len] && !separator(str[len], charset))
			len++;
	}
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

char	**split(char *str, char *charset, int i, int y)
{
	char	**result;

	result = malloc(sizeof(char *) * (len_words(str, charset) + 1 + 1));
	if (!result)
		return (NULL);
	while (str[i])
	{
		while (str[i] && separator(str[i], charset))
			i++;
		if (str[i])
		{
			result[y] = ft_strdup_sep(str + i, charset, 0);
			if (!result[y])
				return (result[y] = NULL, ft_free(result), NULL);
			y++;
			if (y > 0 && alphastr(result[y - 1]))
			{
				i += ft_strlen(result[y - 1]);
				continue ;
			}
		}
		while (str[i] && !separator(str[i], charset))
			i++;
	}
	return (result[y] = NULL, result);
}
