/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_fts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 00:05:49 by rafilipe          #+#    #+#             */
/*   Updated: 2023/05/28 15:43:20 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	matrix_print(char **matrix)
{
	char **temp;
	
	temp = matrix;
	while (*temp)
	{
		printf("%s\n", *temp);
		temp++;
	}
}
