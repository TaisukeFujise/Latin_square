/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmori <rmori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 09:59:28 by tafujise          #+#    #+#             */
/*   Updated: 2025/09/14 21:52:03 by rmori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_row_col_duplicate(int **square, int *pos, int number, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < n)
	{
		if (square[pos[0]][i] == number)
			return (0);
		i++;
	}
	while (j < n)
	{
		if (square[j][pos[1]] == number)
			return (0);
		j++;
	}
	return (1);
}
