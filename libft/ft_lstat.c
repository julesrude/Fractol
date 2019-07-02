/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 20:39:18 by yruda             #+#    #+#             */
/*   Updated: 2018/11/24 20:39:31 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat(t_list *begin_list, unsigned int nbr)
{
	unsigned int i;

	i = 1;
	while (i < nbr)
	{
		if (!begin_list || !(begin_list->next))
			return (NULL);
		begin_list = begin_list->next;
		i++;
	}
	return (begin_list);
}
