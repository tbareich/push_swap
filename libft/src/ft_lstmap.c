/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:39:10 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/18 23:39:10 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*hdr;

	if (lst == NULL)
		return (NULL);
	hdr = (*f)(lst);
	if (hdr == NULL)
		return (NULL);
	tmp = hdr;
	lst = lst->next;
	while (lst)
	{
		tmp->next = (*f)(lst);
		if (tmp->next == NULL)
		{
			ft_lstdel(&hdr, ft_delcontent);
			return (NULL);
		}
		lst = lst->next;
		tmp = tmp->next;
	}
	return (hdr);
}
