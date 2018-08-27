/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 21:40:42 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/04 16:23:15 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_read_output(char **line)
{
	char	test_box[255];
	char	*buf;
	char	*box;
	int		n;

	if (!line || read(0, test_box, 0) < 0)
		return (-1);
	*line = 0;
	box = 0;
	n = 0;
	while (read(0, (buf = ft_strnew(1)), 1) > 0)
	{
		box = ft_strjoin_md(box, "", buf);
		if (ft_count_c(box, '\n') && (n = 1))
			break ;
	}
	if (!n)
		ft_strdel(&buf);
	*line = ft_strdup(box);
	ft_strdel(&box);
	if (!line || !*line)
		return (0);
	n = ft_strlen(*line) - 1;
	(*line)[n] == '\n' ? (*line)[n] = 0 : 0;
	return (1);
}
