/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlayna <nlayna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 22:48:46 by nlayna            #+#    #+#             */
/*   Updated: 2019/05/22 14:52:37 by nlayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdint.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct		s_etr
{
	char			letter;
	unsigned char	width;
	unsigned char	height;
	unsigned char	x;
	unsigned char	y;
	uint64_t		value;
	struct s_etr	*prev;
}					t_etr;

char				ft_reader(int const fd, t_etr *tetris);
unsigned char		ft_solver(t_etr *tetris, char const letter);

#endif
