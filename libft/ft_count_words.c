/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 18:32:25 by yruda             #+#    #+#             */
/*   Updated: 2019/02/11 21:58:14 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		isword_delimiter(char c)
{
	if (c == ' ' || c == '	')
		return (1);
	return (0);
}

int		ft_count_words(char const *s)
{
	int				count;
	int				i;

	count = 0;
	i = 0;
	if (!isword_delimiter(s[0]))
		count++;
	while (s[i] != '\0' && s[i + 1] != '\0')
	{
		if (isword_delimiter(s[i]) && !isword_delimiter(s[i + 1]))
			count++;
		i++;
	}
	return (count);
}
