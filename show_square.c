/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 21:23:37 by tafujise          #+#    #+#             */
/*   Updated: 2025/09/14 10:14:29 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/*
### 二次元配列を標準出力で出力する関数
*/
void	show_square(int	**square)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (square[i][j] == 1)
				write(1, "1", 1);
			else if (square[i][j] == 2)
				write(1, "2", 1);
			else if (square[i][j] == 3)
				write(1, "3", 1);
			else if (square[i][j] == 4)
				write(1, "4", 1);
			else
				write(1, "Erro4", 6);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
