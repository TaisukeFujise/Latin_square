/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 22:07:49 by tafujise          #+#    #+#             */
/*   Updated: 2025/09/14 10:34:09 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define NUM 4

int		is_valid_num(char c);
int		check_row_col_duplicate(int **square, int *pos, int number);
int		check_view_nums(int **square, int *pos, int number, int *view_nums);
void	show_square(int	**square);

/*
### 再帰的に数値を二次元配列に格納していく関数
check.cにある確認関数を条件分岐にもつ
*/
int	put_num_in_square(int **square, int *pos, int number, int *view_nums)
{
	int	n;
	int	*next_pos;

	if (square[pos[0]][pos[1]] != number)
	{
		if (!check_row_col_duplicate(square, pos, number))
			return (0);
		square[pos[0]][pos[1]] = number;
	}
	if (pos[0] == NUM - 1 && pos[1] == NUM - 1)
		show_square(square);
	else
	{
		next_pos = malloc(sizeof(int) * 2);
		if (pos[0] + 1 >= NUM)
		{
			next_pos[0] = 0;
			next_pos[1] = pos[1] + 1;
		}
		else
		{
			next_pos[0] = pos[0] + 1;
			next_pos[1] = pos[1];
		}
		n = 1;
		while (n <= NUM)
		{
			if (!check_row_col_duplicate(square, next_pos, number))
				continue ;
			if (check_view_nums(square, next_pos, n, view_nums)
				&& put_num_in_square(square, next_pos, number, view_nums))
				return (1);
			square[pos[0]][pos[1]] = 0;
			n++;
		}
	}
	return (1);
}

/*
### 初期位置と初期設定をして、数値を格納する再帰関数をスタートさせる関数
*/
void	create_square(int **square, int *view_nums)
{
	int	n;
	int	*start_pos;

	n = 1;
	start_pos = malloc(sizeof(int) * 2);
	start_pos[0] = 0;
	start_pos[1] = 0;
	while (n <= 4)
	{
		put_num_in_square(square, start_pos, n, view_nums);
		n++;
	}
}
