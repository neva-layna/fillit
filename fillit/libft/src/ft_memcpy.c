/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlayna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:08:44 by nlayna            #+#    #+#             */
/*   Updated: 2019/04/06 18:24:54 by nlayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict_dst, const void *restrict_src, size_t n)
{
	char	*dststr;
	char	*srcstr;
	size_t	i;

	i = 0;
	srcstr = (char *)restrict_src;
	dststr = (char *)restrict_dst;
	if (srcstr > dststr)
		return (ft_memmove(restrict_dst, restrict_src, n));
	else
		while (i < n)
		{
			dststr[i] = srcstr[i];
			i++;
		}
	return (dststr);
}
