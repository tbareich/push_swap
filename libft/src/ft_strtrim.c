/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:43:51 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/18 23:43:51 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;

	if (s == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s) - 1;
	while (*(s + start) == '\n' || *(s + start) == '\t' || *(s + start) == ' ')
		start++;
	while (*(s + end) == '\n' || *(s + end) == '\t' || *(s + end) == ' ')
		end--;
	if (end <= start)
		return (ft_strdup(""));
	return (ft_strsub(s, start, end - start + 1));
}
