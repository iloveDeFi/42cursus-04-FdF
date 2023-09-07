/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:05:22 by bat               #+#    #+#             */
/*   Updated: 2023/09/07 23:33:09 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_colors_lines(t_data *data, int x, int y)
{
	int	color;

	if (data->map.parse[y][x] > -2 && data->map.parse[y][x] < 2)
		color = PIXEL_DEEPPINK4;
	else if (data->map.parse[y][x] > 2 && data->map.parse[y][x] < 5)
		color = PIXEL_ALICEBLUE;
	else if (data->map.parse[y][x] > 5 && data->map.parse[y][x] < 10)
		color = PIXEL_BLUEVIOLET;
	else if (data->map.parse[y][x] > -5 && data->map.parse[y][x] < -2)
		color = PIXEL_KHAKI4;
	else if (data->map.parse[y][x] > -10 && data->map.parse[y][x] < -5)
		color = PIXEL_BURLYWOOD4;
	else
		color = PIXEL_FORESTGREEN;
	return (color);
}

int	ft_color_background(t_data *data)
{
	if (data->key.background == 0)
		return (PIXEL_LAVENDERBLUSH);
	else if (data->key.background == 1)
		return (PIXEL_DARKORCHID);
	else if (data->key.background == 2)
		return (PIXEL_DARKGREY);
	else if (data->key.background == 3)
		return (PIXEL_DEEPPINK1);
	else if (data->key.background == 4)
		(PIXEL_ROSYBROWN4);
	else if (data->key.background > 4)
	{
		data->key.background = 0;
		return (PIXEL_LAVENDERBLUSH);
	}
	else if (data->key.background < 0)
	{
		data->key.background = 4;
		return (PIXEL_ROSYBROWN4);
	}
	return (0);
}
