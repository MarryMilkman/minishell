/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 22:50:03 by iseletsk          #+#    #+#             */
/*   Updated: 2018/03/24 17:00:25 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	void	*sbox;

	sbox = s;
	while (n != 0)
	{
		*((unsigned char *)s) = 0;
		s++;
		n--;
	}
	return (sbox);
}
