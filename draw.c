/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:25:15 by bat               #+#    #+#             */
/*   Updated: 2023/09/08 11:25:42 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(t_data *data, int x, int y, int color)
{
	char	*pxl;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		pxl = data->img.addr + (y * data->img.line_len + x * \
								(data->img.bpp / 8));
		*(unsigned int *)pxl = color;
	}
}

void	ft_draw_background(t_data *data)
{
	int	width;
	int	height;
	int	color;

	height = -1;
	color = ft_color_background(data);
	while (++height < WIN_HEIGHT)
	{
		width = -1;
		while (++width < WIN_WIDTH)
			ft_put_pixel(data, width, height, color);
	}
}

void	ft_trace_line(t_data *data, int start, int end, int color)
{
	float	delta_x;
	float	delta_y;
	float	pixels_x;
	float	pixels_y;
	int		pixels;

	delta_x = data->t_point[end].fx - data->t_point[start].fx;
	delta_y = data->t_point[end].fy - data->t_point[start].fy;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixels_x = data->t_point[start].fx;
	pixels_y = data->t_point[start].fy;
	while (pixels)
	{
		ft_put_pixel(data, -pixels_x + WIN_WIDTH / 3 + data->key.horizontal, \
					-pixels_y + WIN_HEIGHT / 3 + data->key.vertical, color);
		pixels_x += delta_x;
		pixels_y += delta_y;
		pixels--;
	}
}

void	ft_define_points_to_connect(t_data *data)
{
	int	h;
	int	w;

	h = -1;
	while (++h < data->map.height)
	{
		w = -1;
		while (++w < data->map.width)
		{
			if (h < data->map.height - 1)
				ft_trace_line(data, h * data->map.width + w,
					(h + 1) * data->map.width + w, ft_colors_lines(data, w, h));
			if (w < data->map.width - 1)
				ft_trace_line(data, h * data->map.width + w,
					h * data->map.width + w + 1, ft_colors_lines(data, w, h));
		}
	}
	free(data->t_point);
}
