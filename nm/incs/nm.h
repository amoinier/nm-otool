/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:16:25 by amoinier          #+#    #+#             */
/*   Updated: 2018/01/24 16:30:23 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_H

# define NM_H

# define SPACE_64 16
# define SPACE_32 12

# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/mman.h>
# include <unistd.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct		s_symbol {
	char			*name;
	unsigned int	type;
	uint64_t		value;
	struct s_symbol	*next;
	struct s_symbol	*prev;
}					t_symbol;

int			error(char *s);
t_symbol 	*create_symbols_list();
char 		detect_type(int type);

void		handle64(char *ptr);

void		get_string_array(int nsyms, int symoff, int stroff, char *ptr);



t_symbol 	*sort(t_symbol *symbols, t_symbol *new);

char		*print_memory(uint64_t addr, int bit);


#endif
