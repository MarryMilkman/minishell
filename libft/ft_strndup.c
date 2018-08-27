/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 12:46:59 by iseletsk          #+#    #+#             */
/*   Updated: 2018/07/22 12:49:03 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, int n)
{
	char	*b_str;
	char	*r_str;

	if (!str)
		return (0);
	b_str = malloc(sizeof(char) * (n + 1));
	r_str = b_str;
	while (*str && n--)
		*b_str++ = *str++;
	*b_str = 0;
	return (r_str);
}
