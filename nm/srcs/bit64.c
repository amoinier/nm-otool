/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit64.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:36:16 by amoinier          #+#    #+#             */
/*   Updated: 2018/01/24 16:47:30 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void		handle64(char *ptr)
{
	int						ncmds;
	int 					i;
	struct mach_header_64	*header;
	struct load_command		*lc;
	struct symtab_command	*sym;

	header = (struct mach_header_64 *)ptr;
	ncmds = header->ncmds;
	lc = (void *)(ptr + sizeof(struct mach_header_64));
	i = 0;
	while (i < ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *)lc;
			get_string_array(sym->nsyms, sym->symoff, sym->stroff, ptr);
			break ;
		}
		lc = (void *) lc + lc->cmdsize;
		i++;
	}
}
