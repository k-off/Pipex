/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrev.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 15:38:55 by tde-jong       #+#    #+#                */
/*   Updated: 2019/01/16 10:44:34 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*ret;
	int		len;
	int		i;

	len = ft_strlen(str);
	ret = ft_memalloc(len + 1);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[len - 1 - i] = str[i];
		i++;
	}
	return (ret);
}
