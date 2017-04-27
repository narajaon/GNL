/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 09:19:28 by narajaon          #+#    #+#             */
/*   Updated: 2017/04/27 19:27:08 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_line	*init_struct(t_line *line_s)
{
	if (!(line_s = (t_line *)malloc(sizeof(t_line))) ||
			!(CURRENT = ft_strnew(BUFF_SIZE)) ||
			!(FULL = ft_strnew(BUFF_SIZE)))
		return (NULL);
	return (line_s);
}

int		format(t_line *line_s, char **line)
{
	int i;

	i = 0;
	while (CURRENT[i] && CURRENT[i] != '\n')
		i++;
//	printf("curr %c\n", CURRENT[i]);
	if (!(FULL = ft_strjoin(FULL, ft_strsub(CURRENT, 0, i + 1))))
		return (-1);
	CURRENT = ft_memmove(CURRENT, &CURRENT[i + 1], ft_strlen(CURRENT));
	FULL[ft_strlen(FULL) - 1] = (FULL[ft_strlen(FULL) - 1] == '\n') ?
		'\0' : FULL[ft_strlen(FULL) - 1];
	*line = FULL;
	return (1);
}

/*ne renvoie rien a la fin du fichier!*/

int		get_next_line(const int fd, char **line)
{
	static t_line	*line_s;

	if (fd < 0 || !(line_s = (!line_s) ? init_struct(line_s) : line_s))
		return (-1);
	ft_strclr(FULL);
	if (!(ft_strchr(CURRENT, '\n')))
		FULL = ft_strcpy(FULL, CURRENT);
		printf("??|%s|\n", FULL);
	if (ft_strchr(CURRENT, '\n'))
		return (format(line_s, line));
	while ((RET = read(fd, CURRENT, BUFF_SIZE)) > 0)
	{
		if (ft_strchr(CURRENT, '\n'))
			return (format(line_s, line));
		if (!(FULL = ft_strjoin(FULL, CURRENT)))
			return (-1);
		ft_strclr(CURRENT);
	}
	return (RET);
}

int		main(int ac, char **av)
{
	int fd;
	int ret;
	char *ptr;

	if (ac != 2)
		return (0);
	ret = 0;
	fd = open(av[1], O_RDONLY);
	//close(fd);
	while ((ret = get_next_line(fd, &ptr) > 0))
		printf("%s\n", ptr)
			;
	//get_next_line(fd, &ptr);
	//printf("%s\n", ptr);
	//printf("ptr |%s|\n", ptr);
	printf("cmp %d\n", ft_strcmp(ptr, "aaa"));
	//printf("ret %d", ret);
	return (0);
}
