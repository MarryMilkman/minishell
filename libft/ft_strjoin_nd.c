/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_md.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 20:22:08 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/04 16:23:29 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_nd(char *s1, const char *sepa, char *s2)
{
	char	*rbox;
	char	*h_str;

	if (!s1 && s2 && (rbox = ft_strdup(s2)))
		return (rbox);
	if (s1 && !s2 && (rbox = ft_strdup(s1)))
		return (rbox);
	if (!s1 && !s2)
		return (0);
	if (sepa && *sepa)
		rbox = ft_strjoin(s1, sepa);
	else
		rbox = ft_strdup(s1);
	h_str = ft_strdup(rbox);
	ft_strdel(&rbox);
	rbox = ft_strjoin(h_str, s2);
	ft_strdel(&h_str);
	return (rbox);
}
