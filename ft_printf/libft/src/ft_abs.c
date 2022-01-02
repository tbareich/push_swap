/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 21:23:19 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/01 21:28:13 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned			ft_abs(int num)
{
	return num < 0 ? -num : num;
}

unsigned long		ft_labs(long num)
{
	return num < 0 ? -num : num;
}

unsigned long long	ft_llabs(long long num)
{
	return num < 0 ? -num : num;
}