/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 14:52:04 by narajaon          #+#    #+#             */
/*   Updated: 2017/04/25 18:25:51 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strtrimc(char const *s, char c)
{
	char	*str;
	char	*ptr;
	int		i;
	int		i_2;

	i = 0;
	i_2 = 0;
	if (!*s)
		return ((char *)s);
	ptr = (char *)s;
	while ((*ptr == c) && *ptr)
		ptr++;
	if (!*ptr)
		return (ptr);
	while (ptr[i])
		i++;
	i--;
	while ((ptr[i] == c) && ptr[i])
		i--;
	if (!(str = ft_strnew(i - i_2 + 1)))
		return (NULL);
	while (i_2++ <= i)
		str[i_2 - 1] = ptr[i_2 - 1];
	return (str);
}
