/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 09:19:28 by narajaon          #+#    #+#             */
/*   Updated: 2017/04/26 13:27:36 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_line	*init_struct(t_line *line_s)
{
//	printf("rwrqreqw");
	if (!(line_s = (t_line *)malloc(sizeof(t_line))) ||
				!(line_s->current = ft_strnew(BUFF_SIZE)) ||
			!(line_s->remain = ft_strnew(BUFF_SIZE)) ||
			!(line_s->full = ft_strnew(BUFF_SIZE)) ||
			!(line_s->next = ft_strnew(BUFF_SIZE)))
		return (NULL);
	//line_s->i++;
	return (line_s);
}

void	format(t_line *line_s)
{
	int	i;

	i = 0;
	while (line_s->current[i] && line_s->current[i] != '\n')
		i++;
	if (line_s->current[i] == '\n')
	{
		line_s->remain = ft_strsub(line_s->current, 0, i);
		line_s->next = ft_strsub(line_s->current, i + 1, ft_strlen(line_s->current));
	}
}

int		get_next_line(const int fd, char **line)
{
	static t_line	*line_s;
	int				ret;

	if (!line_s)
	{
		if (!(line_s = init_struct(line_s)))
			return (-1);
	}
	else
	{
		ft_strclr(line_s->full);
		line_s->full = ft_strjoin(line_s->full, line_s->next);
	}
	while ((ret = read(fd, line_s->current, BUFF_SIZE) > 0))
	{
		if (ft_strchr(line_s->current, '\n'))
		{
			format(line_s);
			line_s->full = ft_strjoin(line_s->full, line_s->remain);
			*line = line_s->full;
//			printf("full %s\n", line_s->full);
			return (1);
		}
		else
		{
			line_s->full = ft_strjoin(line_s->full, line_s->current);
			ft_strclr(line_s->current);
		}
	}
	return (0);
}

int		main(int ac, char **av)
{
	int fd;
	int ret;
	char *ptr;

	fd = open(av[1], O_RDONLY);
	//printf("%d\n", fd);
	//close(fd);
	while ((ret = get_next_line(fd, &ptr) > 0))
		printf("%s\n", ptr);
	//ret = get_next_line(fd, &ptr);
	//ret = get_next_line(fd, &ptr);
	//printf("%s\n\n", ptr);
	//printf("\nret %d\n", ret);
	return (0);
}
