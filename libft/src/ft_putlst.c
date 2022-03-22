/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:40:47 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/18 23:40:47 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putlst(t_list *lst)
{
	if (lst == NULL)
	{
		ft_putstr("empty list");
		return ;
	}
	while (lst)
	{
		ft_putstr("\"");
		if (lst->content != NULL)
			ft_putstr(lst->content);
		else
			ft_putstr("NULL");
		ft_putstr("\"");
		if (lst->next)
			ft_putstr(" -> ");
		lst = lst->next;
	}
}
