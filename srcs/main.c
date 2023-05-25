/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:51:21 by rafilipe          #+#    #+#             */
/*   Updated: 2023/05/25 01:36:48 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

	// Check Path

/* int	flood_fill(char **matrix, t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (x < 0 || x >= map->h || y < 0 || y >= map->w) {
		return;
	}
	
	if (matrix[x][y] != targetColor) {
		// Not the target color
		return;
	}
	
	matrix[x][y] = replacementColor; // Replace the color
	
	// Recursively call floodFill on neighboring cells
	floodFill(matrix, rows, cols, x + 1, y, targetColor, replacementColor);
	floodFill(matrix, rows, cols, x - 1, y, targetColor, replacementColor);
	floodFill(matrix, rows, cols, x, y + 1, targetColor, replacementColor);
	floodFill(matrix, rows, cols, x, y - 1, targetColor, replacementColor);
} */
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
