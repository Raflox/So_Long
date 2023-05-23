/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:12:14 by rafilipe          #+#    #+#             */
/*   Updated: 2023/05/23 21:16:47 by rafilipe         ###   ########.fr       */
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
