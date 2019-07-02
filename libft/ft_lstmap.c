/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:44:31 by yruda             #+#    #+#             */
/*   Updated: 2018/11/22 20:48:18 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	**indirect;

	new = NULL;
	indirect = NULL;
	indirect = &new;
	while (lst != NULL)
	{
		(*indirect) = ft_lstnew(((*f)(lst))->content,
								((*f)(lst))->content_size);
		lst = lst->next;
		indirect = &(*indirect)->next;
	}
	return (new);
}
