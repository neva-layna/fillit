/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlayna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:03:26 by nlayna            #+#    #+#             */
/*   Updated: 2019/04/13 17:10:32 by nlayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_chr(char *str, int c)
{
	unsigned long i;
	unsigned char sym;

	i = 0;
	sym = c;
	while (str[i] && str[i] != sym)
		i++;
	return (i);
}
