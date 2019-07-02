/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:39:10 by yruda             #+#    #+#             */
/*   Updated: 2019/04/22 17:35:33 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int num, int pow)
{
	int		i;
	int		result;

	i = 0;
	result = 1;
	if (pow < 0)
		return (-1);
	while (i < pow)
	{
		result *= num;
		i++;
	}
	return (result);
}
