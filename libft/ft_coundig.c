/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coundig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:42:21 by iseletsk          #+#    #+#             */
/*   Updated: 2018/03/23 14:22:25 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_coundig(int nb)
{
	int	count;

	count = 1;
	if (nb < 0)
		count++;
	while ((nb /= 10))
		count++;
	return (count);
}