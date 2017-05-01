/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:46:42 by narajaon          #+#    #+#             */
/*   Updated: 2017/04/24 12:23:04 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	char	*ptr;
	int		i;

	i = 0;
	if (!(str = ft_strnew(ft_strlen(s))))
		return (NULL);
	ptr = (char *)s;
	while (ptr[i])
	{
		str[i] = f(i, ptr[i]);
		i++;
	}
	return (str);
}
