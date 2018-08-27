/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_hendl_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 16:37:46 by iseletsk          #+#    #+#             */
/*   Updated: 2018/07/20 16:37:55 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	***s_create_command(char *str)
{
	char	***r_box;
	int		size;
	char	**split_str;
	int		i;

	size = ft_count_c(str, ';') + 1 ;
	r_box = malloc(sizeof(char **) * (size + 1));
	if (size == 1)
	{
		r_box[0] = ms_pars_input(str);
		r_box[1] = 0;
		return (r_box);
	}
	split_str = ft_strsplit(str, ';');
	i = -1;
	while (++i < size && split_str[i])
		r_box[i] = ms_pars_input(split_str[i]);
	r_box[i] = 0;
	i = -1;
	while (split_str[++i])
		ft_strdel(&(split_str[i]));
	free(split_str);
	return (r_box);
}

void	ms_hendl_command(char *str, char ***env)
{
	char	**arg_inp;
	char	***comm_inp;
	int		i;

	comm_inp = s_create_command(str);
	if (!comm_inp)
		return ;
	i = -1;
	while ((arg_inp = comm_inp[++i]))
	{
		if (!*arg_inp)
		{
			ms_del_arg_inp(&arg_inp);
			continue;
		}
		if (!ft_strcmp("unsetenv", arg_inp[0]) || !ft_strcmp("cd", arg_inp[0]) ||
			!ft_strcmp("setenv", arg_inp[0]) || !ft_strcmp("echo", arg_inp[0]) ||
			!ft_strcmp("env", arg_inp[0]) || !ft_strcmp("exit", arg_inp[0]))
			ms_hendl_integrated_command(arg_inp, env);
		else if (*arg_inp)
			ms_hendl_general_command(arg_inp, *env);
		ms_del_arg_inp(&arg_inp);
	}
	free(comm_inp);
}