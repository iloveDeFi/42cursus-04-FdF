/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:05:22 by bat               #+#    #+#             */
/*   Updated: 2023/09/07 14:06:13 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_colors_lines(t_data *data, int x, int y)
{
	int	color;

	if (data->map.parse[y][x] > -2 && data->map.parse[y][x] < 2)
		color = PIXEL_BLACK;
	else if (data->map.parse[y][x] > 2 && data->map.parse[y][x] < 5)
		color = PIXEL_RED;
	else if (data->map.parse[y][x] > 5 && data->map.parse[y][x] < 10)
		color = PIXEL_GREEN;
	else if (data->map.parse[y][x] > -5 && data->map.parse[y][x] < -2)
		color = PIXEL_GOLD;
	else if (data->map.parse[y][x] > -10 && data->map.parse[y][x] < -5)
		color = PIXEL_PINK;
	else
		color = PIXEL_PURPLE;
	return (color);
}

int	ft_color_background(t_data *data)
{
	if (data->key.background == 0)
		return (PIXEL_AZURE);
	else if (data->key.background == 1)
		return (PIXEL_SEASHELL);
	else if (data->key.background == 2)
		return (PIXEL_BISQUE);
	else if (data->key.background == 3)
		return (PIXEL_MISTYROSE);
	else if (data->key.background == 4)
		(PIXEL_HONEY);
	else if (data->key.background > 4)
	{
		data->key.background = 0;
		return (PIXEL_AZURE);
	}
	else if (data->key.background < 0)
	{
		data->key.background = 4;
		return (PIXEL_HONEY);
	}
	return (0);
}
