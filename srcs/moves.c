/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:58:42 by rafilipe          #+#    #+#             */
/*   Updated: 2023/06/22 19:32:58 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_d(t_program *game)
{
	mlx_destroy_image(game->mlx, game->img->player);
	game->img->player = new_file_img("./textures/player_right.xpm", *game);
	if (game->map.matrix[game->map.player.row][game->map.player.len + 1] != '1' \
		&& game->map.matrix[game->map.player.row][game->map.player.len + 1] != 'E')
	{
		if (game->map.matrix[game->map.player.row][game->map.player.len + 1] == 'C')
		{
			game->map.collectible--;
			game->map.matrix[game->map.player.row][game->map.player.len] = '0';
			game->map.player.len++;
			game->map.matrix[game->map.player.row][game->map.player.len] = 'P';
		}
		else if (game->map.matrix[game->map.player.row][game->map.player.len + 1] == '0')
		{
			game->map.matrix[game->map.player.row][game->map.player.len] = '0';
			game->map.player.len++;
			game->map.matrix[game->map.player.row][game->map.player.len] = 'P';
		}
	}
	else if (game->map.matrix[game->map.player.row][game->map.player.len + 1] == 'E')
		is_game_over(game);
	mlx_clear_window(game->mlx, game->win);
	draw_imgs(*game);
}

void	move_a(t_program *game)
{
	mlx_destroy_image(game->mlx, game->img->player);
	game->img->player = new_file_img("./textures/player_left.xpm", *game);
	if (game->map.matrix[game->map.player.row][game->map.player.len - 1] != '1' \
		&& game->map.matrix[game->map.player.row][game->map.player.len - 1] != 'E')
	{
		if (game->map.matrix[game->map.player.row][game->map.player.len - 1] == 'C')
		{
			game->map.collectible--;
			game->map.matrix[game->map.player.row][game->map.player.len] = '0';
			game->map.player.len--;
			game->map.matrix[game->map.player.row][game->map.player.len] = 'P';
		}
		else if (game->map.matrix[game->map.player.row][game->map.player.len - 1] == '0')
		{
			game->map.matrix[game->map.player.row][game->map.player.len] = '0';
			game->map.player.len--;
			game->map.matrix[game->map.player.row][game->map.player.len] = 'P';
		}
	}
	else if (game->map.matrix[game->map.player.row][game->map.player.len - 1] == 'E')
		is_game_over(game);
	mlx_clear_window(game->mlx, game->win);
	draw_imgs(*game);
}

void	move_s(t_program *game)
{
	mlx_destroy_image(game->mlx, game->img->player);
	game->img->player = new_file_img("./textures/player_down.xpm", *game);
	if (game->map.matrix[game->map.player.row + 1][game->map.player.len] != '1' \
		&& game->map.matrix[game->map.player.row + 1][game->map.player.len] != 'E')
	{
		if (game->map.matrix[game->map.player.row + 1][game->map.player.len] == 'C')
		{
			game->map.collectible--;
			game->map.matrix[game->map.player.row][game->map.player.len] = '0';
			game->map.player.row++;
			game->map.matrix[game->map.player.row][game->map.player.len] = 'P';
		}
		else if (game->map.matrix[game->map.player.row + 1][game->map.player.len] == '0')
		{
			game->map.matrix[game->map.player.row][game->map.player.len] = '0';
			game->map.player.row++;
			game->map.matrix[game->map.player.row][game->map.player.len] = 'P';
		}
	}
	else if (game->map.matrix[game->map.player.row + 1][game->map.player.len] == 'E')
		is_game_over(game);
	mlx_clear_window(game->mlx, game->win);
	draw_imgs(*game);
}

void	move_w(t_program *game)
{
	mlx_destroy_image(game->mlx, game->img->player);
	game->img->player = new_file_img("./textures/player_up.xpm", *game);
	if (game->map.matrix[game->map.player.row - 1][game->map.player.len] != '1' \
		&& game->map.matrix[game->map.player.row - 1][game->map.player.len] != 'E')
	{
		if (game->map.matrix[game->map.player.row - 1][game->map.player.len] == 'C')
		{
			game->map.collectible--;
			game->map.matrix[game->map.player.row][game->map.player.len] = '0';
			game->map.player.row--;
			game->map.matrix[game->map.player.row][game->map.player.len] = 'P';
		}
		else if (game->map.matrix[game->map.player.row - 1][game->map.player.len] == '0')
		{
			game->map.matrix[game->map.player.row][game->map.player.len] = '0';
			game->map.player.row--;
			game->map.matrix[game->map.player.row][game->map.player.len] = 'P';
		}
	}
	else if (game->map.matrix[game->map.player.row - 1][game->map.player.len] == 'E')
		is_game_over(game);
	mlx_clear_window(game->mlx, game->win);
	draw_imgs(*game);
}
