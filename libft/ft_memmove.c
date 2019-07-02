/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 14:42:53 by yruda             #+#    #+#             */
/*   Updated: 2018/11/22 20:37:21 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dsttemp;
	const char	*srctemp;

	dsttemp = (char *)dst;
	srctemp = (const char *)src;
	if (dsttemp < srctemp)
	{
		while (len)
		{
			*dsttemp++ = *srctemp++;
			len--;
		}
	}
	else
	{
		while (len)
		{
			*(dsttemp + len - 1) = *(srctemp + len - 1);
			len--;
		}
	}
	return (dst);
}
