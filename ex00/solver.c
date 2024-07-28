/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:32:31 by thduquen          #+#    #+#             */
/*   Updated: 2024/07/28 17:32:34 by thduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puzzle.h"

int	solve(t_Puzzle *puzzle, int row, int col)
{
	int	num;

	if (row == puzzle->size)
		return (check_view(puzzle));
	if (col == puzzle->size)
		return (solve(puzzle, row + 1, 0));
	num = 1;
	while (num <= puzzle->size)
	{
		if (is_valid_sudoku(puzzle, row, col, num))
		{
			puzzle->grid[row][col] = num;
			if (solve(puzzle, row, col + 1))
				return (1);
			puzzle->grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

int	is_valid_sudoku(t_Puzzle *puzzle, int row, int col, int num)
{
	int	x;

	x = 0;
	while (x < puzzle->size)
	{
		if (puzzle->grid[row][x] == num || puzzle->grid[x][col] == num)
			return (0);
		x++;
	}
	return (1);
}

int	check_view(t_Puzzle *puzzle)
{
	return (check_col_up(puzzle) && check_col_down(puzzle)
		&& check_row_left(puzzle) && check_row_right(puzzle));
}
