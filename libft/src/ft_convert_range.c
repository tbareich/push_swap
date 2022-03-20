/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_range.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:33:19 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/20 21:01:29 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<libft.h>

int	ft_convert_range(int value, t_range old_range, t_range new_range)
{
	return ((((value - old_range.min) * (new_range.max - new_range.min))
			/ (old_range.max - old_range.min)) + new_range.min);
}
