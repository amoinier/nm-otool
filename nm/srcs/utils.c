/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:20:44 by amoinier          #+#    #+#             */
/*   Updated: 2018/01/23 18:47:55 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"


int		error(char *s)
{
	ft_putstr(s);
	ft_putchar('\n');
	exit(0);
	return (0);
}

t_symbol 	*create_symbols_list()
{
	static t_symbol		*symbols;

	if (!symbols)
	{
		if (!(symbols = (t_symbol *)malloc(sizeof(t_symbol))))
			return (NULL);
	}
	return (symbols);
}

char 	detect_type(int type)
{
	if (type == 1)
		return ('U');
	if (type == 14)
		return ('t');
	if (type == 15)
		return ('T');
	if (type == 36)
		return ('T');
	else
		return (' ');
}
