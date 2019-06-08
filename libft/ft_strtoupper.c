/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtoupper.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/18 18:17:46 by tde-jong       #+#    #+#                */
/*   Updated: 2019/02/18 18:21:13 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtoupper(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_islower(str[i]))
			str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}
