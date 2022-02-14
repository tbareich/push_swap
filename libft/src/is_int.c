/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 01:59:12 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/09 16:03:07 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	is_number(char *number, int index)
{
	while (number[index])
	{
		if (number[index] > '9' || number[index] < '0')
			return (0);
		++index;
	}
	return (1);
}

static int	compare(char *num1, char *num2, int i)
{
	while (num1[i])
	{
		if (num1[i] <= '9' && num1[i] >= '0')
		{
			if (num1[i] > num2[i])
				return (0);
			if (num1[i] < num2[i])
				return (1);
		}
		else
			return (0);
		++i;
	}
	return (1);
}

static char	is_in_int_range(char *number, char *min, char *max)
{
	int		i;
	int		len;
	char	*cmp;

	i = 0;
	if (number[i] == '-')
		++i;
	if (i == 1)
		cmp = min;
	else
		cmp = max;
	len = ft_strlen(number);
	if ((len - i) != 10)
	{
		if ((len - i) < 10)
			return (is_number(number, i));
		return (0);
	}
	return (compare(number, cmp, i));
}

char	is_int(char *number)
{
	if (number == 0)
		return (0);
	return (is_in_int_range(number, "-2147483648", "2147483647"));
}
