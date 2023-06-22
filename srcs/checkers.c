/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:12:14 by rafilipe          #+#    #+#             */
/*   Updated: 2023/06/02 00:03:54 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_ext(char *infile)
{
	int	len;

	len = ft_strlen(infile) - 4;
	if ((ft_strncmp(&infile[len], ".ber", 4)))
		error("File must have .ber extension");
	return (1);
}

int	check_args(int ac, char **av)
{
	if (ac == 1)
		error("You must choose a MAP FILE\n");
	else if (ac == 2 && check_ext(av[1]))
		return (1);
	else if (ac > 2)
		error("Choose only one file\n");
	return (0);
}

static int	check_pos(char **temp_matrix, t_map *map, int p_row, int p_len)
{
	if (p_row < 0 || p_row >= map->h \
		|| p_len < 0 || p_len >= map->w)
		return (0);
	if (temp_matrix[p_row][p_len] != '1' \
		&& temp_matrix[p_row][p_len] != 'X')
	{
		temp_matrix[p_row][p_len] = 'X';
		return (1);
	}
	return (0);
}

static void	flood_fill(char **temp_matrix, t_map *map, int p_row, int p_len)
{
	if (check_pos(temp_matrix, map, p_row + 1, p_len))
		flood_fill(temp_matrix, map, p_row + 1, p_len);
	if (check_pos(temp_matrix, map, p_row -1, p_len))
		flood_fill(temp_matrix, map, p_row - 1, p_len);
	if (check_pos(temp_matrix, map, p_row, p_len + 1))
		flood_fill(temp_matrix, map, p_row, p_len + 1);
	if (check_pos(temp_matrix, map, p_row, p_len - 1))
		flood_fill(temp_matrix, map, p_row, p_len - 1);
}

int	has_solution(t_map *map)
{	
	char	**temp;

	map->temp = matrix_cpy(map->matrix, map->h);
	temp = map->temp;
	get_coord(map, &map->player, 'P');
	flood_fill(temp, map, map->player.row, map->player.len);
	while (*temp)
	{
		if (str_srch(*temp, 'E') || str_srch(*temp, 'C'))
			error("No Solution on Map!");
		temp++;
	}
	return (1);
}
