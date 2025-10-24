/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:10:21 by gule-bat          #+#    #+#             */
/*   Updated: 2025/10/17 15:10:21 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "libft/get_next_line/get_next_line.h"
# include "../mlx_linux/mlx.h"

# define X_AXIS 1280
# define Y_AXIS 960

typedef struct s_mx
{
	void			*mlx;
	void			*win;
	struct s_data	*data;
}					t_mx;

typedef struct s_cub
{
    char    *file; // file name                         // argv[1]  no free
    char    **full_file; // file                        // gnl      free
    // int     sizey; 
    char    **map;  // full map 1111 000 etc...         // ptr vers la map ds full_file donc pas de free
    char    **txt_file; // texture buffer,              // strdup   free
    // int     fl_cl[2][3]; // floor groud color ( F C ???, )    // stack no free
    int     **fl_cl; // floor ceiling color ( F C ???, )    // stack no free
    int     p_pos;
}               t_cub;

typedef struct s_data
{
    t_cub   info;
    t_mx    mx;
    void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
    long int        x;
    long int        y;
}           t_data;

#endif