/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:51:21 by rafilipe          #+#    #+#             */
/*   Updated: 2023/05/23 21:17:21 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* t_map	setup_map(char *infile)
{
	t_map	map;
} */

int	main(int ac, char **av)
{
	//t_program	game;

	if (check_args(ac, av))
	{
		printf("AQUI\n");
		/* game.mlx = mlx_init();
		game.map = setup_map(av[1]); */
	}
	return (0);
}
