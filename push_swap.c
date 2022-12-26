/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 03:24:43 by nabboune          #+#    #+#             */
/*   Updated: 2022/12/26 02:23:10 by nabboune         ###   ########.fr       */
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
		printf("1\n");
		printf("%s\n", av[0]);
		cttab = (char ***)malloc((ac - 1) * sizeof(char **));
		while (av[i])
		{
			cttab[i - 1] = ft_split(av[i], ' ');
			// j = 0;
			// while (cttab[i - 1][j])
			// 	printf("%s\t", cttab[i - 1][j++]);
			i++;
		}
		printf("2\n");
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
			printf("3\n");
			while (cttab[i][j])
				ctab[k++] = cttab[i][j++];
			printf("4\n");
			i++;
		}
		i = 0;
		printf("5\n");
		// mn hna l t7te khassni ndebuguihe....
		while (ctab[i])
		{
			printf("==%s==", ctab[i]);
			i++;
		}
		printf("\n==%d==\n", i);
		printf("6\n");
		tab = (int *)malloc(i * sizeof(int));
		i = 0;
		while (ctab[i])
		{
			printf("7\n");
			tab[i] = ft_atoi(ctab[i]);
			i++;
		}
		printf("8\n");
		j = 0;
		while (j < i)
			ft_printf("%d", tab[j++]);
		printf("9\n");
	}
	printf("10\n");
}