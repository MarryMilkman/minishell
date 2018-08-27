/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cpy_environ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:13:58 by iseletsk          #+#    #+#             */
/*   Updated: 2018/07/22 17:14:02 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ms_cpy_environ(char **env)
{
	extern char **environ;
	char		**new_env;
	int			i;

	i = 0;
	if (env)
		environ = env;
	while (environ[i])
		i++;
	new_env = malloc(sizeof(char *) * (1 + i));
	i = -1;
	while (environ[++i])
		new_env[i] = ft_strdup(environ[i]);
	new_env[i] = 0;
	return (new_env);
}