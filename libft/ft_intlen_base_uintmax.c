/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intlen_base_uintmax.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/15 15:32:11 by tde-jong       #+#    #+#                */
/*   Updated: 2019/02/18 16:57:07 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen_base_uintmax(uintmax_t n, unsigned char base)
{
	if (n >= base)
		return (ft_intlen_base_uintmax(n / base, base) + 1);
	return (1);
}
