/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:16:45 by yruda             #+#    #+#             */
/*   Updated: 2019/03/19 14:39:07 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 1000
# define R_TOEND(fd, line) { while(get_next_line(fd, &text) == 1) {R_TOEND1} }
# define R_TOEND1 temp = line; if(line) line = ft_strjoin(line, text); R_TOEND2
# define R_TOEND2 else line = ft_strdup(text); free (temp); free (text);

int	get_next_line(const int fd, char **line);

#endif
