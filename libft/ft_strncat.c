/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 21:16:30 by yruda             #+#    #+#             */
/*   Updated: 2018/11/22 18:47:57 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	char			*start;
	unsigned long	i;

	i = 0;
	start = s1;
	while (*s1++)
		continue ;
	s1 = s1 - 1;
	while (i < n && (*s1++ = *s2++))
		i++;
	if (i == n)
		*s1 = '\0';
	return (start);
}
