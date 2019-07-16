/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlayna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 04:14:55 by nlayna            #+#    #+#             */
/*   Updated: 2019/07/15 17:58:51 by nlayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*ft_strcreate(size_t size, char sym)
{
	char		*str;
	size_t		i;

	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	else
	{
		i = 0;
		while (i < size)
			str[i++] = sym;
		str[i] = 0;
		return (str);
	}
}

static void	ft_print(t_etr *tet, char letter, unsigned char const size)
{
	char			*board;
	uint32_t		y;
	uint32_t		x;

	board = ft_strcreate(size * (size + 1), '.');
	while ((y = 0) || letter-- >= 'A')
	{
		while (y < tet->height)
		{
			x = 0;
			while (x < tet->width)
			{
				if ((tet->value >> (16 * y + x)) & 1LL)
					board[(tet->y + y) * (size + 1) + tet->x + x] = tet->letter;
				x++;
			}
			y++;
		}
		tet++;
	}
	y = 0;
	while (y < size)
		board[y++ * (size + 1) + size] = '\n';
	ft_putstr(board);
	ft_strdel(&board);
}

static int	ft_err(char *str)
{
	ft_putendl(str);
	return (0);
}

int			main(int ac, char **av)
{
	char			letter;
	t_etr			tetris[27];
	unsigned char	size;

	if (ac != 2)
		return (ft_err("usage : ./fillit source_file"));
	ft_bzero(tetris, sizeof(t_etr) * 27);
	if (!(letter = ft_reader(open(av[1], O_RDONLY), tetris)))
		return (ft_err("error"));
	if (!(size = ft_solver(tetris, letter)))
		return (ft_err("error"));
	ft_print(tetris, letter, size);
	return (0);
}
