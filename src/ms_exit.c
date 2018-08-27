/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 14:22:17 by iseletsk          #+#    #+#             */
/*   Updated: 2018/07/22 14:22:18 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	s_exit(int nbr)
{
	write(1, "exit\n", 5);
	exit(nbr);	
}

void	ms_exit(char **arg)
{
	int		nbr;
	char	*d_str;

	if (!arg)
		s_exit(0);
	if (arg[1] && !arg[2])
	{
		nbr = ft_atoi(arg[1]);
		d_str = ft_itoa(nbr);
		if (ft_strcmp(arg[1], d_str))
		{
			ft_strdel(&d_str);
			ms_print_error(arg[0], arg[1], "numeric argument required");
			return ;
		}
		s_exit(nbr);
	}
	if (arg[1] && arg[2])
	{
		ms_print_error(arg[0], "too many arguments", 0);
		return ;
	}
	s_exit(0);
}
