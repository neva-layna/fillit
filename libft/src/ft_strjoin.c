/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlayna <nlayna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 20:29:47 by nlayna            #+#    #+#             */
/*   Updated: 2019/04/27 19:21:03 by nlayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = ft_strnew(size)))
		return (NULL);
	while (s1[j] != 0)
		str[i++] = s1[j++];
	j = 0;
	while (s2[j] != 0)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
