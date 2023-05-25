/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:51:41 by rafilipe          #+#    #+#             */
/*   Updated: 2023/05/25 01:29:03 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "../include/mlx.h"
# include "../libft/libft.h"

/* MACROS */
# define TRUE 1
# define FALSE 0

/* STRUCTS */
typedef struct s_coord {
	int	row;
	int	len;
}	t_coord;

typedef struct s_map {
	char	**matrix;
	int		h;
	int		w;
	t_coord	player;
}	t_map;

typedef struct s_program {
	void	*mlx;
	void	*win;
	int		h;
	int		w;
	t_map	map;
}	t_program;

/**** SRCS *****/

// Error
void	error(char *str);

// Checkers
int		check_ext(char *infile);
int		check_args(int ac, char **av);

// Map Setup
char	**get_map(char *infile);
int		setup_map(char **matrix, t_map *map);
int		map_size(char **matrix, t_map *map);
int		check_walls(char **matrix, t_map *map);
int		check_walls(char **matrix, t_map *map);
int		check_tokens(char **matrix, t_map *map);
int		solution_ok(char **matrix, t_map map);

// Auxiliary
int		str_srch(char *s, char c);
void	get_coord(t_map *map, t_coord *axis, char token);


/* DEGUG --> DELETE LATER */
void	matrix_print(char **matrix);

#endif