/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_lst_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:18:03 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/02 17:58:21 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	add_remaining_lst_actions(t_turn *turn,
	t_list *a_lst, t_list *b_lst)
{
	t_operation	a_operation;
	t_operation	b_operation;

	while (a_lst)
	{
		a_operation = *((t_operation *)(a_lst->content));
		add_action(turn, a_operation);
		a_lst = a_lst->next;
		ft_lstdelone(&(turn->a_actions->head), ft_delcontent);
		turn->a_actions->head = a_lst;
	}
	while (b_lst)
	{
		b_operation = *((t_operation *)(b_lst->content));
		add_action(turn, b_operation);
		b_lst = b_lst->next;
		ft_lstdelone(&(turn->b_actions->head), ft_delcontent);
		turn->b_actions->head = b_lst;
	}
}

static int	mergt_operations(t_turn *turn, t_list *a_lst, t_list *b_lst)
{
	t_operation	a_operation;
	t_operation	b_operation;

	b_operation = *((t_operation *)(b_lst->content));
	if (b_operation == pa)
		return (1);
	a_operation = *((t_operation *)(a_lst->content));
	if (a_operation == ra && b_operation == rb)
		add_action(turn, rr);
	else if (a_operation == rra && b_operation == rrb)
		add_action(turn, rrr);
	else if (a_operation == sa && b_operation == sb)
		add_action(turn, ss);
	else
	{
		add_action(turn, b_operation);
		add_action(turn, a_operation);
	}
	return (0);
}

void	add_lst_actions(t_turn *turn)
{
	t_list		*a_lst;
	t_list		*b_lst;

	a_lst = turn->a_actions->head;
	b_lst = turn->b_actions->head;
	while (b_lst && a_lst)
	{
		if (mergt_operations(turn, a_lst, b_lst))
			break ;
		a_lst = a_lst->next;
		b_lst = b_lst->next;
		ft_lstdelone(&(turn->a_actions->head), ft_delcontent);
		ft_lstdelone(&(turn->b_actions->head), ft_delcontent);
		turn->a_actions->head = a_lst;
		turn->b_actions->head = b_lst;
	}
	add_remaining_lst_actions(turn, a_lst, b_lst);
}
