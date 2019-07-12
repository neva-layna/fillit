/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlayna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:50:08 by nlayna            #+#    #+#             */
/*   Updated: 2019/04/08 16:50:09 by nlayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstfree(t_list *lst)
{
	while (lst->next)
	{
		free(lst->next);
		lst->next = NULL;
	}
	free(lst);
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlst;
	t_list *temp;

	if (!(lst))
		return (NULL);
	newlst = f(lst);
	temp = newlst;
	while (lst->next)
	{
		lst = lst->next;
		if (!(newlst->next = f(lst)))
		{
			free(newlst->next);
			return (ft_lstfree(lst));
		}
		newlst = newlst->next;
	}
	return (temp);
}
