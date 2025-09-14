/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 19:04:41 by tafujise          #+#    #+#             */
/*   Updated: 2025/09/14 10:15:03 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define FAIL -1
#define N 16 /*4×4の盤面のサイズ*/

void	str_to_view_nums(char *str, int *view_nums);

void	search_sudoku_square(int *view_nums);

int	main(int argc, char **argv)
{
	int	*view_nums;

	view_nums = malloc(sizeof(int) * N);

	if (argc != 2)
	{
		write(1, "Erro5\n", 6);
		return (FAIL);
	}
	else
		str_to_view_nums(argv[1], view_nums);
	search_sudoku_square(view_nums);
}
