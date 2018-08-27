/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pars_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 18:57:57 by iseletsk          #+#    #+#             */
/*   Updated: 2018/07/20 18:57:58 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char *s_catch_quote(char *str)
{
	int		i;
	char	c;
	char	*buf;

	i = -1;
	c = 0;
	while (i == -1 || (c && !(buf = 0)))
	{
		while (str[++i])
		{
			if ((str[i] == '"' || str[i] == '\'') && !c && (c = str[i]))
				continue;
			if (str[i] == c)
				c = 0;
		}
		if (c)
		{
			write(1, "dquote> ", 8);
			ft_read_output(&buf);
			str = ft_strjoin_md(str, "\n", buf);
		}
	}
	return (str);
}

char		**ms_pars_input(char *str)
{
	char	**arg_inp;
	char	*valid_str;

	arg_inp = 0;
	valid_str = s_catch_quote(ft_strdup(str));
	arg_inp = ms_cut_str_into_arg(valid_str);
	ft_strdel(&valid_str);
	return (arg_inp);
}