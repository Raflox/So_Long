/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:51:41 by rafilipe          #+#    #+#             */
/*   Updated: 2023/05/23 21:14:41 by rafilipe         ###   ########.fr       */
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
# include "../utils/libft/libft.h"
# include "../utils/gnl/get_next_line.h"

/* MACROS */
# define TRUE 1
# define FALSE 0

/* STRUCTS */
typedef struct s_axis {
	int	x;
	int	y;
}	t_axis;


typedef struct s_map {
	char	**map;
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

/* SRCS */
void	error(char *str);
int		check_ext(char *infile);
int		check_args(int ac, char **av);

#endif