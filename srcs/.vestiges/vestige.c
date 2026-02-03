/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vestige1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:43:12 by gule-bat          #+#    #+#             */
/*   Updated: 2025/12/09 18:43:12 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// vestiges : 
// 
//fonctions de debug ou fonctions pouvant être utiles mais ne l'étant plus atm
// 
// void	print_map(t_data *data, t_vec vec)
// {
// 	t_vec	xy;
// 	int		x2;
// 	char	**map;
// 
// 	(void)vec;
// 	map = data->info.map;
// 	xy.y = 0;
// 	while (map[xy.y])
// 	{
// 		xy.x = 0;
// 		x2 = xy.x;
// 		while (map[xy.y][xy.x] != '\0')
// 		{
// 			if (xy.x == 0 && map[xy.y][xy.x] == '\t')
// 			{
// 				tab_to_pixel(data, &xy.x, &xy.y, 'x');
// 				x2 += 8;
// 			}
// 			else
// 			{
// 				scaled_pxl_minimap(data, x2, xy.y, map[xy.y][xy.x]);
// 				xy.x++;
// 				x2++;
// 			}
// 		}
// 		xy.y++;
// 	}
// 	mlx_put_image_to_window(data->mx.mlx, data->mx.win, data->mx.img_st->img,
// 		500, 500);
// }
// int	scaled_pxl_txt(t_data *data, int x, int y, int c)
// {
// 	int		i;
// 	int		j;
// 	int		factor;

// 	factor = FACTOR / 64.0;
// 	i = 0;
// 	j = 0;
// 	while (i < factor)
// 	{
// 		j = 0;
// 		while (j < factor)
// 		{
// 			my_mlx_pixel_put(data->mx.img_st, x * factor + j,
// 				y * factor + i, c);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (1);
// }
//
//
//	Vestige ray caster + raycast textures
//
// void	ray_cast_cam_txt(t_data *data) // PROTOTYPE
// {
// 	t_vec	fov;
// 	t_vec	mv;
// 	t_vec	fov_p;
// 	t_vec	dist;
// 	t_vec	i;

// 	dist.x = 0;
// 	fov_p.f_x = (data->player.fov - ((PI)) / 5);
// 	fov_p.f_y = (data->player.fov + ((PI)) / 5);
// 	i.f_x = PI / 3 / X_AXIS;
// 	while (dist.x < X_AXIS)
// 	{
// 		vector_sin_cos_plus(&fov, data, &mv, fov_p.f_x);
// 		line_calc_dda(data, &fov, &mv, NULL);
// 		dist.f_x = lenslesslenght(data, mv);
// 		dist.y = (FACTOR / dist.f_x) * (X_AXIS / 2);

// 		i.x = -dist.y / 2 + Y_AXIS / 2;
// 		if (i.x < 0)
// 			i.x = 0;
// 		i.y = dist.y / 2 + Y_AXIS / 2;
// 		if (i.y < 0)
// 			i.y = Y_AXIS - 1;
		
// 		if (fov.x)
// 			i.f_y = data->player.p_y + dist.f_x * fov.f_y;
// 		else
// 			i.f_y = data->player.p_x + dist.f_x * fov.f_x;
// 		i.f_y -=  floor(i.f_y);
// 		t_vec txt;
// 		txt.x = (int)(i.f_y * 64.0);	// txt x
// 		if (fov.x == 1 && mv.f_x > 0)
// 			txt.x = 64 - txt.x - 1;
// 		if (fov.x == 0 && mv.f_x < 0)
// 			txt.x = 64 - txt.x - 1;
// 		txt.f_y = 64 / dist.y;		// step
// 		txt.f_x = (i.x - Y_AXIS / 2 + dist.y / 2) * txt.f_y; //txt pos
// 		unsigned int z = 0;
// 		// printf("%d %d\n", data->txt->n->width, data->txt->s->height);
// 		for (int x = i.x; x < i.y; x++)
// 		{
// 			txt.y = (int)txt.f_x & (64 - 1);
// 			txt.f_x += txt.f_y;
// 			if ((txt.x < 0 || txt.y < 0) || (txt.x >= data->txt->s->width || txt.y >= data->txt->s->height))
// 				break;
// 			if (fov.x)
// 			{
// 				if (mv.x == 1)
// 					z = *(unsigned int *)(data->txt->n->addr + (txt.y * data->txt->n->line_length + txt.x * (data->txt->n->bpp / 8)));
// 				else
// 					z = *(unsigned int *)(data->txt->s->addr + (txt.y * data->txt->s->line_length + txt.x * (data->txt->s->bpp / 8)));
// 			}
// 			else
// 			{
// 				if (mv.x == 1)	
// 					z = *(unsigned int *)(data->txt->e->addr + (txt.y * data->txt->e->line_length + txt.x * (data->txt->e->bpp / 8)));
// 				else
// 					z = *(unsigned int *)(data->txt->w->addr + (txt.y * data->txt->w->line_length + txt.x * (data->txt->w->bpp / 8)));
// 			}
// 			scaled_pxl_txt(data, dist.x, x, mlx_get_color_value(data->mx.mlx, z));
// 			// line_print_y(data, dist.x, x, color_range(z, (dist.y) / 12));
// 			my_mlx_pixel_put(data->mx.img_st, dist.x, x, color_range(z, (dist.y) / 12));
// 		}
// 		// if (fov.x)
// 		// {
// 		// 	if (mv.x == 1)
// 		// 	{

// 		// 		// line_print_y(data, dist.x, dist.y, color_range(RED, (dist.f_x) / 12));
// 		// 	}
// 		// 	else
// 		// 	{

// 		// 		// line_print_y(data, dist.x, dist.y, color_range(YELLOW, (dist.f_x) / 12));
// 		// 	}
// 		// }
// 		// else
// 		// {
// 		// 	if (mv.x == 1)
// 		// 	{

// 		// 		// line_print_y(data, dist.x, dist.y, color_range(BLUE, (dist.f_x) / 12));
// 		// 	}
// 		// 	else
// 		// 	{

// 		// 		// line_print_y(data, dist.x, dist.y, color_range(PURPLE, (dist.f_x) / 12));
// 		// 	}
// 		// }
// 		// flash(data, dist);
// 		fov_p.f_x += i.f_x;
// 		dist.x++;
// 	}
// }

// void	ray_cast_cam(t_data *data) // WORKING WTHOUT TXT 
// {
// 	t_vec	fov;
// 	t_vec	mv;
// 	t_vec	fov_p;
// 	t_vec	dist;
// 	t_vec	i;

// 	dist.x = 0;
// 	fov_p.f_x = (data->player.fov - ((PI)) / 6);
// 	fov_p.f_y = (data->player.fov + ((PI)) / 6);
// 	i.f_x = PI / 3 / X_AXIS;
// 	while (dist.x < X_AXIS)
// 	{
// 		vector_sin_cos_plus(&fov, data, &mv, fov_p.f_x);
// 		line_calc(data, &fov, &mv, fov_p);
// 		dist.f_x = lenslesslenght(data, mv);
// 		dist.y = (FACTOR / dist.f_x) * (X_AXIS / 2);
// 		line_print_y(data, dist.x, dist.y, color_range(PURPLE, (dist.f_x) / 12));
// 		flash(data, dist);
// 		fov_p.f_x += i.f_x;
// 		dist.x++;
// 	}
// }

// void	ray_cast_cam(t_data *data)
// {
// 	t_vec dir;
// 	t_vec pln;

// 	dir.f_x = -1.0;
// 	dir.f_y = 0.0;
// 	pln.f_x = 0.0;
// 	pln.f_y = 0.66;


// }
