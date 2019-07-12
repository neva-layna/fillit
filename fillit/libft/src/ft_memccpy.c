/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlayna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:08:54 by nlayna            #+#    #+#             */
/*   Updated: 2019/04/07 16:42:05 by nlayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict_dst, const void *restrict_src,
		int c, size_t n)
{
	size_t			i;
	unsigned char	sym;
	int				check;

	i = 0;
	sym = c;
	check = 0;
	if (restrict_src == NULL && n == 0)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)restrict_dst)[i] = ((unsigned char *)restrict_src)[i];
		if (((unsigned char *)restrict_src)[i] == sym)
		{
			((unsigned char *)restrict_dst)[i] =
			((unsigned char *)restrict_src)[i];
			i++;
			check = 1;
			break ;
		}
		i++;
	}
	return ((check == 1) ? restrict_dst + i : NULL);
}
