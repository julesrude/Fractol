/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numwords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 20:36:21 by yruda             #+#    #+#             */
/*   Updated: 2018/11/24 20:36:32 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_numwords(char const *s)
{
	size_t			count;
	int				i;

	count = 0;
	i = 0;
	if (!ft_iswhitespace(s[0]) && s[0] != '\0')
		count++;
	while (s[i] != '\0' && s[i + 1] != '\0')
	{
		if (ft_iswhitespace(s[i]) && !ft_iswhitespace(s[i + 1]))
			count++;
		i++;
	}
	return (count);
}
