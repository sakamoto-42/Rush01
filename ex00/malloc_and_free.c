/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_and_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:32:11 by thduquen          #+#    #+#             */
/*   Updated: 2024/07/28 17:32:14 by thduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "puzzle.h"

int	allocate_puzzle(t_Puzzle *puzzle)
{
	if (!allocate_puzzle_views(puzzle))
		return (0);
	if (!allocate_puzzle_grid(puzzle))
	{
		free(puzzle->views);
		return (0);
	}
	return (1);
}

int	allocate_puzzle_views(t_Puzzle *puzzle)
{
	puzzle->views = (int *)malloc(puzzle->size * 4 * sizeof(int));
	if (!puzzle->views)
		return (0);
	return (1);
}

int	allocate_puzzle_grid(t_Puzzle *puzzle)
{
	int	i;
	int	j;

	puzzle->grid = (int **)malloc(puzzle->size * sizeof(int *));
	if (!puzzle->grid)
		return (0);
	i = 0;
	while (i < puzzle->size)
	{
		puzzle->grid[i] = (int *)malloc(puzzle->size * sizeof(int));
		if (!puzzle->grid[i])
		{
			j = 0;
			while (j < i)
			{
				free(puzzle->grid[j]);
				j++;
			}
			free(puzzle->grid);
			return (0);
		}
		i++;
	}
	return (1);
}

void	free_puzzle_grid(t_Puzzle *puzzle)
{
	int	i;

	i = 0;
	while (i < puzzle->size)
	{
		free(puzzle->grid[i]);
		i++;
	}
	free(puzzle->grid);
}

void	free_puzzle(t_Puzzle *puzzle)
{
	free(puzzle->views);
	free_puzzle_grid(puzzle);
}
