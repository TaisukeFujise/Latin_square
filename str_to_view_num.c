/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_view_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 19:07:16 by tafujise          #+#    #+#             */
/*   Updated: 2025/09/14 16:13:20 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*
### 数字文字が'1'~'4'かどうかを確認する関数
*/
int	is_valid_num(char c)
{
	return ('1' <= c && c <= '4');
}

/*
### コマンドライン引数の文字列をint型の配列にする関数
 */
void	str_to_view_nums(char *str, int *view_nums)
{
	int	index;

	index = 0;
	while (index < 16)
	{
		while (!is_valid_num(*str))
			str++;
		if (!is_valid_num(*str))
			write(1, "Erro1\n", 6);
		else
			view_nums[index] = *str - '0';
		str++;
		index++;
	}
	if (index != 16)
		write(1, "Erro3\n", 6);
}
