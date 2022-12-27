/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:36:14 by nabboune          #+#    #+#             */
/*   Updated: 2022/12/27 02:14:44 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ==> 1) Split the av arguments
// ==> 2) Get a table of strings representing each single number passed by the user
// ==> 3) Create a table of int out of (2)
// ==> 4) Build a stack representing the int array

// ==> FUNCTIONS :
// ==> 1) Split the av arguments

#include "push_swap.h"

char	***ft_split_arguments(int ac, char **av)
{
	char	***cttab;
	int		i;
	int		j;

	i = 1;
	j = 0;
	cttab = (char ***)malloc(ac * sizeof(char **));
	while (av[i])
		cttab[j++] = ft_split(av[i++], ' ');
	cttab[j] = 0;
	return (cttab);
}

// ==> 2) Get a table of strings representing each single number passed by the user

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
	i = 0;
	k = 0;
	while (cttab[i])
	{
		j = 0;
		while (cttab[i][j])
			ctab[k++] = cttab[i][j++];
		i++;
	}
	return (ctab);
}

// ==> 3) Create a table of int out of (2)

int	*ft_int_tab(int size, char **ctab)
{
	int	*tab;
	int	i;

	i = 0;
	tab = (int *)malloc(size * sizeof(int));
	while (i < size)
	{
		tab[i] = ft_atoi(ctab[i]);
		i++;
	}
	return (tab);
}

// ==> 4) Build a stack representing the int array

t_list	*ft_stack_creation(int size, int *tab)
{
	t_list **node;
	t_list *stack;
	int i;

	i = 1;
	node = (t_list **)malloc(size * sizeof(t_list *));
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