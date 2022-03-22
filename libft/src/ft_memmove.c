/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:40:22 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/18 23:40:22 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src - dst > 0)
		ft_memcpy(dst, src, len);
	else if (src - dst < 0)
	{
		while (len > 0)
		{
			--len;
			*(unsigned char *)(dst + len) = *(unsigned char *)(src + len);
		}
	}
	return (dst);
}
