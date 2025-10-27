/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:34:40 by ocviller          #+#    #+#             */
/*   Updated: 2025/10/27 19:47:15 by ocviller         ###   ########.fr       */
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

char	*ft_strdup_sep(char *str, char *charset)
{
	int		len;
	int		i;
	char	*word;

	len = 0;
	i = 0;
	while (str[len] && !separator(str[len], charset))
		len++;
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

char	**split(char *str, char *charset)
{
	int		words;
	int		i;
	char	**result;

	words = len_words(str, charset);
	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && separator(*str, charset))
			str++;
		if (*str)
		{
			result[i] = ft_strdup_sep(str, charset);
			if (!result[i])
				return (NULL);
			i++;
		}
		while (*str && !separator(*str, charset))
			str++;
	}
	result[i] = NULL;
	return (result);
}
