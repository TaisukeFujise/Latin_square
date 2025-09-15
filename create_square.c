/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmori <rmori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 22:07:49 by tafujise          #+#    #+#             */
/*   Updated: 2025/09/14 21:57:45 by rmori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		check_row_col_duplicate(int **square, int *pos, int number, int n);
int		check_view_nums(int **square, int *pos, int *view_nums);
void	show_square(int **square, int n);
int		put_num_in_square(int **square, int *pos, int number, int *view_nums);
int		solve_next(int **square, int *pos, int *view_nums);
void	calculate_next_pos(int *pos, int *next_pos, int n);

void	create_square(int **square, int *view_nums)
{
	int	n;
	int	*start_pos;

	n = 1;
	start_pos = malloc(sizeof(int) * 2);
	start_pos[0] = 0;
	start_pos[1] = 0;
	while (n <= view_nums[0])
	{
		if (put_num_in_square(square, start_pos, n, view_nums))
			return ;
		n++;
	}
	write(1, "Error\n", 6);
	free(start_pos);
}

void	calculate_next_pos(int *pos, int *next_pos, int n)
{
	if (pos[0] + 1 >= n)
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

int	solve_next(int **square, int *pos, int *view_nums)
{
	int	n;
	int	*next_pos;

	next_pos = malloc(sizeof(int) * 2);
	calculate_next_pos(pos, next_pos, view_nums[0]);
	n = 1;
	while (n <= view_nums[0])
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

int	put_num_in_square(int **square, int *pos, int number, int *view_nums)
{
	if (!check_row_col_duplicate(square, pos, number, view_nums[0]))
		return (0);
	square[pos[0]][pos[1]] = number;
	if (!check_view_nums(square, pos, view_nums))
	{
		square[pos[0]][pos[1]] = 0;
		return (0);
	}
	if (pos[0] == (view_nums[0] - 1) && pos[1] == (view_nums[0] - 1))
	{
		if (check_view_nums(square, pos, view_nums))
		{
			show_square(square, view_nums[0]);
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
