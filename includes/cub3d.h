/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 18:29:50 by ocviller          #+#    #+#             */
/*   Updated: 2025/10/24 18:29:50 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "libft/get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

# define X_AXIS 1280
# define Y_AXIS 720

# define BLACK       0x000000
# define WHITE       0xFFFFFF
# define RED         0xFF0000
# define GREEN       0x00FF00
# define BLUE        0x0000FF
# define YELLOW      0xFFFF00
# define CYAN        0x00FFFF
# define MAGENTA     0xFF00FF
# define GRAY        0x808080
# define ORANGE      0xFFA500
# define PURPLE      0x800080
# define BROWN       0xA52A2A

# define FACTOR		10	

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mx
{
	void			*mlx;
	void			*win;
	t_img			*img_st;
	struct s_data	*data;
}	t_mx;

typedef struct s_txt
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		*floor;
	int		*ceiling;
}	t_txt;

typedef struct s_cub
{
	char	*file;
	char	**map;
	char	**full_file;
	int		p_pos;
}	t_cub;

typedef struct s_vec
{
	int	x;
	int	y;
}	t_vec;

typedef struct s_data
{
	t_cub	info;
	t_mx	mx;
	t_txt	*txt;
}	t_data;

// FREE
void	free_tab(char **str);
void	free_int_tab(int **tab, int size);
int		get_size_file(int fd);
void	free_struct(t_data *data);

// PARSING
int		txt_init(t_data *data, int i);
int		read_infile(int fd, t_data *data);
int		get_fc(t_data *data);
int		parse_map(t_data *data);

// UTILS
char	**split(char *str, char *charset);
void	ft_error(char *message);

// MINIMAP 
void	pxl_type(t_data *data, int x, int y, int c);
int		scaled_pxl(t_data *data, int x, int y, char c);
void	tab_to_pixel(t_data *data, int *x, int *y, int c);
void	print_map(t_data *data, t_vec vec);
void	engine(t_data *data);

// MATHS
t_vec	vec_offset(int x, int y);
		// offset selon fenetre divise selon la taille des pxl

// MLX
int		close_window(t_data *data);
void	init_mx(t_data *data);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

// PRINT (A DELETE)
void	print_data(t_data *data);

#endif
