/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_sudoku_square.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 20:41:55 by tafujise          #+#    #+#             */
/*   Updated: 2025/09/14 16:31:06 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	show_square(int **square);

void	create_square(int	**square, int	*view_nums);

/*
### 二次元配列の作成・値の格納・出力をおこなう関数
関数内では、二次元配列の作成のみで、ほかは関数として分離
*/
void	search_sudoku_square(int *view_nums)
{
	int	**square;
	int	i;
	int	j;

	square = (int **)malloc(sizeof(int *) * 4);
	i = 0;
	while (i < 4)
	{
		square[i] = (int *)malloc(sizeof(int) * 4);
		i ++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			square[i][j] = 0;
			j++;
		}
		i++;
	}
	create_square(square, view_nums);
}
