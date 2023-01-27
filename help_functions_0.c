/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions_0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:36:14 by nabboune          #+#    #+#             */
/*   Updated: 2023/01/27 02:35:57 by nabboune         ###   ########.fr       */
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

	if (!cttab)
		return (-1);
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

void	ft_free_cttab(char ***cttab)
{
	int	i;
	int	j;

	i = 0;
	while (cttab[i])
	{
		j = 0;
		while (cttab[i][j])
			free(cttab[i][j++]);
		free(cttab[i++]);
	}
	free(cttab);
}

char	**ft_char_tab(int nb, char ***cttab)
{
	char	**ctab;
	int		i;
	int		j;
	int		k;

	if (!cttab)
		return (0);
	i = 0;
	ctab = (char **)malloc(nb * sizeof(char *));
	if (!ctab)
	{
		ft_free_cttab(cttab);
		return (0);
	}
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

t_list	*ft_stack_creation(int size, int *tab)
{
	t_list	*stack;
	int		i;

	if (!tab)
		return (0);
	i = 0;
	stack = ft_lstnew(tab[i++]);
	while (i < size)
		ft_lstadd_back(&stack, ft_lstnew(tab[i++]));
	return (stack);
}
