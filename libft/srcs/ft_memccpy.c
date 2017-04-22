/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:11:04 by narajaon          #+#    #+#             */
/*   Updated: 2017/04/22 11:18:24 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;
	char		*str;
	const char	*str2;

	i = 0;
	str = dest;
	str2 = src;
	while (i < n)
	{
		if (str2[i] == c)
		{
			str[i] = str2[i];
			return (dest + i + 1);
		}
		str[i] = str2[i];
		i++;
	}
	return (NULL);
}
