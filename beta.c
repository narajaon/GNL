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

int		err_out(char **line)
{
	if (!line)
		return (-1);
	*line = "";
	return (-1);
}

void	*init_clr(t_line *line_s, int command)
{
	if (command == 0)
	{
		if (!(line_s = (t_line *)malloc(sizeof(t_line))) ||
				!(CURRENT = ft_strnew(BUFF_SIZE)))
			return (NULL);
		return (line_s);
	}
	ft_strclr(CURRENT);
//	free(line_s);
	return ((void *)1);
}

int		format(t_line *line_s, char **line, char *full)
{
	int		i;
	char	*tmp;

	i = 0;
	while (CURRENT[i] && CURRENT[i] != '\n')
		i++;
	if (!CURRENT[i + 1])
	{
		CURRENT[i] = '\0';
		*line = ft_strjoin(full, CURRENT);
		init_clr(line_s, 1);
		return (RET);
	}
	tmp = ft_strsub(CURRENT, 0, i);
	*line = ft_strjoin(full, tmp);
	ft_strdel(&tmp);
	CURRENT = ft_memmove(CURRENT, &CURRENT[i + 1], ft_strlen(CURRENT));
	((RET < BUFF_SIZE) && !ft_strchr(CURRENT, '\n')) ? ft_strclr(CURRENT) : CURRENT;
	return (RET);
}

/*ne renvoie rien a la fin du fichier!*/

int		get_next_line(const int fd, char **line)
{
	static t_line	*line_s;
	char			*tmp;
	char			*full;

	if (fd < 0 || !line)
		return (err_out(line));
	line_s = (line_s) ? line_s : init_clr(line_s, 0);
	if (ft_strchr(CURRENT, '\n'))
		return (format(line_s, line, full));
	full = ft_strdup(CURRENT);
	ft_strclr(CURRENT);
	while ((RET = read(fd, CURRENT, BUFF_SIZE)) > 0)
	{
		if (ft_strchr(CURRENT, '\n'))
			return (format(line_s, line, full));
		tmp = ft_strjoin(full, CURRENT);
		ft_strdel(&full);
		full = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	*line = ft_strdup(full);
	init_clr(line_s, 1);
	return (RET);
}
/*
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
//	while ((ret = get_next_line(fd, &ptr) > 0))
//		printf("RET %d line |%s|\n", ret, ptr)
//			;
	get_next_line(fd, &ptr);
	//printf("RET %d final |%s|\n", ret, ptr);
	//ret = get_next_line(fd, &ptr);
	//ret = get_next_line(fd, &ptr);
	printf("%s\n", ptr);
	//printf("cmp %d\n", ft_strcmp(ptr, ""));
	//printf("ret %d", ret);
	return (0);
}*/
