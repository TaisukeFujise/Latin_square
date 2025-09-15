/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_view_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmori <rmori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 02:15:40 by tafujise          #+#    #+#             */
/*   Updated: 2025/09/14 23:22:52 by rmori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_top_to_bottom(int **square, int *pos, int *view_nums)
{
	int	index;
	int	max_num;
	int	count;
	int	n;

	n = view_nums[0];
	index = 0;
	max_num = 0;
	count = 0;
	while (index < n)
	{
		if (max_num < square[pos[0]][index])
		{
			count++;
			max_num = square[pos[0]][index];
		}
		index++;
	}
	if (count != view_nums[pos[0] + 1] && pos[1] == (n - 1))
		return (0);
	if (count > view_nums[pos[0] + 1])
		return (0);
	return (1);
}

int	check_bottom_to_top(int **square, int *pos, int *view_nums)
{
	int	index;
	int	max_num;
	int	count;
	int	n;

	n = view_nums[0];
	index = n - 1;
	max_num = 0;
	count = 0;
	while (index >= 0)
	{
		if (square[pos[0]][index] == 0)
			return (1);
		if (max_num < square[pos[0]][index])
		{
			count++;
			max_num = square[pos[0]][index];
		}
		index--;
	}
	if (count != view_nums[pos[0] + n + 1])
		return (0);
	return (1);
}

int	check_left_to_right(int **square, int *pos, int *view_nums)
{
	int	index;
	int	max_num;
	int	count;
	int	n;

	n = view_nums[0];
	index = 0;
	max_num = 0;
	count = 0;
	while (index < n)
	{
		if (max_num < square[index][pos[1]])
		{
			count++;
			max_num = square[index][pos[1]];
		}
		index++;
	}
	if (count != view_nums[pos[1] + n * 2 + 1] && pos[0] == (n - 1))
		return (0);
	if (count > view_nums[pos[1] + n * 2 + 1])
		return (0);
	return (1);
}

int	check_right_to_left(int **square, int *pos, int *view_nums)
{
	int	index;
	int	max_num;
	int	count;
	int	n;

	n = view_nums[0];
	index = n - 1;
	max_num = 0;
	count = 0;
	while (index >= 0)
	{
		if (square[index][pos[1]] == 0)
			return (1);
		if (max_num < square[index][pos[1]])
		{
			count++;
			max_num = square[index][pos[1]];
		}
		index--;
	}
	if (count != view_nums[pos[1] + n * 3 + 1])
		return (0);
	return (1);
}

int	check_view_nums(int **square, int *pos, int *view_nums)
{
	if (check_top_to_bottom(square, pos, view_nums)
		&& check_bottom_to_top(square, pos, view_nums)
		&& check_left_to_right(square, pos, view_nums)
		&& check_right_to_left(square, pos, view_nums))
		return (1);
	else
		return (0);
}
