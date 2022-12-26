/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 03:24:43 by nabboune          #+#    #+#             */
/*   Updated: 2022/12/26 11:50:00 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char ***cttab;
	char **ctab;
	int *tab;
	int i;
	int j;
	int k;
	int l;

	cttab = NULL;
	ctab = NULL;
	tab = NULL;
	if (ac > 1)
	{
		i = 1;
		cttab = (char ***)malloc(ac * sizeof(char **));
		while (av[i])
		{
			cttab[i - 1] = ft_split(av[i], ' ');
			i++;
		}
		cttab[i] = 0;
		i = 0;
		k = 0;
		l = 0;
		while (cttab[i])
		{
			j = 0;
			while (cttab[i][j])
			{
				j++;
				l++;
			}
			i++;
		}
		ctab = (char **)malloc(l * sizeof(char *));
		i = 0;
		while (cttab[i])
		{
			j = 0;
			while (cttab[i][j])
				ctab[k++] = cttab[i][j++];
			i++;
		}
		i = 0;
		while (i <= k)
		{
			i++;
		}
		tab = (int *)malloc(i * sizeof(int));
		i = 0;
		while (ctab[i])
		{
			tab[i] = ft_atoi(ctab[i]);
			i++;
		}
		j = 0;
		while (j < i)
			ft_printf("{%d}", tab[j++]);
	}
}