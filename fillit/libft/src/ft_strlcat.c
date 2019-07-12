/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlayna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:07:18 by nlayna            #+#    #+#             */
/*   Updated: 2019/04/06 18:27:57 by nlayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict_dst, const char *restrict_src, size_t size)
{
	size_t i;
	size_t j;
	size_t dest_size;
	size_t src_size;

	i = 0;
	j = 0;
	dest_size = ft_strlen(restrict_dst);
	src_size = ft_strlen(restrict_src);
	if (size <= dest_size)
		return (src_size + size);
	while (restrict_dst[i] && i < (size - 1))
		i++;
	while (restrict_src[j] && i < (size - 1))
	{
		restrict_dst[i] = restrict_src[j];
		i++;
		j++;
	}
	restrict_dst[i] = '\0';
	return (dest_size + src_size);
}
