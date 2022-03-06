/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_actions_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:41:30 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/03 13:25:13 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	run_actions(t_turn *turn,
			t_operation operation, int index)
{
	while (index)
	{
		run_action(turn, operation, 0);
		--index;
	}
}

void	move_to_top_not_print(t_turn *turn, int index)
{
	int		i;
	t_stack	*stack;

	stack = turn->stack_a;
	if (index >= (int)((stack->top / 2) - 1))
	{
		i = stack->top - 1 - index;
		run_actions(turn, ra, i);
	}
	else
	{
		i = index + 1;
		run_actions(turn, rra, i);
	}
}

void	move_to_index_not_print(t_turn *turn, int source_index, 
										int target_index)
{
	t_stack	*stack;
	int		dist;
	t_operation op;

	stack = turn->stack_a;
	dist = source_index - target_index;
	if (dist < 0)
		op = ra;
	else
		op = rra;
	run_actions(turn, op, abs(dist));

}

static int binary_search(t_stack *stack, int *len_array, int left, int right, int index, int value)
{
	int pivot;

	if (left == right)
	{
		if (value >= stack->array[len_array[left]].value)
		{
			len_array[left] = index;
			if (left > 0)
				return (len_array[left - 1]);
		}
		return (-1);
	}
	pivot = left + (right - left) / 2;
	if (value >= stack->array[len_array[pivot]].value)
		return (binary_search(stack, len_array, left, pivot, index, value));
	return (binary_search(stack, len_array, pivot + 1, right, index, value));
}

static void lis(t_turn *turn)
{
	int *lis_array;
	int *len_array;
	int length;
	int i;
	t_stack *stack_a;

	stack_a = turn->stack_a;
	lis_array = (int *)malloc(stack_a->length * sizeof(int));
	if (lis_array == NULL)
		error(MEMOERROR);
	len_array = (int *)malloc(stack_a->length * sizeof(int));
	if (len_array == NULL)
	{
		ft_memdel((void **)&lis_array);
		error(MEMOERROR);
	}
	length = 0;
	i = turn->stack_a->length;
	while (i > -1)
	{
		lis_array[i] = -1;
		len_array[i] = -1;
		i--;
	}
	i = 0;
	while (i < stack_a->length)
	{
		if (stack_a->array[i].value
			< stack_a->array[len_array[length]].value)
		{
			lis_array[i] = len_array[length];
			++length;
			len_array[length] = i;
		}
		else
			lis_array[i] = binary_search(stack_a, len_array,
			0, length, i, stack_a->array[i].value);
		++i;
	}
	i = len_array[length];
	while (i > -1)
	{
		turn->stack_a->array[i].keep = 1;
		i = lis_array[i];
	}
}

t_action_list	best_actions_list(t_turn *turn, t_stack stack_a)
{
	t_action_list	best_actions;
	int				index;

	best_actions.head = NULL;
	best_actions.length = MAX_INT;
	turn->stack_a = copy_stack(stack_a);
	index = find_min(turn->stack_a);
	if (index != 0)
		move_to_top_not_print(turn, index);
	lis(turn);
	move_to_index_not_print(turn, turn->stack_a->top - 1, index);
	index = turn->stack_a->length;
	while (index)
	{
		if (turn->stack_a->array[turn->stack_a->top - 1].keep != 1)
			run_action(turn, pb, 1);
		else
			run_action(turn, ra, 1);
		--index;
	}
	complex_sort(turn, turn->stack_b->length);
	if (turn->actions->length < best_actions.length)
	{
		ft_lstdel(&(best_actions.head), ft_delcontent);
		best_actions.head = turn->actions->head;
		best_actions.length = turn->actions->length;
		turn->actions->head = NULL;
	}
	else
		ft_lstdel(&(turn->actions->head), ft_delcontent);
	turn->actions->length = 0;
	stack_del(&(turn->stack_a));
	while (turn->stack_b->top)
		pop_stack(turn->stack_b);
	return (best_actions);
}
