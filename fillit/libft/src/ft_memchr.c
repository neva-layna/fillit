/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlayna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:08:28 by nlayna            #+#    #+#             */
/*   Updated: 2019/04/06 18:24:30 by nlayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	sym;

	i = 0;
	sym = c;
	while (n--)
	{
		if (((unsigned char *)s)[i] == sym)
			return ((unsigned char *)s + i);
		i++;
	}
	return (NULL);
}
