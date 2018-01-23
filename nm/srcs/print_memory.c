/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:07:41 by amoinier          #+#    #+#             */
/*   Updated: 2018/01/23 18:40:00 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static char		*reverse_string(char *str)
{
	char		tmp;
	int			j;
	int			size;

	j = 0;
	size = ft_strlen(str) - 1;
	while (str[j * 2])
	{
		tmp = str[j];
		str[j] = str[size - j];
		str[size - j] = tmp;
		j++;
	}
	return (str);
}

static char		*change_base(intptr_t addr, int base)
{
	char const	*char_base = "0123456789abcdef";
	char		*result;
	int			tmp;
	int			j;

	j = 0;
	tmp = 0;
	if (!(result = (char *)malloc(sizeof(char) * 17)))
		return (NULL);
	while (addr != 0)
	{
		tmp = addr % base;
		result[j] = char_base[tmp];
		addr /= base;
		j++;
	}
	result[j] = '\0';
	result = reverse_string(result);
	return (result);
}

char 	*add_zero(char *str_addr, int bit)
{
	int		i;
	char 	*str;

	if (!(str = (char *)malloc(sizeof(char) * bit + 1)))
		return (NULL);
	i = 0;
	while (i < (int)(bit - ft_strlen(str_addr)))
	{
		str[i] = '0';
		i++;
	}
	return (ft_strjoin(str, str_addr));
}

void			print_memory(unsigned int addr, int bit)
{
	char		*str_addr;

	str_addr = change_base(addr, 16);
	printf("%s - X%dX", str_addr, bit);
	if (ft_strlen(str_addr) > 0)
	{
		//ft_putstr(add_zero(str_addr, bit));
	}
	else
		ft_putstr("");
	free(str_addr);
	return ;
}
