/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:16:25 by amoinier          #+#    #+#             */
/*   Updated: 2018/01/23 18:51:57 by amoinier         ###   ########.fr       */
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
	char			type;
	unsigned int	value;
	struct s_symbol	*next;
}					t_symbol;

int			error(char *s);
t_symbol 	*create_symbols_list();
char 		detect_type(int type);

void		handle64(char *ptr);

void		get_string_array(int nsyms, int symoff, int stroff, char *ptr);



char 		**sort(char **array, int size);

void		print_memory(unsigned int addr, int bit);


#endif
