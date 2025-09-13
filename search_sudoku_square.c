/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_sudoku_square.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 20:41:55 by tafujise          #+#    #+#             */
/*   Updated: 2025/09/14 04:15:12 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	show_square(int **square);

void	put_num_in_square(int	**square, int	*view_nums);

int		check_sudoku_num(int **square, int i, int j, int number);

/*
### 二次元配列の作成・値の格納・出力をおこなう関数
関数内では、二次元配列の作成のみで、ほかは関数として分離
*/
void	search_sudoku_square(int *view_nums)
{
	int	**square;
	int	i;
	int	j;

	square = (int **)malloc(sizeof(int) * 4);
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
			square[i][j] = j + 1;
			j++;
		}
		i++;
	}
	put_num_in_square(square, view_nums);
	show_square(square);
}
