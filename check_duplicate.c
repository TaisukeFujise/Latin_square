/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 09:59:28 by tafujise          #+#    #+#             */
/*   Updated: 2025/09/14 09:59:32 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
### 行と列で重複した数字がないかどうかを確認する関数
1. 引数
- square : 4×4の二次元配列
- pos : 参照したい配列内の座標(x, y)をもつ一次元配列
- number : 現在参照している数字
2. 返り値
- true : 1（重複なし）
- false : 0 (重複あり)
*/
int	check_row_col_duplicate(int **square, int *pos, int number)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		if (square[pos[0]][i] == number)
			return (0);
		i++;
	}
	while (j < 4)
	{
		if (square[j][pos[1]] == number)
		{
			return (0);
		}
		j++;
	}
	return (1);
}
