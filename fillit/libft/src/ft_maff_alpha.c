/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maff_alpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlayna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 16:36:06 by nlayna            #+#    #+#             */
/*   Updated: 2019/04/13 16:40:01 by nlayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_maff_alpha(void)
{
	char aff;

	aff = 'a';
	while (aff <= 'z')
	{
		if (aff % 2 == 0)
			ft_putchar(aff - 32);
		else if (aff % 2 != 0)
			ft_putchar(aff);
		aff++;
	}
	ft_putchar('\n');
}
