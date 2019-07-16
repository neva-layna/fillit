/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlayna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 14:31:01 by nlayna            #+#    #+#             */
/*   Updated: 2019/07/10 14:31:02 by nlayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			ft_tcon(t_etr *tetris)
{
	unsigned char	i;
	unsigned char	j;

	i = 0;
	while ((tetris[i]).letter != 0)
	{
		tetris[i].prev = NULL;
		j = i;
		while (j - 1 >= 0)
		{
			j--;
			if ((tetris[j].value ^ tetris[i].value) == 0LL)
			{
				tetris[i].prev = &(tetris[j]);
				j = 0;
			}
		}
		i++;
	}
}

static void			ft_start(t_etr *tetris)
{
	if (tetris->prev == NULL)
	{
		tetris->y = 0;
		tetris->x = 0;
	}
	else
	{
		tetris->y = tetris->prev->y;
		tetris->x = tetris->prev->x + tetris->width - 1;
	}
}

static int			ft_board(t_etr *tetris,
		unsigned const char size, int16_t *board)
{
	if (tetris->letter == 0)
		return (1);
	ft_start(tetris);
	while (tetris->y + tetris->height <= size)
	{
		while (tetris->x + tetris->width <= size)
		{
			if (!(*(int64_t *)(board + tetris->y) & tetris->value << tetris->x))
			{
				*(int64_t *)(board + tetris->y) ^= tetris->value << tetris->x;
				if (ft_board(tetris + 1, size, board) == 1)
					return (1);
				*(int64_t *)(board + tetris->y) ^= tetris->value << tetris->x;
			}
			(tetris->x)++;
		}
		tetris->x = 0;
		(tetris->y)++;
	}
	return (0);
}

static int			ft_back(t_etr *tetris, t_etr *curr, char letter)
{
	while (letter-- >= 'A')
	{
		curr->x = tetris->x;
		curr->y = tetris->y;
		tetris->x = 0;
		tetris->y = 0;
		curr->width = tetris->width;
		curr->height = tetris->height;
		curr->letter = tetris->letter;
		curr++;
		tetris++;
	}
	return (0);
}

unsigned char		ft_solver(t_etr *tetris, char const letter)
{
	unsigned char	size;
	int16_t			board[16];
	t_etr			*curr;

	size = 13;
	if (!(curr = (t_etr *)malloc(sizeof(t_etr) * (letter - 'A' + 1))))
		return (0);
	ft_bzero(board, sizeof(int16_t) * 16);
	ft_tcon(tetris);
	while (size * size >= ((letter + 1 - 'A') * 4) &&
	ft_board(tetris, size, board) == 1)
	{
		size--;
		ft_bzero(board, sizeof(int16_t) * 16);
		ft_back(tetris, curr, letter);
	}
	ft_back(curr, tetris, letter);
	ft_memdel((void **)&curr);
	return (size + 1);
}
