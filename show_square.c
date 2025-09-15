/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmori <rmori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 21:23:37 by tafujise          #+#    #+#             */
/*   Updated: 2025/09/14 23:30:05 by rmori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	show_square(int	**square, int n)
{
	int		i;
	int		j;
	char	c;

	j = -1;
	while (++j < n)
	{
		i = -1;
		while (++i < n)
		{
			if (1 <= square[i][j] <= n)
			{
				c = square[i][j] + 48;
				write(1, &c, 1);
			}
			else
				write(1, "Error\n", 6);
			if (i != (n - 1))
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}
