/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 13:05:18 by tde-jong       #+#    #+#                */
/*   Updated: 2019/01/14 14:58:29 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;

	if (s1 && s2)
	{
		str = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (str == NULL)
			return (NULL);
		ft_strcpy(str, s1);
		ft_strcpy(str + ft_strlen(s1), s2);
		return (str);
	}
	else
	{
		return (NULL);
	}
}
