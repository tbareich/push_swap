/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_inorder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:36:07 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/18 23:36:07 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	bst_inorder(t_bst *root)
{
	if (root == NULL)
		return ;
	bst_inorder(root->left);
	ft_putnbr(root->key);
	ft_putendl(0);
	bst_inorder(root->right);
}
