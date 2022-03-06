/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:45:37 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/28 16:00:32 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*copy_stack(t_stack stack)
{
	t_stack	*copy;
	int		i;

	copy = (t_stack *)malloc(sizeof(t_stack));
	init_stack(copy, stack.length);
	i = 0;
	while (i < stack.top)
	{
		push_stack(copy, stack.array[i].value, stack.array[i].keep);
		++i;
	}
	return (copy);
}
