/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 19:48:13 by yruda             #+#    #+#             */
/*   Updated: 2018/11/22 18:55:06 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,
					int c, size_t n)
{
	unsigned long	i;
	unsigned char	*idest;
	unsigned char	*isrc;

	isrc = (unsigned char *)src;
	idest = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		idest[i] = isrc[i];
		if (isrc[i] == (unsigned char)c)
		{
			dst = (void *)idest;
			return (&dst[i + 1]);
		}
		i++;
	}
	return (NULL);
}
