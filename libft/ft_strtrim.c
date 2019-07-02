/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:02:28 by yruda             #+#    #+#             */
/*   Updated: 2018/11/22 18:38:30 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhite(int c)
{
	if (c == 9 || c == 10 || c == 32)
		return (1);
	else
		return (0);
}

char		*ft_strtrim(char const *s)
{
	int	start;
	int	end;

	start = 0;
	end = 0;
	if (s == NULL)
		return (NULL);
	while (ft_iswhite(s[start++]))
		continue ;
	start--;
	end = start;
	while (s[end] != '\0')
		end++;
	while (ft_iswhite(s[end - 1]))
		end--;
	if (end > start)
		return (ft_strsub(s, (size_t)(start), (size_t)(end - start)));
	return (ft_strnew(0));
}
