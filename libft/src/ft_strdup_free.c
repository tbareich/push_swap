/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:41:47 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/18 23:41:47 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_free(char **s1)
{
	char	*tmp;

	tmp = ft_strdup(*s1);
	ft_strdel((char **)s1);
	return (tmp);
}
