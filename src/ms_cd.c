/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:34:48 by iseletsk          #+#    #+#             */
/*   Updated: 2018/07/22 15:34:51 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ms_cd(char **arg)
{
	if (!arg[1])
	{
		chdir("/");
		return ;
	}
	if (arg[1] && arg[2])
	{
		ms_print_error("string not in pwd", arg[1], 0);
		return ;
	}
	if (chdir(arg[1]) == -1)
	{
		ms_print_error("something not right", arg[1], 0);
		return ;
	}
}