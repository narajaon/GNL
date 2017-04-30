/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 09:19:28 by narajaon          #+#    #+#             */
/*   Updated: 2017/04/22 15:24:42 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	int fd;
	int ret;
	char *buff;
	char *buff2;

	ret = 0;
	fd = open(av[1], O_RDONLY);
	buff = ft_strnew(BUFF_SIZE);
	buff2 = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buff2, BUFF_SIZE)))
	{
		printf("%d\n", ret);
		buff = ft_strjoin(buff, buff2);
		ft_memdel(&buff2);
	}
	printf("%s\n\n", buff);
	printf("%s", buff2);
	return (0);
}
