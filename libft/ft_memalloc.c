/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 09:57:04 by narajaon          #+#    #+#             */
/*   Updated: 2017/04/24 12:22:28 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;
	size_t	i;

	i = 0;
	if (!(mem = (void *)malloc(sizeof(void) * (size))))
		return (NULL);
	while (i < size)
		*((char*)mem + i++) = 0;
	return (mem);
}
