/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlayna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 16:42:03 by nlayna            #+#    #+#             */
/*   Updated: 2019/04/13 16:47:48 by nlayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_bits(unsigned char octet)
{
	char	bits[8];
	int		num;
	int		count;
	char	z;

	num = octet;
	count = 0;
	while (count < 8)
	{
		bits[count] = num % 2;
		num = num / 2;
		count++;
	}
	while (count - 1 >= 0)
	{
		z = bits[count - 1] + 48;
		ft_putchar(z);
		count--;
	}
}
