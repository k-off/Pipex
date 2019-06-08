/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 10:10:14 by tde-jong      #+#    #+#                 */
/*   Updated: 2019/01/10 10:23:02 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t size;
	size_t i;

	size = ft_strlen(src);
	i = 0;
	while (i < len)
	{
		if (i >= size)
		{
			dst[i] = '\0';
		}
		else
		{
			dst[i] = src[i];
		}
		i++;
	}
	return (dst);
}
