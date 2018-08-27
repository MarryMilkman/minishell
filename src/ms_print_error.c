/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 14:41:45 by iseletsk          #+#    #+#             */
/*   Updated: 2018/07/22 14:41:52 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ms_print_error(char *s1, char *s2, char *s3)
{
	write(2, "minishel: ", ft_strlen("minishel: "));
	if (s1)
		write(2, s1, ft_strlen(s1));
	if (s2)
	{
		write(2, ": ", 2);
		write(2, s2, ft_strlen(s2));
	}
	if (s3)
	{
		write(2, ": ", 2);
		write(2, s3, ft_strlen(s3));
	}
	write(2, "\n", 1);
}