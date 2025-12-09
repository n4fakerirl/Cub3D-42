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