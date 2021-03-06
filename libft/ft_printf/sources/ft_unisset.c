/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unisset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:41:03 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/02 19:08:40 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_unisset(wchar_t *dest, int c, size_t len)
{
	size_t	i;

	i = 0;
	if (!dest)
		return ;
	while (i < len)
		dest[i++] = c;
}
