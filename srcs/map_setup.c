/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:14:55 by rafilipe          #+#    #+#             */
/*   Updated: 2023/06/23 00:42:39 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**get_map(char *infile)
{
	int		fd;
	char	*big;
	char	*temp;
	char	**matrix;

	fd = open(infile, O_RDONLY);
	if (fd < 0 || !infile)
		error("Map File not valid\n");
	big = ft_calloc(1, 1);
	while (TRUE)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		big = ft_strjoin(big, temp);
		free(temp);
	}
	if ((ft_strnstr(big, "\n\n", ft_strlen(big)) != 0))
		error("Map File not valid\n");
	matrix = ft_split(big, '\n');
	free(big);
	close(fd);
	return (matrix);
}

static int	map_size(char **matrix, t_map *map)
{
	int		len;
	int		rows;
	int		count;

	len = 0;
	rows = 0;
	while (matrix[rows][len])
		len++;
	while (matrix[rows])
	{
		count = 0;
		while (matrix[rows][count])
			count++;
		if (count != len)
			return (0);
		rows++;
	}
	if (rows == len)
		return (0);
	map->h = rows;
	map->w = len;
	return (1);
}

static int	check_walls(char **matrix, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->w)
	{
		if (matrix[0][i] != '1' || matrix[map->h - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map->h)
	{
		if (matrix[i][0] != '1' || matrix[i][map->w - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_tokens(char **matrix, t_map *map)
{
	int	i;
	int	exit;
	int	player;
	int	collectible;

	i = 0;
	exit = 0;
	player = 0;
	collectible = 0;
	while (i < map->h)
	{
		exit += str_srch(matrix[i], 'E');
		player += (str_srch(matrix[i], 'P'));
		collectible += (str_srch(matrix[i], 'C'));
		i++;
	}
	if (player != 1 || exit != 1 || collectible == 0)
		error("Check for DUPLICATE TOKENS or NO COLLECTIBLES");
	map->collectible = collectible;
	return (1);
}

int	map_setup(char **matrix, t_map	*map)
{
	int		i;
	int		j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] != '1' && matrix[i][j] != '0' \
				&& matrix[i][j] != 'P' && matrix[i][j] != 'E' \
				&& matrix[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	if (map_size(matrix, map) && check_walls(matrix, map) \
		&& check_tokens(matrix, map) && has_solution(map))
		return (1);
	return (0);
}
