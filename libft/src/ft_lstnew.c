/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:39:22 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/18 23:39:22 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*p;

	p = (t_list *)malloc(sizeof(t_list));
	if (p == NULL)
		return (NULL);
	p->next = NULL;
	if (content == NULL)
	{
		p->content = NULL;
		p->content_size = 0;
		return (p);
	}
	p->content = ft_memalloc(content_size);
	if (p->content == NULL)
	{
		free(p);
		return (NULL);
	}
	ft_memcpy(p->content, content, content_size);
	p->content_size = content_size;
	return (p);
}
