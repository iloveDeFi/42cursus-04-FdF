/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:25:22 by bat               #+#    #+#             */
/*   Updated: 2023/09/08 10:47:52 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>
# include <fcntl.h>
 
// Macro
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define PIXEL_DEEPPINK4 0x8b0a50
# define PIXEL_ALICEBLUE 0xf0f8ff
# define PIXEL_LAVENDERBLUSH 0xfff0f5
# define PIXEL_BLUEVIOLET 0x8a2be2
# define PIXEL_KHAKI4 0x8b864e
# define PIXEL_BURLYWOOD4 0x8b7355
# define PIXEL_ROSYBROWN4 0x8b6969
# define PIXEL_DARKORCHID 0xbf3eff
# define PIXEL_DARKGREY 0xa9a9a9
# define PIXEL_DEEPPINK1 0xff1493
# define PIXEL_FORESTGREEN 0x228b22
# define MOVE 25
# define ALTITUDE 0.1
# define ROTATE 0.1
# define ZOOM 1

// Structures
typedef struct s_key
{
	int		horizontal;
	int		vertical;
	int		background;
	float	altitude;
}	t_key;

typedef struct s_point
{
	float	fy;
	float	fx;
}	t_point;

typedef struct s_map
{
	char	*file;
	int		width;
	int		height;
	int		**parse;
}	t_map;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data {
	float	alpha;
	int		size;
	char	**tab;
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
	t_img	img;
	t_point	*t_point;
	t_key	key;
}	t_data;

/* Main */
void	ft_initial_values(t_data *data);

// Display error & free
void	ft_display_error(char *str);
void	ft_free_tab_from_split(char *tab[]);
void	ft_free_parsing(t_data *data, int y);
void	ft_free_map_parse(t_data *data);
void	ft_free_mlx(t_data *data, int flag);

// Size & parsing
void	ft_define_size(t_data *data);
void	ft_parsing(t_data *data);
void	ft_parsing_bis(t_data *data, char *line, int y);

// Convert
void	ft_convert(t_data *data);
void	ft_convert_fx(t_data *data, int x, int y, int i);
void	ft_convert_fy(t_data *data, int x, int y, int i);

// Graphic
void	ft_initialization(t_data *data);
int	ft_render(t_data *data);

// Draw
void	ft_put_pixel(t_data *data, int x, int y, int color);
void	ft_draw_background(t_data *data);
void	ft_define_points_to_connect(t_data *data);
void	ft_trace_line(t_data *data, int start, int end, int color);

// Hook
void	ft_instructions(t_data *data);
int	ft_keyboard(int keycode, t_data *data);
int	ft_shutdown(t_data *data);
int	ft_mouse(int button, int x, int y, t_data *data);

// Colors
int		ft_colors_lines(t_data *data, int x, int y);
int		ft_color_background(t_data *data);

#endif