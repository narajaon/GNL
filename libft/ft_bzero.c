/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:06:16 by narajaon          #+#    #+#             */
/*   Updated: 2017/04/24 12:22:08 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*s_;
	size_t	i;

	if (n == 0)
		return ;
	s_ = s;
	i = 0;
	while (i < n)
	{
		s_[i] = 0;
		i++;
	}
}
