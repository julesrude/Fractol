/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 16:22:44 by yruda             #+#    #+#             */
/*   Updated: 2018/11/22 18:39:42 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstrn(const char *haystack, const char *needle, size_t len)
{
	unsigned long		j;
	char				*inception;

	j = 0;
	inception = (char *)haystack;
	if (!haystack || !needle)
		return (NULL);
	while (*(haystack))
	{
		j = 1;
		if (*haystack == *needle)
		{
			while (*(haystack + j) == *(needle + j) && j < len)
				j++;
			if (!*(needle + j) || j == len)
				return ((char *)(haystack));
		}
		haystack++;
	}
	return (inception);
}
