/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:19:14 by gule-bat          #+#    #+#             */
/*   Updated: 2026/02/10 08:54:59 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_txt(t_data **data, char *path, t_img **img)
{
	char	*tmpath;
	char	*tmp;

	tmpath = NULL;
	if (!path)
		return (1);
	tmp = ft_strdup(path);
	if (!tmp)
		return (1);
	tmpath = ft_strjoin("txt/", tmp);
	if (!tmpath)
		return (free(tmp), 1);
	free(tmp);
	(*img)->img = mlx_xpm_file_to_image((*data)->mx.mlx, tmpath, &(*img)->width,
			&(*img)->height);
	if (!(*img)->img)
		return (free(tmpath), 1);
	free(tmpath);
	(*img)->addr = mlx_get_data_addr((*img)->img, &(*img)->bpp,
			&(*img)->line_length, &(*img)->endian);
	if (!(*img)->addr)
		return (1);
	return (0);
}

int	init_txt(t_data **data)
{
	(*data)->txt->n = ft_calloc(1, sizeof(t_img));
	if (!(*data)->txt->n)
		return (1);
	(*data)->txt->s = ft_calloc(1, sizeof(t_img));
	if (!(*data)->txt->s)
		return (1);
	(*data)->txt->e = ft_calloc(1, sizeof(t_img));
	if (!(*data)->txt->e)
		return (1);
	(*data)->txt->w = ft_calloc(1, sizeof(t_img));
	if (!(*data)->txt->w)
		return (1);
	(*data)->txt->hud = ft_calloc(1, sizeof(t_img));
	return (0);
}

int	get_txt_full(t_data **data)
{
	if (!((*data)->txt->no && (*data)->txt->so && (*data)->txt->ea
			&& (*data)->txt->we))
		return (1);
	if (init_txt(data))
		return (1);
	if (get_txt(data, (*data)->txt->no, &(*data)->txt->n) && (*data)->txt->no)
		return (1);
	if (get_txt(data, (*data)->txt->so, &(*data)->txt->s) && (*data)->txt->so)
		return (1);
	if (get_txt(data, (*data)->txt->ea, &(*data)->txt->e) && (*data)->txt->ea)
		return (1);
	if (get_txt(data, (*data)->txt->we, &(*data)->txt->w) && (*data)->txt->we)
		return (1);
	if (get_txt(data, "hudcub.xpm", &(*data)->txt->hud))
		return (1);
	if ((*data)->txt->hud->width != 1280 && (*data)->txt->hud->height != 720)
		return (1);
	return (0);
}
