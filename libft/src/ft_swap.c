/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:04:49 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/09 16:04:49 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_swap(t_stack_element *elem1, t_stack_element *elem2)
{
	t_stack_element	tmp;

	tmp = *elem1;
	*elem1 = *elem2;
	*elem2 = tmp;
}
