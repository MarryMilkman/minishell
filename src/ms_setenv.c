/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 18:18:05 by iseletsk          #+#    #+#             */
/*   Updated: 2018/07/24 18:18:08 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	**s_add_param(char **arg, char ***env, int size)
{
	int		i;
	char	**n_env;

	n_env = malloc(sizeof(char *) * (size + 1));
	i = -1;
	while ((*env)[++i])
	{
		n_env[i] = ft_strdup((*env)[i]);
		ft_strdel(&((*env)[i]));
	}
	free(*env);
	*env = 0;
	arg++;
	while (*arg)
	{
		if (ft_count_c(*arg, '='))
			n_env[i++] = ft_strdup(*arg);
		arg++;
	}
	n_env[i] = 0;
	return (n_env);
}

static int	s_check_valid(char *str)
{
	char	i;

	if (ft_count_c(str, '='))
	{
		if (*str == '=')
		{
			ms_print_error("setenv", str, "not a valid identifier");
			return (0);
		}
	}
	return (1);
}

void	ms_setenv(char **arg, char ***env)
{
	int		i;
	int		j;
	int		size;
	char	*(null_term_arg)[2];

	i = 1;
	null_term_arg[0] = 0;
	null_term_arg[1] = 0;
	while (arg[i])
		if (!s_check_valid(arg[i++]))
			return ;
	size += i - 1;
	i = -1;
	while ((*env)[++i])
	{
		j = 0;
		while (arg[++j])
			if (!ft_strncmp(arg[j], null_term_arg[0] = (*env)[i],
					ft_ltl(arg[j], '=') + 1))
				ms_unsetenv((char **)null_term_arg, env);
		if (ft_count_c(arg[j], '='))
			size++;
	}
	*env = s_add_param(arg, env, size);
}