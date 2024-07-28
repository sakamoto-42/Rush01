/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:32:21 by thduquen          #+#    #+#             */
/*   Updated: 2024/07/28 17:32:24 by thduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "puzzle.h"

void	print_error_unsolvable(void)
{
	write(1, "Error\n", 6);
}
/*The arguments you enterred are not solvable\n", 51);*/

void	print_error_arguments(void)
{
	write(1, "Error\n", 6);
}
/*"Please enter 1 argument containing 16 numbers:\n", 54);
	write(1, "Between 1 and 4 for each column, and each row\n", 46);*/

void	print_solution(t_Puzzle *puzzle)
{
	char	buffer[1000];
	int		index;
	int		i;
	int		j;

	index = 0;
	i = 0;
	while (i < puzzle->size)
	{
		j = 0;
		while (j < puzzle->size)
		{
			buffer[index++] = puzzle->grid[i][j] + '0';
			if (j < puzzle->size - 1)
				buffer[index++] = ' ';
			j++;
		}
		buffer[index++] = '\n';
		i++;
	}
	write(1, buffer, index);
}
