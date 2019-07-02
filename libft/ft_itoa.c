/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:48:58 by yruda             #+#    #+#             */
/*   Updated: 2018/11/22 20:40:41 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_putitoa(int n, int symbols, int index, char *result)
{
	if (n < 0)
	{
		result[0] = '-';
		ft_putitoa(-n, symbols, index, result);
	}
	else
	{
		if (n >= 10 && n <= 2147483647)
			ft_putitoa(n / 10, symbols, index - 1, result);
		result[index] = n % 10 + '0';
		result[index + 1] = '\0';
	}
	return (result);
}

static char	*ft_itoa_special(int n, char *result)
{
	if (n == -2147483648)
	{
		if ((result = (char *)malloc(sizeof(char) * (11 + 1))))
			ft_strcpy(result, "-2147483648\0");
		return (result);
	}
	if (n == 0)
	{
		if ((result = (char *)malloc(sizeof(char) * (1 + 1))))
			ft_strcpy(result, "0\0");
		return (result);
	}
	return (result);
}

char		*ft_itoa(int n)
{
	long	temp;
	int		i;
	char	*result;

	temp = n;
	i = 0;
	result = NULL;
	if (n == -2147483648 || n == 0)
		return (ft_itoa_special(n, result));
	if (n < 0)
		i++;
	while (temp != 0)
	{
		temp = temp / 10;
		i++;
	}
	if ((result = (char *)malloc(sizeof(char) * (i + 1))))
		ft_putitoa(n, i, i - 1, result);
	return (result);
}
