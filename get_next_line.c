/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:55:38 by narajaon          #+#    #+#             */
/*   Updated: 2017/04/24 16:07:29 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	**formated(char *str)
{
	int		i;
	char	**tab;

	i = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * 2)))
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
		{
			tab[1] = ft_strdup(str + i + 1);
			str[i] = '\0';
		}
		i++;
	}
	tab[0] = ft_strdup(str);
	return (tab);
}

char	*get_line(const int fd, char **line)
{
	char		*str;
	char		*str2;
	static char	*str3;
	char **tab;

	str = ft_strnew(BUFF_SIZE);
	str2 = ft_strnew(BUFF_SIZE);
	while (read(fd, str2, BUFF_SIZE) && !ft_strchr(str2, '\n'))
	{
		if (str3)
		{
			str = ft_strjoin(str3, str);
			ft_strdel(&str3);
		}
		str = ft_strjoin(str, str2);
		ft_strdel(&str2);
		str2 = ft_strnew(BUFF_SIZE);
	}
	str = ft_strjoin(str, formated(str2)[0]);
	str3 = formated(str2)[1];
	ft_strdel(&str2);
	return (str);
}

int		main(int ac, char **av)
{
	int fd;
	char *buff;
	char *ptr;

	buff = ft_strnew(BUFF_SIZE);
	fd = open(av[1], O_RDONLY);
	printf("%s\n", get_line(fd, &ptr));
	printf("%s\n", get_line(fd, &ptr));
	return (0);
}
