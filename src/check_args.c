#include <push_swap.h>

static void	indexing(t_stack *stack, t_list *head)
{
	int	i;
	t_indexing *elem;
	t_indexing *elem_cmp;

	merge_sort(&head);
	// print_sorted_list(head);
	i = 0;
	while (head != NULL)
	{
		elem = (t_indexing *)(head->content);
		stack->array[elem->index] = i;
		if (head->next != NULL)
		{
			elem_cmp = (t_indexing *)(head->next->content);
			if (elem->value == elem_cmp->value)
				error(DEFAULTERROR);
		}
		head = head->next;
		++i;
	}
}

void	check_args(t_turn *turn, int ac, char **av)
{
	int 	i;
	int 	number;
	t_list	*head;
	t_list	*node;
	t_indexing	indexing_element;

	i = ac - 1;
	head = NULL;
	while (i > 0)
	{
		if (is_int(av[i]) == 0)
			error(DEFAULTERROR);
		number = atoi(av[i]);
		if (push_stack(turn->stack_a, number))
			error(DEFAULTERROR);
		indexing_element.value = number;
		indexing_element.index = turn->stack_a->top - 1;
		if ((node = ft_lstnew(&indexing_element, sizeof(t_indexing))) == NULL)
			error(MEMOERROR);
		ft_lstadd(&head, node);
		--i;
	}
	indexing(turn->stack_a, head);
	ft_lstdel(&head, ft_delcontent);
}