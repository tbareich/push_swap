#include <push_swap.h>

void	check_args(t_turn *turn, int ac, char **av)
{
	int 	i;
	int 	number;
	t_list	*head;
	t_list	*node;
	t_indexing	indexing_element;

	if (ac < 2)
		error(DEFAULTERROR);
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
	merge_sort(&head);
	print_sorted_list(head);
}