/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 19:13:59 by yruda             #+#    #+#             */
/*   Updated: 2019/04/22 17:36:03 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** allocates mamory for and returns a copy of a 2-story char array
*/

char	**ft_arrdup(char **arr, int height, int width)
{
	char	**copy;
	int		i;

	i = 0;
	copy = NULL;
	if (arr == NULL)
		return (NULL);
	if ((copy = (char **)malloc(sizeof(char*) * height)))
	{
		while (i < height)
		{
			copy[i] = (char *)malloc(sizeof(char) * width);
			ft_memcpy(copy[i], arr[i], width);
			i++;
		}
	}
	return (copy);
}
