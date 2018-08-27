/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 14:08:43 by iseletsk          #+#    #+#             */
/*   Updated: 2018/07/20 14:09:41 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		main(int ac, char **av, char **env)
{
	char	*str;

	env = ms_cpy_environ(env);
	str = 0;
	while (1)
	{
		write(1, "$> ", 3);
		ft_read_output(&str);
		if (!str)
		{
			write(1, "\n", 1);
			ms_exit(0);
		}
		ms_hendl_command(str, &env);
		system("leaks minishell");
		ft_strdel(&str);
	}
	return (0);
}








// {
// 	pid_t	father;
// 	if (ac == 1)
// 		return (0);
// 	father = fork();
// 	if (father == 0)
// 	{
// 		sleep(5);
// 		execve("/bin/cd", av, 0);
// 		printf("xcvgytrd\n");
// 	}
// 	if (father > 0)
// 	{
// 		wait(&father);
// 		printf("Im yor father\n");
// 	}
// 	return(0);
// }
