/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos_symbols.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:37:31 by amoinier          #+#    #+#             */
/*   Updated: 2018/01/24 16:30:42 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"


static void		print_output(t_symbol *symbols)
{
	while (symbols)
	{
		if (symbols->name && (symbols->name[0] == '_' || ft_strstr(symbols->name, "dyld")))
		{
			printf("%s %c %s\n", print_memory(symbols->value, SPACE_64), detect_type(symbols->type), symbols->name);
		}
		symbols = symbols->next;
	}
}
// static t_symbol	*add_new_symbol(t_symbol *symbols, t_symbol *new)
// {
//
// }

void				get_string_array(int nsyms, int symoff, int stroff, char *ptr)
{
	int				i;
	t_symbol		*symbols;
	t_symbol 		*tmp;
	char 			*stringtable;
	struct nlist_64	*array;

	array = (void *)ptr + symoff;
	stringtable = (void *)ptr + stroff;
	symbols = create_symbols_list();
	tmp = NULL;
	i = 0;
	while (i < nsyms)
	{
		if (&stringtable[array[i].n_un.n_strx])
		{
			if (!(tmp = create_symbols_list()))
				error("can't malloc");
			tmp->name = ft_strdup(&stringtable[array[i].n_un.n_strx]);
			tmp->value = array[i].n_value;
			tmp->type = array[i].n_type;
			symbols = sort(symbols, tmp);
		}
		i++;
	}
	print_output(symbols);
}
