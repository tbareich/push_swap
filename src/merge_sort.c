/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 04:29:50 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/06 04:52:21 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_list	*sorted_merge(t_list *a, t_list *b)
{
    t_list* result;

	result = NULL;
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    if ((((t_indexing *)a->content)->value) <=
			((t_indexing *)b->content)->value)
	{
        result = a;
        result->next = sorted_merge(a->next, b);
    }
    else
	{
        result = b;
        result->next = sorted_merge(a, b->next);
    }
    return (result);
}

static void		front_back_split(t_list *source,
                    t_list **frontRef, t_list **backRef)
{
    t_list* fast;
    t_list* slow;

    slow = source;
    fast = source->next;
    while (fast != NULL)
	{
        fast = fast->next;
        if (fast != NULL)
		{
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

void 			merge_sort(t_list **headRef)
{
    t_list*	head;
    t_list*	a;
    t_list*	b;

	head = *headRef;
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
    front_back_split(head, &a, &b);
    merge_sort(&a);
    merge_sort(&b);
    *headRef = sorted_merge(a, b);
}

void			print_sorted_list(t_list *head)
{
    while (head != NULL) {
        ft_printf("{%d, %d}",((t_indexing *)head->content)->index,
				((t_indexing *)head->content)->value);
        head = head->next;
		if (head != NULL)
			ft_putstr(" -> ");
		else
			ft_putstr("\n");
    }
}