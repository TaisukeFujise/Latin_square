/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 02:15:40 by tafujise          #+#    #+#             */
/*   Updated: 2025/09/14 09:59:16 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
/*
### TopToBottom(coltop)について確認
1. 引数
- square : 4×4の二次元配列
- pos : 参照したい配列内の座標(x, y)をもつ一次元配列
- number : 現在参照している数字
- view_nums : コマンドライン引数で受け取った視点の値の一次元配列
2. 返り値
- true : 1（coltopの値と一致）
- false : 0 (coltopの値と不一致)
*/
int	check_top_to_bottom(int **square, int *pos, int number, int *view_nums)
{
	int	index;
	int	max_num;
	int	count;

	square[pos[0]][pos[1]] = number;
	index = 0;
	max_num = 0;
	count = 0;
	while (index < 4)
	{
		if (max_num < square[pos[0]][index])
		{
			count++;
			max_num = square[pos[0]][index];
		}
		index ++;
	}
	if (count != view_nums[pos[1]])
		return (0);
	return (1);
}

/*
### BottomToTop(colbottomについて確認)
1. 引数
- square : 4×4の二次元配列
- pos : 参照したい配列内の座標(x, y)をもつ一次元配列
- number : 現在参照している数字
- view_nums : コマンドライン引数で受け取った視点の値の一次元配列
2. 返り値
- true : 1（coltopの値と一致）
- false : 0 (coltopの値と不一致)
*/
int	check_bottom_to_top(int **square, int *pos, int number, int *view_nums)
{
	int	index;
	int	max_num;
	int	count;

	square[pos[0]][pos[1]] = number;
	index = 3;
	max_num = 0;
	count = 0;
	while (index >= 0)
	{
		if (max_num < square[pos[0]][index])
		{
			count++;
			max_num = square[pos[0]][index];
		}
		index --;
	}
	if (count != view_nums[pos[1] + 4])
		return (0);
	return (1);
}

/*
### LeftToRight（rowleftの確認）
1. 引数
- square : 4×4の二次元配列
- pos : 参照したい配列内の座標(x, y)をもつ一次元配列
- number : 現在参照している数字
- view_nums : コマンドライン引数で受け取った視点の値の一次元配列
2. 返り値
- true : 1（coltopの値と一致）
- false : 0 (coltopの値と不一致)
*/
int	check_left_to_right(int **square, int *pos, int number, int *view_nums)
{
	int	index;
	int	max_num;
	int	count;

	square[pos[0]][pos[1]] = number;
	index = 0;
	max_num = 0;
	count = 0;
	while (index < 4)
	{
		if (max_num < square[index][pos[1]])
		{
			count++;
			max_num = square[index][pos[1]];
		}
		index ++;
	}
	if (count != view_nums[pos[0] + 4 * 2])
		return (0);
	return (1);
}

/*
### RightToLeft（rowrightの確認）
1. 引数
- square : 4×4の二次元配列
- pos : 参照したい配列内の座標(x, y)をもつ一次元配列
- number : 現在参照している数字
- view_nums : コマンドライン引数で受け取った視点の値の一次元配列
2. 返り値
- true : 1（coltopの値と一致）
- false : 0 (coltopの値と不一致)
*/
int	check_right_to_left(int **square, int *pos, int number, int *view_nums)
{
	int	index;
	int	max_num;
	int	count;

	square[pos[0]][pos[1]] = number;
	index = 3;
	max_num = 0;
	count = 0;
	while (index >= 0)
	{
		if (max_num < square[index][pos[1]])
		{
			count++;
			max_num = square[index][pos[1]];
		}
		index --;
	}
	if (count != view_nums[pos[0] + 4 * 3])
		return (0);
	return (1);
}

int	check_view_nums(int **square, int *pos, int number, int *view_nums)
{
	if (check_top_to_bottom(square, pos, number, view_nums)
		&& check_bottom_to_top(square, pos, number, view_nums)
		&& check_left_to_right(square, pos, number, view_nums)
		&& check_right_to_left(square, pos, number, view_nums))
		return (1);
	else
		return (0);
}
