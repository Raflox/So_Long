/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:58:42 by rafilipe          #+#    #+#             */
/*   Updated: 2023/06/22 18:52:04 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_d(t_program *game)
{
	t_coord	*player;

	player = &game->map.player;
	mlx_destroy_image(game->mlx, game->img->player);
	game->img->player = new_file_img("./textures/player_right.xpm", *game);
	if (game->map.matrix[player->row][player->len + 1] != '1' \
		&& game->map.matrix[player->row][player->len + 1] != 'E')
	{
		if (game->map.matrix[player->row][player->len + 1] == 'C')
		{
			game->map.collectible--;
			game->map.matrix[player->row][player->len] = '0';
			game->map.player.len++;
			game->map.matrix[player->row][player->len] = 'P';
		}
		else if (game->map.matrix[player->row][player->len + 1] == '0')
		{
			game->map.matrix[player->row][player->len] = '0';
			game->map.player.len++;
			game->map.matrix[player->row][player->len] = 'P';
		}
	}
	mlx_clear_window(game->mlx, game->win);
	draw_imgs(*game);
	
}

void	move_a(t_program *game)
{
	t_coord	*player;

	player = &game->map.player;
	mlx_destroy_image(game->mlx, game->img->player);
	game->img->player = new_file_img("./textures/player_left.xpm", *game);
	if (game->map.matrix[player->row][player->len - 1] != '1' \
		&& game->map.matrix[player->row][player->len - 1] != 'E')
	{
		if (game->map.matrix[player->row][player->len - 1] == 'C')
		{
			game->map.collectible--;
			game->map.matrix[player->row][player->len] = '0';
			game->map.player.len--;
			game->map.matrix[player->row][player->len] = 'P';
		}
		else if (game->map.matrix[player->row][player->len - 1] == '0')
		{
			game->map.matrix[player->row][player->len] = '0';
			game->map.player.len--;
			game->map.matrix[player->row][player->len] = 'P';
		}
	}
	mlx_clear_window(game->mlx, game->win);
	draw_imgs(*game);
}

void	move_s(t_program *game)
{
	t_coord	*player;

	player = &game->map.player;
	mlx_destroy_image(game->mlx, game->img->player);
	game->img->player = new_file_img("./textures/player_down.xpm", *game);
	if (game->map.matrix[player->row + 1][player->len] != '1' \
		&& game->map.matrix[player->row + 1][player->len] != 'E')
	{
		if (game->map.matrix[player->row + 1][player->len] == 'C')
		{
			game->map.collectible--;
			game->map.matrix[player->row][player->len] = '0';
			game->map.player.row++;
			game->map.matrix[player->row][player->len] = 'P';
		}
		else if (game->map.matrix[player->row + 1][player->len] == '0')
		{
			game->map.matrix[player->row][player->len] = '0';
			game->map.player.row++;
			game->map.matrix[player->row][player->len] = 'P';
		}
	}
	mlx_clear_window(game->mlx, game->win);
	draw_imgs(*game);
}

void	move_w(t_program *game)
{
	t_coord	*player;

	player = &game->map.player;
	mlx_destroy_image(game->mlx, game->img->player);
	game->img->player = new_file_img("./textures/player_up.xpm", *game);
	if (game->map.matrix[player->row - 1][player->len] != '1' \
		&& game->map.matrix[player->row - 1][player->len] != 'E')
	{
		if (game->map.matrix[player->row - 1][player->len] == 'C')
		{
			game->map.collectible--;
			game->map.matrix[player->row][player->len] = '0';
			game->map.player.row--;
			game->map.matrix[player->row][player->len] = 'P';
		}
		else if (game->map.matrix[player->row - 1][player->len] == '0')
		{
			game->map.matrix[player->row][player->len] = '0';
			game->map.player.row--;
			game->map.matrix[player->row][player->len] = 'P';
		}
	}
	mlx_clear_window(game->mlx, game->win);
	draw_imgs(*game);
}