/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strequ.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 12:34:27 by tde-jong       #+#    #+#                */
/*   Updated: 2019/01/14 14:30:47 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
	{
		if (ft_strlen(s1) != ft_strlen(s2))
			return (0);
		if ((ft_strcmp(s1, s2) == 0))
			return (1);
	}
	return (0);
}
