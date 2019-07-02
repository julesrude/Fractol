/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:57:30 by yruda             #+#    #+#             */
/*   Updated: 2018/11/30 18:57:40 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_lstdelelem(t_list **head, t_list **elem)
{
	t_list			**indirect;

	if (!elem || !(*elem) || !head || !(*head))
		return (1);
	indirect = head;
	if ((*head)->next)
	{
		while (((*indirect)->next) && (*indirect) != (*elem))
			indirect = &(*indirect)->next;
		*indirect = (*elem)->next;
	}
	else if (*elem == *head)
		*head = NULL;
	else
		return (1);
	free(*elem);
	*elem = NULL;
	return (1);
}

t_list	*ft_lstsearch(t_list **start, size_t fd_search)
{
	t_list			*temp;

	temp = NULL;
	if (!start || !(*start))
		return (NULL);
	temp = *start;
	while (temp != NULL && temp->content_size != fd_search)
		temp = temp->next;
	return (temp);
}

void	ft_divide(char *todivide, char **line, t_list *current)
{
	char			*tmp;
	char			*tmp1;
	int				i;

	i = 0;
	tmp = NULL;
	tmp1 = NULL;
	while (todivide[i] != '\n')
		i++;
	tmp1 = ft_strsub(todivide, 0, i);
	tmp = ft_strjoin(*line, tmp1);
	ft_strdel(line);
	ft_strdel(&tmp1);
	*line = ft_strdup(tmp);
	free(tmp);
	if (i <= (int)ft_strlen(todivide))
		current->content = (void *)ft_strdup(ft_strchr(todivide, '\n') + 1);
}

int		ft_pullfromlst(t_list **resids, t_list **current, int fd, char **line)
{
	char			*temp;

	temp = NULL;
	if (!((*current) = ft_lstsearch(resids, fd)))
	{
		(*current) = ft_lstnew((void *)0, 0);
		ft_lstadd(resids, (*current));
		(*current)->content_size = fd;
	}
	else
	{
		if (ft_strchr((*current)->content, '\n'))
		{
			temp = ft_strdup((*current)->content);
			ft_strdel((char **)&((*current)->content));
			ft_divide(temp, line, (*current));
			ft_strdel(&temp);
			return (1);
		}
		if (*line)
			free(*line);
		*line = ft_strdup((*current)->content);
		free(((*current)->content));
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*resids;
	t_list			*current;
	int				num;
	char			*temp;
	char			buffer[BUFF_SIZE + 1];

	if (!line || read(fd, 0, 0) < 0 || !(*line = ft_strnew(0)) || BUFF_SIZE < 1)
		return (-1);
	if (ft_pullfromlst(&resids, &current, fd, line))
		return (1);
	while ((num = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[num] = '\0';
		if (ft_strchr(buffer, '\n'))
		{
			ft_divide(buffer, line, current);
			break ;
		}
		temp = *line;
		*line = ft_strjoin(*line, buffer);
		ft_strdel(&temp);
	}
	if (num == 0 && ft_lstdelelem(&resids, &current) && ft_strequ(*line, "\0"))
		return (0);
	return (1);
}
