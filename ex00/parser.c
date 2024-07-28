/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:31:53 by thduquen          #+#    #+#             */
/*   Updated: 2024/07/28 17:31:56 by thduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puzzle.h"

void	parse_views(const char *str, t_Puzzle *puzzle)
{
	int	i;

	i = 0;
	while (i < puzzle->size * 4)
	{
		puzzle->views[i] = str[i * 2] - '0';
		i++;
	}
}

int	determine_size(int len)
{
	if (len == 31)
		return (4);
	if (len == 39)
		return (5);
	return (0);
}
/*  
La meme logique fonctionnerait en theorie pour de plus grands tableaux
if (len == 47) return 6;
if (len == 57) return 7;
if (len == 63) return 8;
if (len == 71) return 9;*/
