/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:36:01 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/18 23:36:01 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bst	*bst_find(t_bst *root, int key)
{
	if (root == NULL || root->key == key)
		return (root);
	if (key > root->key)
		return (bst_find(root->right, key));
	return (bst_find(root->left, key));
}
