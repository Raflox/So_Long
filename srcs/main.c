/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:51:21 by rafilipe          #+#    #+#             */
/*   Updated: 2023/06/22 18:48:53 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
/* 
void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x < img.w && y < img.h) {
		dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
		*(unsigned int *) dst = color;
	}
}

unsigned int	get_pixel_img(t_img img, int x, int y) {
	return (*(unsigned int *)((img.addr
			+ (y * img.line_len) + (x * img.bpp / 8))));
}

void	put_img_to_img(t_img dst, t_img src, int x, int y) {
	int i;
	int j;

	i = 0;
	while(i < src.w) {
		j = 0;
		while (j < src.h) {
			put_pixel_img(dst, x + i, y + j, get_pixel_img(src, i, j));
			j++;
		}
		i++;
	}
} */


int	main(int ac, char **av)
{
	t_program	game;

	if (check_args(ac, av))
	{
		game.map.matrix = get_map(av[1]);
		if (map_setup(game.map.matrix, &game.map))
		{
			game.mlx = mlx_init();
			game.win = mlx_new_window(game.mlx, game.map.w * 32, game.map.h * 32, "SO_LONG");
			//game.map = malloc(sizeof(t_map));
			game.img = malloc(sizeof(t_img));
			printf("SETUP\n");
			game.moves = 0;
			get_imgs(game);
			draw_imgs(game);
			mlx_key_hook(game.win, read_keys, &game);
			mlx_hook(game.win, 17, 0, exit_game, &game);
		}
		else 
			error("Bad Map Setup.");
		mlx_loop(game.mlx);
	}
	return (0);
}
