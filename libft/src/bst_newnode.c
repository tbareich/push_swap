/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_newnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:36:34 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/18 23:36:34 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bst	*bst_newnode(int key, void *content, size_t content_size)
{
	t_bst	*new;

	new = (t_bst *)malloc(sizeof(t_bst));
	if (new == NULL)
		return (NULL);
	new->key = key;
	new->content_size = content_size;
	new->left = NULL;
	new->right = NULL;
	if (content_size == 0)
	{
		new->content = NULL;
		return (new);
	}
	new->content = malloc(content_size);
	if (new->content == NULL)
	{
		free(new);
		return (NULL);
	}
	ft_memcpy(new->content, content, content_size);
	return (new);
}
