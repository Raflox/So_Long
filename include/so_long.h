/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:51:41 by rafilipe          #+#    #+#             */
/*   Updated: 2023/06/22 19:19:35 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

/* MACROS */
# define TRUE 1
# define FALSE 0
# define ESC 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2

/* STRUCTS */
typedef struct s_coord {
	int	row;
	int	len;
}	t_coord;

typedef struct s_img
{
	void	*wall;
	void	*player;
	void	*exit_true;
	void	*exit_false;
	void	*collectible;
	void	*blank;
}	t_img;

typedef struct s_map {
	char	**matrix;
	char	**temp;
	int		h;
	int		w;
	int		collectible;
	int		over;
	t_coord	player;
}	t_map;

typedef struct s_program {
	void	*mlx;
	void	*win;
	t_map	map;
	t_img	*img;
	int		moves;
}	t_program;

/**** SRCS *****/

// Error
void	error(char *str);

// Checkers
int		check_ext(char *infile);
int		check_args(int ac, char **av);

// Map Setup
char	**get_map(char *infile);
int		map_setup(char **matrix, t_map *map);
int		has_solution(t_map *map);

// Window
int		read_keys(int key_pressed, t_program *game);
int		exit_game(t_program *game);
void	is_game_over(t_program *game);

// Auxiliary
int		str_srch(char *s, char c);
void	get_coord(t_map *map, t_coord *axis, char token);
char	**matrix_cpy(char **src, int row);

// Images
void	draw_imgs(t_program game);
void	get_imgs(t_program game);
void	*new_file_img(char *path, t_program game);

// Moves
void	move_w(t_program *game);
void	move_a(t_program *game);
void	move_s(t_program *game);
void	move_d(t_program *game);

/* DEGUG --> DELETE LATER */
void	matrix_print(char **matrix);

#endif