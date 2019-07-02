/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrtint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 19:13:14 by yruda             #+#    #+#             */
/*   Updated: 2019/01/26 19:13:19 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** finds a root (whole number) for an int.
** if the root is not a whole number, it takes the closest whole from the + side
*/

int		ft_sqrtint(unsigned int i)
{
	unsigned int	root;

	root = 0;
	while (root * root < i)
		root++;
	return (root);
}
