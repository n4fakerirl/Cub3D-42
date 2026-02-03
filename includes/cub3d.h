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
# include <stdbool.h>
# include <unistd.h>
# include <sys/time.h>

# define X_AXIS		1280
# define Y_AXIS		720

# define PI			3.141592653

# define BLACK		0x000000
# define WHITE		0xFFFFFF
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define YELLOW		0xFFFF00
# define CYAN		0x00FFFF
# define MAGENTA	0xFF00FF
# define GRAY		0x808080
# define ORANGE		0xFFA500
# define PURPLE		0x800080
# define BROWN		0xA52A2A

# define FACTOR		10
# define TAB		4
# define SPEED		0.5  // DANGER POTENTIEL 

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
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
	t_img	*n;
	char	*so;
	t_img	*s;
	char	*we;
	t_img	*w;
	char	*ea;
	t_img	*e;
	int		*floor;
	int		*ceiling;
	t_img	*hud;
}	t_txt;

typedef struct s_player
{
	float	p_x;
	float	p_y;
	float	fov;
	bool	l;
	bool	r;
	bool	z;
	bool	q;
	bool	s;
	bool	d;
}	t_player;

typedef struct s_cub
{
	char	*file;
	char	**map;
	char	**full_file;
	char	**filled;
	int		map_y;
	int		map_x;
	int		p_posx;
	int		p_posy;
}	t_cub;

typedef struct s_data
{
	t_cub		info;
	t_mx		mx;
	t_player	player;
	t_txt		*txt;
}	t_data;

typedef struct s_vec
{
	int		x;
	int		y;
	float	f_x;
	float	f_y;
}	t_vec;

// FREE
void	free_tab(char **str);
void	free_int_tab(int **tab, int size);
int		get_size_file(int fd);
void	free_struct(t_data *data);
void	ft_free_null(t_data *data, int i);
int		copy_tab(t_data *data);
void	free_txt(t_data *data);

// PARSING
int		txt_init(t_data *data, int i);
int		read_infile(int fd, t_data *data);
int		get_fc(t_data *data);
int		parse_map(t_data *data);
void	add_spaces(t_data *data, int y);
int		find_size(t_data *data);
int		create_map(t_data *data);
void	flood_fill(t_data *data, int x, int y);
void	find_player(t_data *data);

// UTILS
char	**split(char *str, char *charset);
void	ft_error(char *message);
char	*dup_n(char *str);
int		useless_line(char *str);
size_t	len_tab(char *str);

//  - RENDER
int		engine(t_data *data);
int		sup_max_color(int color);
int		color_range(int color, float f);
int		scaled_pxl(t_data *data, int x, int y, int c);
void	ray_cast_cam(t_data *data);
void	ray_cast_cam_txt(t_data *data);
void	print_img_manual(t_data *data, t_img *img);
void	clear_pic(t_data *data);
void	calc_textures(t_data *data, t_vec dist, t_vec fov, t_vec mv);
//	-	/dda
void	rc_dda_dir_selector(t_data *data, t_vec *sd, t_vec dlt, t_vec *dir);
void	dda_loop_content(t_vec *sd, t_vec dlt, t_vec *dir, t_vec *mv);
void	line_calc_dda(t_data *data, t_vec *dir, t_vec *mv, float *txt);

// render utils
int		scaled_pxl_line(t_data *data, int x, int y, int c);
void	line_print_y(t_data *data, int xpos, float wall, int color);
void	line_calc(t_data *data, t_vec *fov, t_vec *mv, t_vec fov_p);
float	fish_eye_eater(t_data *data, t_vec mv, t_vec fov, t_vec fov_p);

// MLX
int		close_window(t_data *data);
int		init_mx(t_data *data);
int		key_move(int key, t_data *data);
int		unkey_move(int key, t_data *data);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		get_txt_full(t_data **data);

// minimap 
int		scaled_pxl_minimap(t_data *data, int x, int y, char c);
void	print_game_map(t_data *data, t_vec vec);
void	pxl_type(t_data *data, int x, int y, int c);
void	tab_to_pixel(t_data *data, int *x, int *y, int c);
void	ray_cast(t_data *data, t_vec vec, t_vec player_i); //minimap
/*void	print_map(t_data *data, t_vec vec);	//useless atm*/

// JOUEUR
void	player_coord_fov(t_data *data, float v_fov);
void	coord_calculator(t_data *data, float csv, float snv);
void	player_coord(t_data *data);
bool	contact(t_data *data, float f_x, float f_y, int c);
void	get_fov(t_data *data);

// MATHS
t_vec	vec_offset(int x, int y);
		// offset selon fenetre divise selon la taille des pxl
void	vector_sin_cos_plus(t_vec *vec, t_data *data, t_vec *plr_i, float fov);
float	lenght(float x, float y);
int		get_color(int r, int g, int b);

// PRINT (A DELETE)
void	print_data(t_data *data);

#endif
