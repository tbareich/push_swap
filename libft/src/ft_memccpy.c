/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:39:59 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/18 23:39:59 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void	*p;
	size_t	m;

	p = ft_memchr(src, c, n);
	if (p)
		m = (size_t)(p - src + 1);
	else
		m = n;
	ft_memcpy(dst, src, m);
	if (!p)
		return (NULL);
	return (dst + m);
}
