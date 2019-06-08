/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 15:00:12 by tde-jong       #+#    #+#                */
/*   Updated: 2019/01/23 09:29:16 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	len;
	char	*str;
	int		loc;

	loc = -1;
	str = (char *)s;
	len = ft_strlen(str);
	i = 0;
	while (i <= len)
	{
		if (str[i] == (char)c)
		{
			loc = i;
		}
		i++;
	}
	if (loc == -1)
	{
		return (NULL);
	}
	else
	{
		return (str + loc);
	}
}
