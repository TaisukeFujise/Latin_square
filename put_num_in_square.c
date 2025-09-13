/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_num_in_square.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 22:07:49 by tafujise          #+#    #+#             */
/*   Updated: 2025/09/14 04:16:07 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

int	check_sudoku_num(int **square, int *pos, int number);
int	check_top_to_bottom(int **square, int *pos, int number, int *view_nums);
int	check_bottom_to_top(int **square, int *pos, int number, int *view_nums);
int	check_left_to_right(int **square, int *pos, int number, int *view_nums);
int	check_right_to_left(int **square, int *pos, int number, int *view_nums);

/*
### 再帰的に数値を二次元配列に格納していく関数（未実装）
check.cにある確認関数を条件分岐にもつ
*/
void	put_num_in_square(int **square, int *pos, int number, int *view_nums)
{
	(void)square;
	(void)view_nums;
	(void)number;
	(void)pos;
	return ;
}
