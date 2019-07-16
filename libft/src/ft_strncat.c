/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlayna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:07:11 by nlayna            #+#    #+#             */
/*   Updated: 2019/04/06 18:27:07 by nlayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict_s1, const char *restrict_s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (restrict_s1[i])
		i++;
	while (restrict_s2[j] && j < n)
	{
		restrict_s1[i] = restrict_s2[j];
		i++;
		j++;
	}
	restrict_s1[i] = '\0';
	return (restrict_s1);
}
