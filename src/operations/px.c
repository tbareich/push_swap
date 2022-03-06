/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 09:42:27 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/28 16:01:57 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	px(t_stack *destination_stack, t_stack *source_stack)
{
	t_stack_element	*value;

	value = pop_stack(source_stack);
	if (value != NULL)
		push_stack(destination_stack, value->value, value->keep);
}
