/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 01:59:12 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/02 02:17:56 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	compare_string_numbers(char *num1, char *num2)
{
	int i;

	i = 0;
	while (num1[i])
	{
		if (num1[i] > num2[i])
			return (1);
		else if (num1[i] < num2[i])
			return (-1);
		
		++i;
	}
	return (0);
}

char	is_int(char *number, char *min, char* max)
{
	char	cmp;
	if (number == 0)
		return 0;
	if (number[0] == '-')
		cmp = compare_string_numbers(number + 1, min + 1);
	else
		cmp = compare_string_numbers(number, max);
	return (cmp <= 0);
}