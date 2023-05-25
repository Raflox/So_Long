/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:51:21 by rafilipe          #+#    #+#             */
/*   Updated: 2023/05/25 01:55:21 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

	// Check Path

int	main(int ac, char **av)
{
	t_program	game;

	if (check_args(ac, av))
	{
		/* printf("AQUI\n"); */
		game.mlx = mlx_init();
		game.map.matrix = get_map(av[1]);
		if (setup_map(game.map.matrix, &game.map))
			printf("SETUP\n");
		else
			printf("SETUP WRONG\n");
/* 		get_coord(&game.map, &game.map.player, 'P');
		printf("row: %d", game.map.player.row);
		printf("len: %d", game.map.player.len); */
	}
	return (0);
}
