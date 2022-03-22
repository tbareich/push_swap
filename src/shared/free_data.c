/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 00:11:56 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/22 18:19:51 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	free_data(t_data *data)
{
	if (data->stack_a->array != NULL)
		stack_del_content(data->stack_b);
	stack_del_content(data->stack_a);
	return (0);
}
