/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:37:14 by tbareich          #+#    #+#             */
/*   Updated: 2019/04/04 19:48:14 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*p;

	if (*needle == 0)
		return ((char *)haystack);
	p = ft_memchr(haystack, *needle, ft_strlen(haystack));
	while (p)
	{
		if (!ft_memcmp(p, needle, ft_strlen(needle)))
			return (p);
		haystack = p + 1;
		p = ft_memchr(haystack, *needle, ft_strlen(haystack));
	}
	return (NULL);
}
