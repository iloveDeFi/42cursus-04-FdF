/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:25:22 by bat               #+#    #+#             */
/*   Updated: 2023/06/12 14:49:49 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "minilibx_macos/mlx.h"
# include "printf/ft_printf.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# define SHELL_RED "\033[0;31m"
# define SHELL_YELLOW "\033[0;33m"
# define SHELL_END_COLOR "\033[m"
# define TEXT_COLOR 0x1A1A1D
# define BACKGROUND 0x1A1A1D
# define MENU_BACKGROUND 0x950740
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define MLX_ERROR 1
# define ZOOM_FACTOR 1.1
# define TRANS_FACTOR_X 10
# define TRANS_FACTOR_Y 5
# define ALTITUDE 0.1

typedef struct s_ivector {
	int	x;
	int	y;
	int	z;
}	t_ipoint;

typedef struct s_fpoint {
	float	x;
	float	y;
}	t_fpoint;

typedef struct s_delta {
	float	dx;
	float	dy;
}	t_delta;

typedef struct s_env {
	void		*mlx;
	void		*win;
	void		*image;
	char		*address;
	char		*map_path;
	int			**final_tab;
	int			map_w;
	int			map_h;
	int			x;
	int			y;
	int			i;
	int			c_x;
	int			c_y;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			scale;
	int			translation;
	float		altitude;
	float		zoom;
	float		alpha;
	t_ipoint	*initial_points;
	t_fpoint	*final_points;
	t_delta		*delta;
}	t_env;

/*colors.c: color start, color end and curent percent on the slope*/
int		palette_one(double percent);
int		palette_two(double percent, int z);
int		palette_three(double percent);
int		palette_four(double percent);
int		palette_five(double percent);

/*start.c:*/
void	map_info(t_env *env, char *file);
void	parse_map(t_env *env, char *file);
int		env_init(t_env *env);
int		render(t_env *env);
void	check_format(t_env *env, char *file);

/*hooks.c*/
void	h_management(t_env *env);
int		key_handler(int key, t_env *env);
int		close_win(t_env *env);
int		mouse_handler(int mousecode, int x, int y, t_env *env);

/*fdf.c*/
int		error(char *error_message);
void	free_final_tab(t_env	*env);

/*points.c*/
void	three_dim_point(t_env *env);
void	two_dim_point(t_env *env);

/*draw.c*/
void	put_pixel(t_env *env, int x, int y, int color);
void	draw_line(t_env *env, t_fpoint point0, t_fpoint point1);
void	draw_background(t_env *env);

/*limits.c*/
void	limits(t_env *env);
void	no_limit(t_env *env);
void	right_limit(t_env *env);
void	low_limit(t_env *env);

#endif