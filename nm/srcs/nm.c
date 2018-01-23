/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:15:42 by amoinier          #+#    #+#             */
/*   Updated: 2018/01/23 18:41:16 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	nm(char *ptr)
{
	unsigned int	magic_number;

	magic_number = *(int *)ptr;
	if (magic_number == MH_MAGIC_64)
		handle64(ptr);
	else if (magic_number == MH_MAGIC)
		printf("32 BITS");
	else if (magic_number == FAT_MAGIC)
		printf("FAT BITS");
	else
		printf("OTHER");
}

int		main(int ac, char const **av)
{
	int 		fd;
	char 		*ptr;
	struct stat	info;

	if (ac != 2)
		return error("problem with arg");
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return error("can't open file");
	if (fstat(fd, &info) > 0)
		return error("can't fstat");
	if ((ptr = mmap(0, info.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
		return error("can't malloc st_size");

	create_symbols_list();
	nm(ptr);

	return 0;
}
