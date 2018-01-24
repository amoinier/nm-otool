/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:37:39 by amoinier          #+#    #+#             */
/*   Updated: 2018/01/24 16:47:05 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

t_symbol 	*sort(t_symbol *symbols, t_symbol *new)
{
	t_symbol *tmp;

	tmp = symbols;
	while (tmp && tmp->name && ft_strcmp(tmp->name, new->name) < 0 && ft_strcmp(tmp->name, new->name) != 0)
		tmp = tmp->next;

	if (!tmp || !tmp->name || ft_strcmp(tmp->name, new->name) != 0)
	{
		if (tmp && tmp->prev)
			new->prev = tmp->prev;
		new->next = tmp;
		if (tmp)
		{
			if (tmp->prev)
				tmp->prev->next = new;
			tmp->prev = new;
		}
	}

	while (symbols->prev)
	{
		symbols = symbols->prev;
	}
	return (symbols);
}
