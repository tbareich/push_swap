/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:42:19 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/18 23:42:19 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lend;
	size_t	lens;

	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	if (size > lend)
	{
		ft_bzero(dst + lend, size - lend);
		ft_memccpy(dst + lend, src, 0, size - lend - 1);
	}
	if (size < lend)
		return (lens + size);
	return (lend + lens);
}
