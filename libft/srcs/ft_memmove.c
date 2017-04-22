/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 09:57:32 by narajaon          #+#    #+#             */
/*   Updated: 2017/04/22 11:18:53 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*ptr;
	unsigned char		*ptr2;

	ptr = dst;
	ptr2 = (unsigned char *)src;
	if (dst > src)
	{
		while (len--)
			ptr[len] = ptr2[len];
	}
	else
	{
		while (len--)
			*ptr++ = *ptr2++;
	}
	return (dst);
}
