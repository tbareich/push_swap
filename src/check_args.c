/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 22:22:56 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/14 22:22:56 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	indexing(t_stack *stack, t_list **head)
{
	int			i;
	t_indexing	*elem;
	t_indexing	*elem_cmp;
	t_list		*tmp;

	merge_sort(head);
	i = 0;
	tmp = *head;
	while (tmp != NULL)
	{
		elem = (t_indexing *)(tmp->content);
		stack->array[elem->index].value = i;
		if (tmp->next != NULL)
		{
			elem_cmp = (t_indexing *)(tmp->next->content);
			if (elem->value == elem_cmp->value)
				error(DEFAULTERROR);
		}
		tmp = tmp->next;
		++i;
	}
}

void	check_args(t_turn *turn, int ac, char **av)
{
	int			i;
	int			number;
	t_list		*head;
	t_list		*node;
	t_indexing	indexing_element;

	i = ac - 1;
	head = NULL;
	while (i > 0)
	{
		if (is_int(av[i]) == 0)
			error(DEFAULTERROR);
		number = atoi(av[i]);
		if (push_stack(turn->stack_a, number, 0))
			error(DEFAULTERROR);
		indexing_element.value = number;
		indexing_element.index = turn->stack_a->top - 1;
		node = ft_lstnew(&indexing_element, sizeof(t_indexing));
		if (node == NULL)
			error(MEMOERROR);
		ft_lstadd(&head, node);
		--i;
	}
	indexing(turn->stack_a, &head);
	ft_lstdel(&head, ft_delcontent);
}
