/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 11:42:42 by tde-jong       #+#    #+#                */
/*   Updated: 2019/01/14 14:25:31 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	if (s)
	{
		str = ft_strdup(s);
		if (str == NULL)
			return (NULL);
		i = 0;
		while (str[i] != '\0')
		{
			str[i] = f(i, str[i]);
			i++;
		}
		return (str);
	}
	else
	{
		return (NULL);
	}
}
