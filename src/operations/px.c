/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 09:42:27 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/05 21:48:09 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	px(t_stack *destination_stack, t_stack *source_stack)
{
	t_stack_element	*stacl_element;

	stacl_element = pop_stack(source_stack);
	if (stacl_element != NULL)
	{
		push_stack(destination_stack, stacl_element->value);
		ft_memdel((void **)&stacl_element);
	}
}