#include "get_next_line.h"

int		err_out(char **line, int fd)
{
	if (fd < 0 && line)
		*line = "";
	return (-1);
}

t_line	*init_clr(t_line *line_s)
{
	//(RET = BUFF_SIZE) ? ft_strclr(CURRENT) : CURRENT;
	CURRENT = CURRENT ? CURRENT : ft_strnew(BUFF_SIZE);
	TMP = &CURRENT;
	FULL = ft_strnew(1);
	RET = 0;
	return (line_s);
}

int		format(t_line *line_s, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	while (CURRENT[i] && CURRENT[i] != '\n')
		i++;
	tmp = ft_strsub(CURRENT, 0, i);
	*line = ft_strjoin(FULL, tmp);
	if (RET < BUFF_SIZE && !CURRENT[i + 1])
	{
		ft_strdel(&CURRENT);
		ft_strdel(&FULL);
		ft_strdel(&tmp);
		ft_strdel(TMP);
		return (1);
	}
	CURRENT = ft_memmove(CURRENT, &CURRENT[i + 1], ft_strlen(CURRENT));
	ft_strdel(&tmp);
	//ft_strclr(CURRENT);
	//ft_strdel(TMP);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static t_line	line_p;
	t_line			*line_s;
	char			*tmp;

	if (!line || fd < 0)
		return (err_out(line, fd));
	line_s = init_clr(&line_p);
	if (ft_strchr(CURRENT, '\n'))
		return (format(line_s, line));
	ft_strdel(&FULL);
	FULL = ft_strdup(CURRENT);
	ft_strclr(CURRENT);
	while ((RET = read(fd, CURRENT, BUFF_SIZE)) > 0)
	{
		if (RET < BUFF_SIZE || ft_strchr(CURRENT, '\n'))
			return (format(line_s, line));
		CURRENT[RET] = '\0';
		tmp = ft_strjoin(FULL, CURRENT);
		ft_strdel(&FULL);
		FULL = ft_strdup(tmp);
		ft_strdel(&tmp);
		ft_strclr(CURRENT);
	}
	*line = ft_strdup(FULL);
	ft_strclr(*TMP);
	ft_strdel(&FULL);
	return (RET);
}
/*
int		main(int ac, char **av)
{
	int fd;
	int ret;
	int i;
	char *ptr;

	i = 0;
	if (ac != 2)
		return (0);
	ret = 0;
	fd = open(av[1], O_RDONLY);
	//close(fd);
	while ((ret = get_next_line(fd, &ptr) > 0))
	{
		printf("\n\nline %d |%s|\n\n",  ++i, ptr)
		;
		printf("ret %d\n", ret);
	}
	//get_next_line(fd, &ptr);
	//printf("RET %d final |%s|\n", ret, ptr);
	//ret = get_next_line(fd, &ptr);
	//ret = get_next_line(fd, &ptr);
	printf("|%s|\n", ptr);
	//printf("cmp %d\n", ft_strcmp(ptr, "bbb"));
	//printf("ret %d", ret);
	return (0);
}*/
