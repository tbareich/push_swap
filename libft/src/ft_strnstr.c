/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:43:22 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/18 23:43:22 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*p;

	if (*needle == 0)
		return ((char *)haystack);
	p = ft_strstr(haystack, needle);
	if (p + ft_strlen(needle) > haystack + len)
		return (NULL);
	return (p);
}
