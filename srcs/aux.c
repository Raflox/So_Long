/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:46:52 by rafilipe          #+#    #+#             */
/*   Updated: 2023/05/25 01:28:41 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	str_srch(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

void	get_coord(t_map *map, t_coord *axis, char token)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->h)
	{
		j = 0;
		while (j < map->w)
		{
			if (map->matrix[i][j] == token)
			{
				axis->row = i;
				axis->len = j;
			}
			j++;
		}
		i++;
	}
}

/* def dfs(grid, i, j, old_color, new_color):
    n = len(grid)
    m = len(grid[0])
    if i < 0 or i >= n or j < 0 or j >= m or grid[i][j] != old_color:
        return
    else:
        grid[i][j] = new_color
        dfs(grid, i+1, j, old_color, new_color)
        dfs(grid, i-1, j, old_color, new_color)
        dfs(grid, i, j+1, old_color, new_color)
        dfs(grid, i, j-1, old_color, new_color)

def flood_fill(grid, i, j, new_color):
    old_color = grid[i][j]
    if old_color == new_color:
        return
    dfs(grid, i, j, old_color, new_color) */
