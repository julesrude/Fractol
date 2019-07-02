/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 20:53:15 by yruda             #+#    #+#             */
/*   Updated: 2018/11/02 18:41:35 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	char *start;

	start = s1;
	while (*s1++)
		continue ;
	s1 = s1 - 1;
	while ((*s1++ = *s2++))
		continue ;
	return (start);
}
