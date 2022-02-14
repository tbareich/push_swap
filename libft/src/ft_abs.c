/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 21:23:19 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/14 20:45:23 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

unsigned long	ft_labs(long num)
{
	if (num < 0)
		return (-num);
	return (num);
}

unsigned long long	ft_llabs(long long num)
{
	if (num < 0)
		return (-num);
	return (num);
}
