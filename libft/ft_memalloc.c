/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 18:52:45 by yruda             #+#    #+#             */
/*   Updated: 2018/11/22 20:51:44 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*place;

	place = NULL;
	if (!(place = (void *)malloc((sizeof(void) * size))))
		return (NULL);
	ft_bzero(place, size);
	return (place);
}
