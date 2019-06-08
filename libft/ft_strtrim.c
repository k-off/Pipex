/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 14:18:54 by tde-jong       #+#    #+#                */
/*   Updated: 2019/01/14 15:00:58 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhitespace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	char *str;

	if (s)
	{
		str = ft_strdup(s);
		if (str == NULL)
			return (NULL);
		while (*str != '\0' && ft_iswhitespace(*str))
		{
			str++;
		}
		str = ft_strrev(str);
		while (*str != '\0' && ft_iswhitespace(*str))
		{
			str++;
		}
		return (ft_strrev(str));
	}
	else
	{
		return (NULL);
	}
}
