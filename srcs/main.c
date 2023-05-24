/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:51:21 by rafilipe          #+#    #+#             */
/*   Updated: 2023/05/24 01:32:19 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	parse_map(char **matrix)
{
	// Check Walls
	// Check for Exit
	// Check for player position
	// Check Path
	(void)matrix;
	
}

t_map	setup_map(char *infile)
{
	t_map	map;

	map.matrix = map_array(infile);
	/* print_matrix(map.matrix); */
	return (map);
}

int	main(int ac, char **av)
{
	t_program	game;

	if (check_args(ac, av))
	{
		/* printf("AQUI\n"); */
		game.mlx = mlx_init();
		game.map = setup_map(av[1]);
	}
	return (0);
}
