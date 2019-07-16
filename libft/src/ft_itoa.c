/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlayna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 13:38:57 by nlayna            #+#    #+#             */
/*   Updated: 2019/04/07 18:34:02 by nlayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		num_size(int n)
{
	int size;

	size = (n < 0) ? 2 : 1;
	while (n != 0)
	{
		if (n < 0)
			n *= -1;
		n = n / 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		minus;

	minus = 0;
	size = num_size(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n *= -1;
		minus = 1;
	}
	if ((str = (char *)malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	str[--size] = n != 0 ? '\0' : n % 10 + 48;
	while (size--)
	{
		str[size] = n % 10 + 48;
		n = n / 10;
	}
	if (minus == 1)
		str[0] = '-';
	return (str);
}
