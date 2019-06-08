/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/15 15:32:11 by tde-jong       #+#    #+#                */
/*   Updated: 2019/02/18 18:16:03 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(intmax_t n)
{
	if (n < 0)
		return (ft_intlen(-n) + 1);
	if (n >= 10)
		return (ft_intlen(n / 10) + 1);
	return (1);
}
