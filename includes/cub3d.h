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

# ifndef CUB3D_H
# define CUB3D_H

# include "../mlx_linux/mlx.h"
# include "libft/get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

# define X_AXIS 1280
# define Y_AXIS 960

typedef struct s_mx
{
	void *mlx;
	void *win;
	struct s_data *data;
} t_mx;

typedef struct s_cub
{
	char *file;
	char **full_file;
	char **map;
	char **txt_file;
	int **fl_cl;
	int p_pos;
} t_cub;

typedef struct s_data
{
	t_cub info;
	t_mx mx;
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
	long int x;
	long int y;
} t_data;

// FREE
void	free_tab(char **str);
void	free_int_tab(int **tab, int size);
int	get_size_file(int fd);
void	free_struct(t_data *data);

// PARSING
int	txt_init(t_data *data);
int	read_infile(int fd, t_data *data);

#endif
