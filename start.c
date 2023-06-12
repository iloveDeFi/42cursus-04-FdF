/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:24:56 by bat               #+#    #+#             */
/*   Updated: 2023/06/12 11:44:02 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <unistd.h>

void    ft_putchar(char c)
{
    write (1, &c, 1);
}

// Appelé lorsqu'on appuie sur une touche de la fenêtre
// param de deal_key video https://www.youtube.com/watch?v=l7bLDAWAPfI&t=47s&ab_channel=V%C3%ADdeos
int deal_key(int key, void *param)
{
    ft_putchar('X');
    mlx_pixel_put(mlx_ptr, win_ptr, );
    return (0);
}

int main()
{
    void    *mlx_ptr;
    void    *win_ptr;

    mlx_ptr = mlx_init(); // initialiser la connexion
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42"); // mlx_new_window (créé la fenêtre?)renvoie l'id de la fenêtre
    mlxPixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF); // afficher un pixel dans l'image en appuyant sur une certaine touche
    mlx_Key_Hook(win_ptr, deal_key, (void *)0); // (window id, pointeur sur fonction, param);
    mlx_loop(mlx_ptr); // dessine et gère les évènements
}