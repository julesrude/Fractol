/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 20:38:38 by yruda             #+#    #+#             */
/*   Updated: 2018/11/24 20:39:53 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list **alst, t_list *new)
{
	t_list	**temp;

	temp = NULL;
	if (alst == NULL || new == NULL)
		return ;
	temp = alst;
	while (*temp != NULL)
		temp = &(*temp)->next;
	(*temp) = new;
}
