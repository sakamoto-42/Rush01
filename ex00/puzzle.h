/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:33:16 by thduquen          #+#    #+#             */
/*   Updated: 2024/07/28 17:33:19 by thduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUZZLE_H
# define PUZZLE_H

typedef struct s_puzzle
{
	int	size;
	int	**grid;
	int	*views;
}	t_Puzzle;

void	print_error_unsolvable(void);
void	print_error_arguments(void);
void	print_solution(t_Puzzle *puzzle);
int		is_valid_sudoku(t_Puzzle *puzzle, int row, int col, int num);

int		check_col_up(t_Puzzle *puzzle);
int		check_col_down(t_Puzzle *puzzle);
int		check_row_left(t_Puzzle *puzzle);
int		check_row_right(t_Puzzle *puzzle);
int		check_view(t_Puzzle *puzzle);

int		solve(t_Puzzle *puzzle, int row, int col);

void	parse_views(const char *str, t_Puzzle *puzzle);

int		is_valid_format(const char *str, int size);
void	init_grid(t_Puzzle *puzzle);
int		determine_size(int len);
int		initialize_puzzle(t_Puzzle *puzzle, char *param, int len);
void	free_puzzle_grid(t_Puzzle *puzzle);
int		allocate_puzzle_views(t_Puzzle *puzzle);
int		allocate_puzzle_grid(t_Puzzle *puzzle);
int		allocate_puzzle(t_Puzzle *puzzle);
void	free_puzzle(t_Puzzle *puzzle);

#endif
