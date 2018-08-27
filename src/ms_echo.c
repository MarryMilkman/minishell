/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 17:47:03 by iseletsk          #+#    #+#             */
/*   Updated: 2018/07/22 14:40:47 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ms_echo(char **arg_inp)
{
	int	i;

	i = 0;
	while (arg_inp[++i])
	{
		ft_putstr(arg_inp[i]);
		if (arg_inp[i + 1])
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}
