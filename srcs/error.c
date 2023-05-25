/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:01:03 by rafilipe          #+#    #+#             */
/*   Updated: 2023/05/25 00:02:57 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error(char *str)
{
	// Add function to free memory
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	exit (0);
}
