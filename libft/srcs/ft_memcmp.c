/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 11:21:10 by narajaon          #+#    #+#             */
/*   Updated: 2017/04/22 11:18:36 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *ptr;
	unsigned char *ptr2;

	ptr = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (n)
	{
		if (*ptr2 - *ptr)
			return (*ptr - *ptr2);
		ptr++;
		ptr2++;
		n--;
	}
	return (0);
}
