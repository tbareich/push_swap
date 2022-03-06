/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:40:50 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/18 23:40:50 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 10 || n <= -10)
		ft_putnbr_fd(n / 10, fd);
	if (n < 0 && n > -10)
		ft_putchar_fd('-', fd);
	if (n < 0)
		ft_putchar_fd((n % 10) * -1 + '0', fd);
	else
		ft_putchar_fd(n % 10 + '0', fd);
}
