/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 01:52:34 by tbareich          #+#    #+#             */
/*   Updated: 2019/04/14 19:08:34 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddat(t_list **alst, t_list *new, int index)
{
	t_list	*tmp;

	if (alst == NULL || index < 0 || *alst == NULL)
		return ;
	if (index == 0)
	{
		ft_lstadd(alst, new);
		return ;
	}
	tmp = *alst;
	--index;
	while (index-- && tmp->next)
	{
		tmp = tmp->next;
	}
	new->next = tmp->next;
	tmp->next = new;
}
