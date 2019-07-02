/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:36:25 by yruda             #+#    #+#             */
/*   Updated: 2018/11/02 18:38:17 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char				*inception;
	unsigned long		i;

	inception = dst;
	i = 0;
	while (i < len && (*dst = *src))
	{
		i++;
		if (dst++ && src++)
			continue ;
	}
	while (i < len && (dst))
	{
		*dst++ = '\0';
		i++;
	}
	return (inception);
}
