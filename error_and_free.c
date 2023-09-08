/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:05:33 by bat               #+#    #+#             */
/*   Updated: 2023/09/08 11:19:43 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_display_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void	ft_free_tab_from_split(char *tab[])
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	ft_free_parsing(t_data *data, int y)
{
	while (y >= 0)
	{
		free (data->map.parse[y]);
		y--;
	}
	free(data->map.parse);
	ft_display_error("Error during the parsing.\n");
}

void	ft_free_map_parse(t_data *data)
{
	int	y;

	y = data->map.height - 1;
	while (y >= 0)
	{
		free(data->map.parse[y]);
		y--;
	}
	free(data->map.parse);
}

void	ft_free_mlx(t_data *data, int flag)
{
	if (flag == 1)
	{
		ft_free_map_parse(data);
		ft_display_error("MLX_ERROR\n");
	}
	else if (flag == 2)
	{
		ft_free_map_parse(data);
		free(data->mlx_ptr);
		ft_display_error("MLX ERROR.\n");
	}
	else
	{
		ft_free_map_parse(data);
		free(data->mlx_ptr);
		free(data->win_ptr);
		ft_display_error("MLX ERROR.\n");
	}
}
