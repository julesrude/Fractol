/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:40:04 by yruda             #+#    #+#             */
/*   Updated: 2018/11/22 18:35:29 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(char const *s, char c)
{
	int				count;
	int				i;

	count = 0;
	i = 0;
	if (s[0] != c)
		count++;
	while (s[i] != '\0' && s[i + 1] != '\0')
	{
		if (s[i] == c && s[i + 1] != c)
			count++;
		i++;
	}
	return (count);
}

static char		**ft_splitspecial(char const *s, char **result)
{
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) == 0)
	{
		free(result);
		if (!(result = (char **)malloc(sizeof(char *) * (1))))
			return (NULL);
		result[0] = NULL;
		return (result);
	}
	return (NULL);
}

static char		**ft_fillresult(char const *s, char c, char **result)
{
	unsigned int	start;
	unsigned int	end;
	int				i;

	i = -1;
	start = 0;
	end = 0;
	while (++i < count_words(s, c))
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end] != '\0')
			end++;
		if (!(result[i] = ft_strsub(s, start, (size_t)(end - start))))
			return (NULL);
		start = end + 1;
	}
	result[i] = NULL;
	return (result);
}

char			**ft_strsplit(char const *s, char c)
{
	char			**result;

	result = NULL;
	if (s == NULL || ft_strlen(s) == 0)
		return (ft_splitspecial(s, result));
	if (!(result = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1))))
		return (NULL);
	return (ft_fillresult(s, c, result));
}
