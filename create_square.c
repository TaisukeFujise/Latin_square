/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 22:07:49 by tafujise          #+#    #+#             */
/*   Updated: 2025/09/14 16:32:21 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define NUM 4

int		check_row_col_duplicate(int **square, int *pos, int number);
int		check_view_nums(int **square, int *pos, int *view_nums);
void	show_square(int **square);
int		put_num_in_square(int **square, int *pos, int number, int *view_nums);
int		solve_next(int **square, int *pos, int *view_nums);
void	calculate_next_pos(int *pos, int *next_pos);

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
	while (n <= NUM)
	{
		if (put_num_in_square(square, start_pos, n, view_nums))
			break ;
		n ++;
	}
	free(start_pos);
}

/*
### solve_next関数内で、次のposを求めるのに使用する関数
*/

void	calculate_next_pos(int *pos, int *next_pos)
{
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
}

/*
### 次の座標の再帰を実行する関数
*/
int	solve_next(int **square, int *pos, int *view_nums)
{
	int	n;
	int	*next_pos;

	next_pos = malloc(sizeof(int) * 2);
	calculate_next_pos(pos, next_pos);
	n = 1;
	while (n <= NUM)
	{
		if (put_num_in_square(square, next_pos, n, view_nums))
		{
			free(next_pos);
			return (1);
		}
		n++;
	}
	free(next_pos);
	return (0);
}

/*
### 再帰的に数値を二次元配列に格納していく関数
check.cにある確認関数を条件分岐にもつ
*/
int	put_num_in_square(int **square, int *pos, int number, int *view_nums)
{
	if (!check_row_col_duplicate(square, pos, number))
		return (0);
	square[pos[0]][pos[1]] = number;
	if (pos[0] == NUM - 1 && pos[1] == NUM - 1)
	{
		if (check_view_nums(square, pos, view_nums))
		{
			show_square(square);
			return (1);
		}
	}
	else
	{
		if (solve_next(square, pos, view_nums))
			return (1);
	}
	square[pos[0]][pos[1]] = 0;
	return (0);
}
