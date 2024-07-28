/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_views.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:33:50 by thduquen          #+#    #+#             */
/*   Updated: 2024/07/28 17:33:52 by thduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puzzle.h"

int	check_col_up(t_Puzzle *puzzle)
{
	int	row;
	int	col;
	int	max;
	int	visible;

	col = 0;
	while (col < puzzle->size)
	{
		row = 0;
		max = 0;
		visible = 0;
		while (row < puzzle->size)
		{
			if (puzzle->grid[row][col] > max)
			{
				max = puzzle->grid[row][col];
				visible++;
			}
			row++;
		}
		if (visible != puzzle->views[col])
			return (0);
		col++;
	}
	return (1);
}

int	check_col_down(t_Puzzle *puzzle)
{
	int	row;
	int	col;
	int	max;
	int	visible;

	col = 0;
	while (col < puzzle->size)
	{
		row = puzzle->size - 1;
		max = 0;
		visible = 0;
		while (row >= 0)
		{
			if (puzzle->grid[row][col] > max)
			{
				max = puzzle->grid[row][col];
				visible++;
			}
			row--;
		}
		if (visible != puzzle->views[col + puzzle->size])
			return (0);
		col++;
	}
	return (1);
}

int	check_row_left(t_Puzzle *puzzle)
{
	int	row;
	int	col;
	int	max;
	int	visible;

	row = 0;
	while (row < puzzle->size)
	{
		col = 0;
		max = 0;
		visible = 0;
		while (col < puzzle->size)
		{
			if (puzzle->grid[row][col] > max)
			{
				max = puzzle->grid[row][col];
				visible++;
			}
			col++;
		}
		if (visible != puzzle->views[row + 2 * puzzle->size])
			return (0);
		row++;
	}
	return (1);
}

int	check_row_right(t_Puzzle *puzzle)
{
	int	row;
	int	col;
	int	max;
	int	visible;

	row = 0;
	while (row < puzzle->size)
	{
		col = puzzle->size - 1;
		max = 0;
		visible = 0;
		while (col >= 0)
		{
			if (puzzle->grid[row][col] > max)
			{
				max = puzzle->grid[row][col];
				visible++;
			}
			col--;
		}
		if (visible != puzzle->views[row + 3 * puzzle->size])
			return (0);
		row++;
	}
	return (1);
}
