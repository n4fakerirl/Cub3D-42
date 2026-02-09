/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nova <nova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:47:46 by ocviller          #+#    #+#             */
/*   Updated: 2026/02/09 19:48:59 by nova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_tab(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	close_window(t_data *data)
{
	if (data->mx.mlx && data->mx.img_st && data->mx.img_st->img)
		mlx_destroy_image(data->mx.mlx, data->mx.img_st->img);
	free_txt(data);
	if (data->mx.mlx && data->mx.win)
		mlx_destroy_window(data->mx.mlx, data->mx.win);
	if (data->mx.mlx)
	{
		mlx_destroy_display(data->mx.mlx);
		free(data->mx.mlx);
	}
	if (data->mx.img_st)
		free(data->mx.img_st);
	free_struct(data);
	exit(0);
	return (0);
}

void	free_txt(t_data *data)
{
	if (data->mx.mlx && data->txt->n && data->txt->n->img)
		mlx_destroy_image(data->mx.mlx, data->txt->n->img);
	if (data->mx.mlx && data->txt->s && data->txt->s->img)
		mlx_destroy_image(data->mx.mlx, data->txt->s->img);
	if (data->mx.mlx && data->txt->e && data->txt->e->img)
		mlx_destroy_image(data->mx.mlx, data->txt->e->img);
	if (data->mx.mlx && data->txt->w && data->txt->w->img)
		mlx_destroy_image(data->mx.mlx, data->txt->w->img);
	if (data->mx.mlx && data->txt->hud && data->txt->hud->img)
		mlx_destroy_image(data->mx.mlx, data->txt->hud->img);
	if (data->txt->hud)
		free(data->txt->hud);
}

void	free_struct(t_data *data)
{
	if (!data)
		return ;
	if (data->info.full_file)
		free_tab(data->info.full_file);
	if (data->info.filled)
		free_tab(data->info.filled);
	if (data->info.map)
		free_tab(data->info.map);
	if (data->txt->ceiling)
		free(data->txt->ceiling);
	if (data->txt->floor)
		free(data->txt->floor);
	if (data->txt->n)
		free(data->txt->n);
	if (data->txt->n)
		free(data->txt->s);
	if (data->txt->n)
		free(data->txt->w);
	if (data->txt->n)
		free(data->txt->e);
	if (data->txt->no)
		free(data->txt->no);
	if (data->txt->so)
		free(data->txt->so);
	if (data->txt->we)
		free(data->txt->we);
	if (data->txt->ea)
		free(data->txt->ea);
	if (data->txt)
		free(data->txt);
	free(data);
}
