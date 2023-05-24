/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:14:55 by rafilipe          #+#    #+#             */
/*   Updated: 2023/05/24 01:15:21 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**map_array(char *infile)
{
	int		fd;
	char	*big;
	char	*temp;
	char	**matrix;

	fd = open(infile, O_RDONLY);
	if (fd < 0 || !infile)
		error("Map File not valid\n");
	big = ft_calloc(1,1);
	while (TRUE)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		big = ft_strjoin(big, temp);
		free(temp);
	}
	matrix = ft_split(big, '\n');
	free(big);
	close(fd);
	parse_map(matrix);
	return (matrix);
}