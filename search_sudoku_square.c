/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_sudoku_square.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmori <rmori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 20:41:55 by tafujise          #+#    #+#             */
/*   Updated: 2025/09/14 21:47:22 by rmori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	show_square(int **square);

void	create_square(int	**square, int	*view_nums);

void	search_sudoku_square(int *view_nums)
{
	int	**square;
	int	i;
	int	j;

	square = (int **)malloc(sizeof(int *) * view_nums[0]);
	i = 0;
	while (i < view_nums[0])
	{
		square[i] = (int *)malloc(sizeof(int) * view_nums[0]);
		i ++;
	}
	i = 0;
	while (i < view_nums[0])
	{
		j = 0;
		while (j < view_nums[0])
		{
			square[i][j] = 0;
			j++;
		}
		i++;
	}
	create_square(square, view_nums);
}
