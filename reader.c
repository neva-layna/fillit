/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlayna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 13:49:41 by nlayna            #+#    #+#             */
/*   Updated: 2019/07/15 18:11:09 by nlayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_area(char const *str, unsigned char *area)
{
	unsigned char	i;

	i = 0;
	area[0] = 3;
	area[1] = 0;
	area[2] = 3;
	area[3] = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i % 5 < area[0])
				area[0] = i % 5;
			if (i % 5 > area[1])
				area[1] = i % 5;
			if (i / 5 < area[2])
				area[2] = i / 5;
			if (i / 5 > area[3])
				area[3] = i / 5;
		}
		i++;
	}
}

static t_etr	*ft_gett(t_etr *tetris, char const *str, char const letter)
{
	int				x;
	int				y;
	unsigned char	area[4];

	ft_area(str, area);
	tetris->letter = letter;
	tetris->width = area[1] - area[0] + 1;
	tetris->height = area[3] - area[2] + 1;
	tetris->value = 0LL;
	y = 0;
	while (y < tetris->height)
	{
		x = 0;
		while (x < tetris->width)
		{
			if (str[5 * (area[2] + y) + (area[0] + x)] == '#')
				tetris->value |= 1LL << (16 * y + x);
			x++;
		}
		y++;
	}
	return (tetris);
}

static int		ft_connect(const char *str)
{
	int	block;
	int	i;

	block = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				block++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				block++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				block++;
		}
		i++;
	}
	return (block == 6 || block == 8);
}

static int		ft_valid(const char *str, const int count)
{
	int	i;
	int	block;

	block = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 != 4)
		{
			if (str[i] == '#')
				block++;
			if (str[i] != '.' && str[i] != '#')
				return (0);
		}
		else if (str[i] != '\n')
			return (0);
		i++;
	}
	if (count == 21 && str[20] != '\n')
		return (0);
	if (!ft_connect(str) || block != 4)
		return (0);
	return ((count == 21) ? 1 : 2);
}

char			ft_reader(const int fd, t_etr *tetris)
{
	char	buf[21];
	int		count;
	char	letter;
	char	end;

	letter = 'A';
	while ((count = read(fd, buf, 21)) >= 20)
	{
		if (letter - 'A' >= 26
		|| (end = ft_valid((const char *)buf, count)) == 0)
			return (0);
		if (!(ft_gett(tetris++, (const char *)buf, (const char)letter)))
			return (0);
		letter++;
	}
	if (count != 0)
		return (0);
	else
		return ((letter > 'A' && end == 2) ? letter - 1 : 0);
}
