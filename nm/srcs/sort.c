/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:37:39 by amoinier          #+#    #+#             */
/*   Updated: 2018/01/23 18:51:35 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

char 	**sort(char **array, int size)
{
	int		i;
	int		j;
	int		indtmp;
	char 	*tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		indtmp = -1;
		while (j < size)
		{
			if (ft_strcmp(array[j], array[i]) < 0)
			{
				tmp = array[j];
				indtmp = j;
			}
			j++;
		}
		if (indtmp != -1)
		{
			array[indtmp] = array[i];
			array[i] = tmp;
		}
		i++;
	}
	return (array);
}
