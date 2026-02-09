/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 01:32:57 by gule-bat          #+#    #+#             */
/*   Updated: 2025/10/30 01:32:57 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

long	clock_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	timer(t_data *data)
{
	long		curr;
	static long	last = 0;
	static long	fps = 0;

	curr = clock_ms();
	if (curr - last < 20)
		return (0);
	last = curr;
	fps += 1;
	if (fps >= 60)
		fps = 0;
	if (!engine(data))
		return (0);
	print_img_manual(data, data->txt->hud);
	mlx_put_image_to_window(data->mx.mlx, data->mx.win,
		data->mx.img_st->img, 0, 0);
	return (1);
}

int	init_mx(t_data *data)
{
	data->mx.mlx = mlx_init();
	if (!data->mx.mlx)
		return (1);
	data->mx.win = mlx_new_window(data->mx.mlx, X_AXIS, Y_AXIS, "cub3d");
	if (!data->mx.win)
		return (1);
	data->mx.img_st = malloc(sizeof(t_img));
	if (!data->mx.img_st)
		return (1);
	ft_memset(data->mx.img_st, 0, sizeof(t_img));
	data->mx.img_st->img = mlx_new_image(data->mx.mlx, X_AXIS, Y_AXIS);
	data->mx.img_st->addr = mlx_get_data_addr(data->mx.img_st->img,
			&data->mx.img_st->bpp,
			&data->mx.img_st->line_length,
			&data->mx.img_st->endian);
	data->player.p_x = data->info.p_posx * 4 + 0.5;
	data->player.p_y = data->info.p_posy * 4 - 0.5;
	get_fov(data);
	if (get_txt_full(&data))
		return (1);
	mlx_loop_hook(data->mx.mlx, timer, data);
	mlx_hook(data->mx.win, 2, 1L << 0, key_move, data);
	mlx_hook(data->mx.win, 3, 1L << 1, unkey_move, data);
	mlx_hook(data->mx.win, 17, 0, close_window, data);
	return (0);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color >> 0;
}
