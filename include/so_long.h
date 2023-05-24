/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:51:41 by rafilipe          #+#    #+#             */
/*   Updated: 2023/05/24 01:31:53 by rafilipe         ###   ########.fr       */
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
typedef struct s_axis {
	int	x;
	int	y;
}	t_axis;


typedef struct s_map {
	char	**matrix;
	int		h;
	int		w;
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

//Checkers
int		check_ext(char *infile);
int		check_args(int ac, char **av);

//Map Setup
char	**map_array(char *infile);
void	parse_map(char **matrix);

/* DEGUG --> DELETE LATER */
void	print_matrix(char **matrix);

#endif