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
# define Y_AXIS 960

typedef struct s_mx
{
	void			*mlx;
	void			*win;
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
	char 	**full_file;
	int		p_pos;
}	t_cub;

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

// UTILS
char	**split(char *str, char *charset);
void 	ft_error(char *message);

// PRINT (A DELETE)
void 	print_data(t_data *data);

#endif
