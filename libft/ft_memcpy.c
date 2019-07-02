/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 19:48:32 by yruda             #+#    #+#             */
/*   Updated: 2018/11/02 18:57:57 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned long	i;
	char			*idest;
	char			*isrc;

	isrc = (char *)src;
	idest = (char *)dst;
	i = 0;
	while (i < n)
	{
		idest[i] = isrc[i];
		i++;
	}
	dst = (void *)idest;
	return (dst);
}
