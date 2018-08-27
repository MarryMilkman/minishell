/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lower.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 19:03:23 by iseletsk          #+#    #+#             */
/*   Updated: 2018/03/22 19:04:34 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tolower(int c)
{
	if (!ft_isalpha(c))
		return (c);
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}