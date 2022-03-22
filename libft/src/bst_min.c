/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:36:22 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/18 23:36:22 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_bst	*bst_min(t_bst *root)
{
	if (root == NULL)
		return (NULL);
	while (root->left)
	{
		root = root->left;
	}
	return (root);
}
