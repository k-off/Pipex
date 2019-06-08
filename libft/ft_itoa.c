/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 15:51:11 by tde-jong       #+#    #+#                */
/*   Updated: 2019/02/18 14:07:40 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_intlen(n);
	str = ft_memalloc(len + 1);
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
		i += 1;
	}
	while (i < len)
	{
		len--;
		str[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
