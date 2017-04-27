/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 09:20:17 by narajaon          #+#    #+#             */
/*   Updated: 2017/04/27 19:11:20 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10
# include "./libft/includes/libft.h"
# define  CURRENT line_s->current
# define FULL line_s->full
# define RET line_s->ret

typedef struct	s_line
{
	char	*current;
	char	*full;
	int		ret;
}				t_line;

int				get_next_line(const int fd, char **line);
#endif
