/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modulo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 01:17:05 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/20 03:24:50 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_modulo(int i, int j)
{
	return (((i % j) + j) % j);
}