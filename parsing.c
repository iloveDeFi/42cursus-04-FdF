/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:11:29 by bat               #+#    #+#             */
/*   Updated: 2023/09/07 14:50:19 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_define_size(t_data *data)
{
	int		fd;
	char	*line;

	fd = open(data->map.file, O_RDONLY);
	if (fd < 0)
		ft_display_error("The file cannot be opened.\n");
	line = get_next_line(fd);
	if (!line)
		ft_display_error("The file is empty.\n");
	data->tab = ft_split(line, ' ');
	if (!data->tab)
	{
		free(line);
		ft_display_error("The split result is NULL.\n");
	}
	while (data->tab[data->map.width])
		data->map.width++;
	ft_free_tab_from_split(data->tab);
	while (line)
	{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
		data->map.height++;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
}

/*	Continuation of previous function.
	Parsing to save the value of Z regarding the height and width */
void	ft_parsing_bis(t_data *data, char *line, int y)
{
	int	x;

	x = -1;
	data->tab = ft_split(line, ' ');
	if (!data->tab)
	{
		free(line);
		ft_free_parsing(data, y);
	}
	while (++x < data->map.width)
		data->map.parse[y][x] = ft_atoi(data->tab[x]);
	ft_free_tab_from_split(data->tab);
	free(line);
}

/*	Parsing to save the value of Z regarding the height and width */
void	ft_parsing(t_data *data)
{
	int		fd;
	int		y;
	char	*line;

	y = -1;
	fd = open(data->map.file, O_RDONLY);
	if (fd < 0)
		ft_display_error("The file cannot be opened.\n");
	data->map.parse = malloc(sizeof(int *) * data->map.height);
	if (!data->map.parse)
		ft_display_error("Error with malloc during the parsing.\n");
	while (++y < data->map.height)
	{
		data->map.parse[y] = malloc(sizeof(int) * data->map.width);
		if (!data->map.parse[y])
			ft_free_parsing(data, y - 1);
		line = get_next_line(fd);
		if (!line)
			ft_free_parsing(data, y);
		ft_parsing_bis(data, line, y);
	}
	close (fd);
}
