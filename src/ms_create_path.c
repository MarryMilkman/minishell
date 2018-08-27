/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_create_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 19:22:53 by iseletsk          #+#    #+#             */
/*   Updated: 2018/07/22 19:22:54 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ms_create_path(char **env)
{
	char	**path;
	int		i;

	i = 0;
	if (!*env)
		return (0);
	while (env[i] && (env[i][0] != 'P' || env[i][1] != 'A' ||
			env[i][2] != 'T' || env[i][3] != 'H'))
		i++;
	if (!env[i])
		return (0);
	path = ft_strsplit(env[i] + 5, ':');
	return (path);
}