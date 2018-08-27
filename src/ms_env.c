/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:32:35 by iseletsk          #+#    #+#             */
/*   Updated: 2018/07/22 17:32:39 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ms_env(char **arg, char **env)
{
	if (arg[1])
	{
		ms_print_error(arg[1], "illigal", 0);
		return ;
	}
	while (*env)
		ft_putendl(*env++);
}
