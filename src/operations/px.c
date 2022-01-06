/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 09:42:27 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/06 11:27:16 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	px(t_stack *destination_stack, t_stack *source_stack)
{
	int		*value;

	value = pop_stack(source_stack);
	if (value != NULL)
		push_stack(destination_stack, *value);
}