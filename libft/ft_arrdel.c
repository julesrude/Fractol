/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 19:12:28 by yruda             #+#    #+#             */
/*   Updated: 2019/01/26 19:12:34 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** frees and sets to NULL elements of a 2-story array
*/

void	ft_arrdel(void **arr, int elems)
{
	int	i;

	i = 0;
	while (i < elems)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
}
