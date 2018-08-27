/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cut_str_into_arg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 20:35:37 by iseletsk          #+#    #+#             */
/*   Updated: 2018/07/20 20:35:56 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static t_list	*s_list_new(char *str)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	list->next = 0;
	list->content = ft_strdup(str);
	list->content_size = ft_strlen(str);
	return (list);
}

static void	s_list_add(t_list **b_list, char *str)
{
	t_list *list;

	if (!(list = *b_list))
	{
		*b_list = s_list_new(str);
		return ;
	}
	while (list->next)
		list = list->next;
	list->next = s_list_new(str);
}

static int	s_add_to_list(t_list **list_str, char *str, char c)
{
	int		count;
	int		r_nbr;
	char	*s_str;

	r_nbr = 0;
	while (*str == ' ' && *(str + 1) == ' ' && c == ' ' && ++r_nbr)
		str++;
	count = 0;
	if ((c == '"' || c == '\'') && ++r_nbr)
		str++;
	while (str[count] != c)
		count++;
	s_str = ft_strndup(str, count);
	s_list_add(list_str, s_str);
	ft_strdel(&s_str);
	r_nbr += count;
	return (r_nbr + 1);
}

static char	**s_create_arr(t_list *b_list)
{
	t_list	*d_list;
	char	**arr;
	int		i;

	i = 0;
	d_list = b_list;
	while (d_list && ++i)
		d_list = d_list->next;
	arr = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while ((d_list = b_list))
	{
		arr[i++] = ms_dolar(b_list->content);
		b_list = b_list->next;
		free(d_list);
	}
	arr[i] = 0;
	return (arr);
}

char		**ms_cut_str_into_arg(char *str)
{
	t_list	*list_str;
	int		i;

	list_str = 0;
	i = -1;
	while (str[++i])
	{
		while (*str == ' ')
			str++;
		if (!*str)
			break ;
		if ((str[i] == '"' || str[i] == '\'' || str[i] == ' '))
		{
			str += s_add_to_list(&list_str, str, str[i]);
			i = -1;
		}
	}
	if (*str)
		s_list_add(&list_str, str);
	return (s_create_arr(list_str));
}
