/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 18:12:55 by iseletsk          #+#    #+#             */
/*   Updated: 2018/08/21 18:12:57 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	s_unset(char *arg, char ***env)
{
	char	*save_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((*env)[i] && (*env)[j])
	{
		save_str = ft_strdup((*env)[j]);
		j++;
		if (!ft_strncmp(save_str, arg, ft_ltl(save_str, '=')))
		{
			ft_strdel(&save_str);
			continue;
		}
		ft_strdel(&((*env)[i]));
		(*env)[i] = save_str;
		i++;
	}
	while ((*env)[i])
		ft_strdel(&((*env)[i++]));
}

void	ms_unsetenv(char **arg_inp, char ***env)
{
	while (*arg_inp)
		s_unset(*arg_inp++, env);
}
// {
	// char	*save_str;
	// int		i;
	// int		j;
	// int		count;

	// i = 0;
	// count = 0;
	// j = 0;
	// while ((*env)[i] && (*env)[j])
	// {
	// 	save_str = ft_strdup((*env)[j]);
	// 	j++;
	// 	if (!ft_strncmp(save_str, arg_inp[count], ft_ltl(save_str, '=')))
	// 	{
	// 		count++;
	// 		ft_strdel(&save_str);
	// 		continue;
	// 	}
	// 	ft_strdel(&((*env)[i]));
	// 	(*env)[i] = save_str;
	// 	i++;
	// }
	// while ((*env)[i])
	// 	ft_strdel(&((*env)[i++]));
// }