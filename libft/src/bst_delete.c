/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:35:35 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/18 23:35:35 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	bst_delete(t_bst *root)
{
	if (root == NULL)
		return ;
	bst_delete(root->left);
	bst_delete(root->right);
	free(root->content);
	free(root);
}
