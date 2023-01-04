/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:36:14 by nabboune          #+#    #+#             */
/*   Updated: 2023/01/04 01:56:44 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	***ft_split_arguments(int ac, char **av)
{
	char	***cttab;
	int		i;
	int		j;

	i = 1;
	j = 0;
	cttab = (char ***)malloc(ac * sizeof(char **));
	if (!cttab)
		return (0);
	while (av[i])
		cttab[j++] = ft_split(av[i++], ' ');
	cttab[j] = 0;
	return (cttab);
}

int	ft_how_many_numbers(char ***cttab)
{
	int	i;
	int	j;
	int	l;

	i = 0;
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
	return (l);
}

char	**ft_char_tab(int nb, char ***cttab)
{
	char	**ctab;
	int		i;
	int		j;
	int		k;

	ctab = (char **)malloc(nb * sizeof(char *));
	if (!ctab)
	{
		free(cttab);
		cttab = NULL;
		return (0);
	}
	i = 0;
	k = 0;
	while (cttab[i])
	{
		j = 0;
		while (cttab[i][j])
			ctab[k++] = cttab[i][j++];
		i++;
	}
	free(cttab);
	return (ctab);
}

int	*ft_int_tab(int size, char **ctab)
{
	int	*tab;
	int	i;

	i = 0;
	tab = (int *)malloc(size * sizeof(int));
	if (!tab)
	{
		free(ctab);
		ctab = NULL;
		return (0);
	}
	while (i < size)
	{
		tab[i] = ft_atoi(ctab[i]);
		i++;
	}
	free(ctab);
	return (tab);
}

t_list	*ft_stack_creation(int size, int *tab)
{
	t_list **node;
	t_list *stack;
	int i;

	i = 1;
	node = (t_list **)malloc(size * sizeof(t_list *));
	if (!node)
	{
		free(tab);
		tab = NULL;
		return (0);
	}
	node[0] = ft_lstnew(tab[0]);
	while (i < size)
	{
		node[i] = ft_lstnew(tab[i]);
		node[i - 1]->next = node[i];
		i++;
	}
	stack = node[0];
	return (stack);
}