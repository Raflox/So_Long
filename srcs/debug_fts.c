/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_fts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 00:05:49 by rafilipe          #+#    #+#             */
/*   Updated: 2023/05/24 00:47:11 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_matrix(char **matrix)
{
	char **temp;
	
	temp = matrix;
	while (*temp)
	{
		printf("%s\n", *temp);
		temp++;
	}
}