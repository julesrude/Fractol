/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 18:52:26 by yruda             #+#    #+#             */
/*   Updated: 2018/11/02 18:52:29 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tosearch;
	unsigned long	i;

	i = 0;
	tosearch = (unsigned char *)s;
	while (i < n)
	{
		if (*(tosearch + i) == (unsigned char)c)
			return ((void *)(tosearch + i));
		i++;
	}
	return (NULL);
}
