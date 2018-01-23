/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos_symbols.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:37:31 by amoinier          #+#    #+#             */
/*   Updated: 2018/01/23 18:51:15 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"


static void		print_output()
{
	t_symbol		*symbols;

	symbols = create_symbols_list();
	while (symbols)
	{
		if (symbols->name[0] == '_' || ft_strstr(symbols->name, "dyld"))
		{
			printf("%s\n", symbols->name);
		}
		symbols = symbols->next;
	}
}

void			get_string_array(int nsyms, int symoff, int stroff, char *ptr)
{
	int				i;
	t_symbol		*symbols;
	char 			*stringtable;
	struct nlist_64	*array;

	array = (void *)ptr + symoff;
	stringtable = (void *)ptr + stroff;
	symbols = create_symbols_list();
	i = 0;
	while (i < nsyms)
	{
		if (!symbols)
		{
			if (!(symbols = (t_symbol *)malloc(sizeof(t_symbol) + 1)))
				error("can't malloc");
		}
		symbols->name = &stringtable[array[i].n_un.n_strx];
		symbols->value = array[i].n_value;
		symbols->value = array[i].n_type;
		symbols = symbols->next;
		i++;
	}
	print_output();
}
