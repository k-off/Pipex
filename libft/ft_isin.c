/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isin.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/21 09:27:07 by tde-jong       #+#    #+#                */
/*   Updated: 2019/02/21 09:33:40 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_isin(char c, char *str)
{
	ssize_t i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
