/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 09:20:17 by narajaon          #+#    #+#             */
/*   Updated: 2017/04/22 14:57:19 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
# define BUFF_SIZE 8
# include "./libft/includes/libft.h"

typedef struct s_line
{
	int wid;
	int line;
}				t_line;

int		get_next_line(const int fd, char **line);
#endif
