/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 19:46:45 by yruda             #+#    #+#             */
/*   Updated: 2018/11/22 21:00:58 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LONGLIMIT 9223372036854775807

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' ||
		c == '\n' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int				sign;
	unsigned long	result;

	sign = 1;
	result = 0;
	while (ft_isspace(*str))
		str = str + 1;
	if (*str == '-')
	{
		sign = -1;
		str = str + 1;
	}
	else if (*str == '+')
		str = str + 1;
	while (*str >= '0' && *str <= '9')
	{
		if ((sign == 1 && result > LONGLIMIT / 10) ||
			(sign == 1 && result == LONGLIMIT / 10 && (*str - '0') >= 7))
			return (-1);
		else if ((sign == -1) && (result > LONGLIMIT / 10 ||
			(result == LONGLIMIT / 10 && (*str - '0') >= 8)))
			return (0);
		result = result * 10 + (*str++ - '0');
	}
	return (sign * result);
}
