/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_view_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmori <rmori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 19:07:16 by tafujise          #+#    #+#             */
/*   Updated: 2025/09/14 22:32:29 by rmori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	stringlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	is_valid_num(char c, int n)
{
	return ('1' <= c && c <= (n + 48));
}

int	str_to_view_nums(char *str, int *view_nums)
{
	int	index;

	if (stringlen(str) != (view_nums[0] * 8 - 1))
		return (0);
	index = 1;
	while (index <= (view_nums[0] * 4))
	{
		if (!is_valid_num(*str, view_nums[0]))
			return (0);
		else
			view_nums[index] = *str - '0';
		str++;
		if (!(*str == 32 || *str == 0))
			return (0);
		index++;
		str++;
	}
	if (index != (view_nums[0] * 4 + 1))
		return (0);
	return (1);
}
