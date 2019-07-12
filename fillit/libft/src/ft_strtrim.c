/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlayna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:42:21 by nlayna            #+#    #+#             */
/*   Updated: 2019/04/08 13:42:22 by nlayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while ((s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
		&& (len != i))
		len--;
	len = len - i;
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	j = -1;
	while (++j < len)
		str[j] = s[i++];
	str[j] = '\0';
	return (str);
}
