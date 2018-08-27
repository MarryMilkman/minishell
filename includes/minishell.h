/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 17:43:57 by iseletsk          #+#    #+#             */
/*   Updated: 2018/07/24 18:14:49 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "dirent.h"
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <unistd.h>
# include <stdio.h>

void	ms_echo(char **arg);
void	ms_hendl_command(char *str, char ***env);
char	**ms_pars_input(char *str);
char	**ms_cut_str_into_arg(char *str);
void	ms_hendl_integrated_command(char **arg_inp, char ***env);
void	ms_exit(char **arg_inp);
void	ms_print_error(char *s1, char *s2, char *s3);
void	ms_del_arg_inp(char ***b_arg);
void	ms_cd(char **arg);
char	**ms_cpy_environ(char **env);
void	ms_env(char **arg, char **env);
void	ms_hendl_general_command(char **arg, char **env);
char	**ms_create_path(char **env);
void	ms_setenv(char **arg, char ***env);
void	ms_unsetenv(char **arg, char ***env);

#endif
