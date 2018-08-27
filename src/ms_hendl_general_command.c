/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_hendl_general_command.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 19:01:19 by iseletsk          #+#    #+#             */
/*   Updated: 2018/07/22 19:01:21 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	s_fork_and_carry(char *str, char **arg, char **env)
{
	pid_t	father;

	father = fork();
	if (father == 0)
		execve(str, arg, env);
	if (father > 0)
		wait(&father);
}

static char *s_find_valid_path(char **arg, char **env)
{
	char	*path;
	char	**path_arg;
	int		i;

	if (arg[0] && ((ft_strlen(arg[0]) >= 2 && (arg[0][0] == '.' 
		&& arg[0][1] == '/')) || (ft_strlen(arg[0]) >= 3 && arg[0][0] == '.' 
			&& arg[0][1] == '.' && arg[0][2] == '/')))
		return (0);
	path_arg = ms_create_path(env);
	if (!path_arg)
		return (0);
	path = 0;
	i = -1;
	while (path_arg[++i] && access(path, X_OK))
	{
		ft_strdel(&path);
		path = ft_strjoin_nd(path_arg[i], "/" , arg[0]);
		ft_strdel(&(path_arg[i]));
	}
	while (path_arg[i])
		ft_strdel(&(path_arg[i++]));
	free(path_arg);
	if (!access(path, X_OK))
		return (path);
	ft_strdel(&path);
	return (0);
}

void	ms_hendl_general_command(char **arg, char **env)
{
	char	*path;

	path = s_find_valid_path(arg, env);
	if (path)
	{
		s_fork_and_carry(path, arg, env);
		ft_strdel(&path);
	}
	else if (!access(arg[0], X_OK))
		s_fork_and_carry(arg[0], arg, env);
	else if (!access(arg[0], 0) && access(arg[0], X_OK))
	{
		ms_print_error("permission denied", arg[0], 0);
		return ;
	}
	else
		ms_print_error("invalid command", arg[0], 0);
}

// void	ms_hendl_general_command(char **arg, char **env)
// {
// 	char	*path;

// 	if (!access(arg[0], X_OK))
// 	{
// 		s_fork_and_carry(arg[0], arg, env);
// 	}
// 	else if (!access(arg[0], 0) && access(arg[0], X_OK))
// 	{
// 		ms_print_error("permission denied", arg[0], 0);
// 		return ;
// 	}
// 	else
// 	{
// 		printf("cho u nas tut 2222?\n");
// 		path = s_find_valid_path(arg, env);
// 		if (!path)
// 		{
// 			ms_print_error("invalid command", arg[0], 0);
// 			return ;
// 		}
// 		s_fork_and_carry(path, arg, env);
// 		ft_strdel(&path);
// 	}
// }