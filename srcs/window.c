/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:07:12 by rafilipe          #+#    #+#             */
/*   Updated: 2023/06/22 18:48:32 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	exit_game(t_program *game)
{
	if (game)
		mlx_destroy_window(game->mlx, game->win);
	exit (0);
}

int	read_keys(int key_pressed, t_program *game)
{
/* 	int	counter;

	counter = game->moves; */
	if (key_pressed == ESC)
		exit_game(game);
	else if (key_pressed == W_KEY)
		move_w(game);
	else if (key_pressed == A_KEY)
		move_a(game);
	else if (key_pressed == S_KEY)
		move_s(game);
	else if (key_pressed == D_KEY)
		move_d(game);
	// mlx_string_put(game->mlx, game->win, 0, 0, 255255255, ft_itoa(game->moves)); 
return (0);
}
