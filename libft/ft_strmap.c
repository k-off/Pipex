/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 11:28:35 by tde-jong       #+#    #+#                */
/*   Updated: 2019/01/14 14:18:40 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	if (s)
	{
		str = ft_strdup(s);
		if (str == NULL)
			return (NULL);
		i = 0;
		while (s[i] != '\0')
		{
			str[i] = f(s[i]);
			i++;
		}
		return (str);
	}
	else
	{
		return (NULL);
	}
}
