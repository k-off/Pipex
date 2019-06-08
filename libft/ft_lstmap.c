/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 13:58:27 by tde-jong       #+#    #+#                */
/*   Updated: 2019/02/04 12:39:57 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlist;
	t_list *firstlist;

	if (lst)
	{
		firstlist = f(lst);
		if (firstlist == NULL)
			return (NULL);
		newlist = firstlist;
		while (lst->next != NULL)
		{
			lst = lst->next;
			newlist->next = f(lst);
			if (newlist->next == NULL)
			{
				free(newlist->next);
				return (NULL);
			}
			newlist = newlist->next;
		}
		return (firstlist);
	}
	else
		return (NULL);
}
