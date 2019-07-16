/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlayna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:07:02 by nlayna            #+#    #+#             */
/*   Updated: 2019/04/06 18:26:15 by nlayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict_s1, const char *restrict_s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (restrict_s1[i])
		i++;
	while (restrict_s2[j])
	{
		restrict_s1[i] = restrict_s2[j];
		i++;
		j++;
	}
	restrict_s1[i] = '\0';
	return (restrict_s1);
}
