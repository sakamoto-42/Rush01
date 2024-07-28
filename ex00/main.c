/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:31:43 by thduquen          #+#    #+#             */
/*   Updated: 2024/07/28 17:31:47 by thduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "puzzle.h"

int	is_valid_format(const char *str, int size)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((i % 2 == 0 && (str[i] < '1' || str[i] > '5'))
			|| (i % 2 == 1 && str[i] != ' '))
			return (0);
		i++;
	}
	return (i == (size * 4 * 2 - 1));
}

// il faudrait mofifier jusqu a 9 pour un 9x9

void	init_grid(t_Puzzle *puzzle)
{
	int	i;
	int	j;

	i = 0;
	while (i < puzzle->size)
	{
		j = 0;
		while (j < puzzle->size)
		{
			puzzle->grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	initialize_puzzle(t_Puzzle *puzzle, char *param, int len)
{
	puzzle->size = determine_size(len);
	if (puzzle->size == 0)
	{
		print_error_arguments();
		return (0);
	}
	if (!allocate_puzzle(puzzle))
	{
		print_error_arguments();
		return (0);
	}
	if (!is_valid_format(param, puzzle->size))
	{
		print_error_arguments();
		free_puzzle(puzzle);
		return (0);
	}
	parse_views(param, puzzle);
	init_grid(puzzle);
	return (1);
}

int	main(int argc, char **argv)
{
	t_Puzzle	puzzle;
	int			len;

	len = 0;
	if (argc != 2)
	{
		print_error_arguments();
		return (1);
	}
	while (argv[1][len])
		len++;
	if (!initialize_puzzle(&puzzle, argv[1], len))
		return (1);
	if (solve(&puzzle, 0, 0))
		print_solution(&puzzle);
	else
		print_error_unsolvable();
	free_puzzle(&puzzle);
	return (0);
}
