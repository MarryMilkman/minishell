/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_del_arg_inp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 14:31:45 by iseletsk          #+#    #+#             */
/*   Updated: 2018/07/22 14:31:47 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ms_del_arg_inp(char ***b_arg_inp)
{
	int	i;
	char	**arg_inp;

	arg_inp = *b_arg_inp;
	i = -1;
	while (arg_inp[++i])
		ft_strdel(&(arg_inp[i]));
	free(arg_inp);
	*b_arg_inp = 0;
}