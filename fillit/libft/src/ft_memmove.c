/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlayna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:08:37 by nlayna            #+#    #+#             */
/*   Updated: 2019/04/07 17:27:23 by nlayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dststr;
	char		*srcstr;

	i = -1;
	dststr = (char *)dst;
	srcstr = (char *)src;
	if (srcstr < dststr)
		while ((int)--len >= 0)
			*(dststr + len) = *(srcstr + len);
	else
		while (++i < len)
			*(dststr + i) = *(srcstr + i);
	return (dst);
}
