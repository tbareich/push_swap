/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 01:59:12 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/02 18:40:28 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	is_in_int_range(char *number, char *min, char *max)
{
	int		i;
	int		len;
	char	*cmp;

	i = 0;
	len = ft_strlen(number);
	if (number[i] == '-')
		++i;
	if (i == 1)
		cmp = min;
	else
		cmp = max;
	if ((len - i) != 10)
		return ((len - i) < 10);
	while (number[i])
	{
		if (number[i] > cmp[i] || number[i] > '9' || number[i] < '0')
			return (0);
		++i;
	}
	return (1);
}

char		is_int(char *number)
{
	if (number == 0)
		return 0;
 	return is_in_int_range(number, "-2147483648", "2147483647");
}