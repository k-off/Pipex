/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsub.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 12:54:59 by tde-jong       #+#    #+#                */
/*   Updated: 2019/03/04 14:27:46 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *str;

	if (s)
	{
		str = ft_strnew(len);
		if (str == NULL)
			return (NULL);
		str = ft_strncpy(str, s + start, len);
		return (str);
	}
	else
	{
		return (NULL);
	}
}
