/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_ext_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:04:32 by ocviller          #+#    #+#             */
/*   Updated: 2026/02/17 17:05:10 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	check_ext(char *file, int len)
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

void	wrong_ext(char *ext)
{
	ft_putstr_fd("cub3d: error: ", 2);
	ft_putstr_fd("wrong extension format, yours : ", 2);
	ft_putstr_fd(ext, 2);
	ft_putstr_fd(", expected : .xpm\n", 2);
}
