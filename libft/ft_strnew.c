/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:11:41 by yruda             #+#    #+#             */
/*   Updated: 2018/11/22 20:23:07 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	new = NULL;
	if (!(new = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (new == NULL)
		return (NULL);
	ft_bzero(new, size + 1);
	return (new);
}
