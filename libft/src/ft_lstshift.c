/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstshift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:39:46 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/18 23:39:46 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstshift(t_list **alst)
{
	t_list	*tmp;

	if (alst == NULL || *alst == NULL)
		return (NULL);
	tmp = *alst;
	*alst = (*alst)->next;
	return (tmp);
}
