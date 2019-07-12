/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlayna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:28:20 by nlayna            #+#    #+#             */
/*   Updated: 2019/04/08 15:59:13 by nlayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_words_count(char const *s, char c)
{
	int count;
	int check;

	count = 0;
	check = 0;
	while (*s)
	{
		if (check == 1 && *s == c)
			check = 0;
		if (check == 0 && *s != c)
		{
			check = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static size_t	ft_alph_count(char const *s, char c)
{
	int count;

	count = 0;
	while (*s != c && *s)
	{
		count++;
		s++;
	}
	return (count);
}

static	char	**str_free(char **str, int i)
{
	while (str[i--])
	{
		free(str[i]);
		str[i] = NULL;
	}
	free(str);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**words;
	int		i;
	size_t	wordc;

	if (s == NULL)
		return (NULL);
	wordc = ft_words_count(s, c);
	if (!(words = (char **)malloc(sizeof(char *) * wordc + 1)) && s == NULL)
		return (NULL);
	i = 0;
	if (!words)
		return (NULL);
	while (wordc--)
	{
		while (*s == c && *s)
			s++;
		if (!(words[i] = ft_strsub(s, 0, ft_alph_count(s, c))))
			return (str_free(words, i));
		s = s + ft_alph_count(s, c);
		i++;
	}
	words[i] = 0;
	return (words);
}
