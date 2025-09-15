/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 19:04:41 by tafujise          #+#    #+#             */
/*   Updated: 2025/09/14 23:31:57 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#define N 4

int		str_to_view_nums(char *str, int *view_nums);

void	search_sudoku_square(int *view_nums);

int	main(int argc, char **argv)
{
	int	*view_nums;

	view_nums = malloc(sizeof(int) * (N * 4 + 1));
	view_nums[0] = N;
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	else
	{
		if (!str_to_view_nums(argv[1], view_nums))
		{
			write(1, "Error\n", 6);
			return (1);
		}
	}
	search_sudoku_square(view_nums);
}
