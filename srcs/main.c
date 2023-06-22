/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:51:21 by rafilipe          #+#    #+#             */
/*   Updated: 2023/06/22 23:00:44 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	game_init(t_program game)
{
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, \
		game.map.w * 32, game.map.h * 32, "SO_LONG");
	game.img = malloc(sizeof(t_img));
	printf("SETUP\n");
	game.moves = 0;
	game.map.over = 0;
	get_imgs(game);
	draw_imgs(game);
	mlx_key_hook(game.win, read_keys, &game);
	mlx_hook(game.win, 17, 0, exit_game, &game);
	mlx_loop(game.mlx);
}

int	main(int ac, char **av)
{
	t_program	game;

	if (check_args(ac, av))
	{
		game.map.matrix = get_map(av[1]);
		if (map_setup(game.map.matrix, &game.map))
		{
			game_init(game);
		}
		else
			error("Bad Map Setup.");
	}
	return (0);
}
