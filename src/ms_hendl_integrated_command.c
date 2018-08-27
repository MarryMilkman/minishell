/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_hendl_integrated_command.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 14:06:25 by iseletsk          #+#    #+#             */
/*   Updated: 2018/07/22 14:06:27 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ms_hendl_integrated_command(char **arg_inp, char ***env)
{
	if (!ft_strcmp("echo", *arg_inp))
		ms_echo(arg_inp);
	if (!ft_strcmp("exit", *arg_inp))
		ms_exit(arg_inp);
	if (!ft_strcmp("cd", *arg_inp))
	 	ms_cd(arg_inp);
	if (!ft_strcmp("env", *arg_inp))
	 	ms_env(arg_inp, *env);
	if (!ft_strcmp("setenv", *arg_inp))
		ms_setenv(arg_inp, env);
	if (!ft_strcmp("unsetenv", *arg_inp))
		ms_unsetenv(arg_inp, env);
}