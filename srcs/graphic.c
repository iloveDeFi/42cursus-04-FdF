/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:05:06 by bat               #+#    #+#             */
/*   Updated: 2023/06/19 10:42:39 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*	Initializes the various graphic elements */
void	ft_initialization(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		ft_free_mlx(data, 1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
							WIN_WIDTH, WIN_HEIGHT, "Fil de fer mon ami! \
							MOVE = awsd \
							| ZOOM = zx \
							| ROTATE = rt \
							| ALTITUDE = ul");
	if (data->win_ptr == NULL)
		ft_free_mlx(data, 2);
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (data->img.mlx_img == NULL)
		ft_free_mlx(data, 3);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, \
								&data->img.line_len, &data->img.endian);
	ft_instructions(data);
	mlx_loop_hook(data->mlx_ptr, ft_render, data);
	mlx_loop(data->mlx_ptr);
}

/*	Function called in the mlx_loop_hook */
void	ft_render(t_data *data)
{
	ft_draw_background(data);
	ft_convert(data);
	ft_connect(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
						data->img.mlx_img, 0, 0);
}
