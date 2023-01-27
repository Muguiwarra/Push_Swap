/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:38:47 by nabboune          #+#    #+#             */
/*   Updated: 2023/01/27 01:40:24 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_verify_ctab_elem(char **ctab, char elem)
{
	if (!((elem >= 9 && elem <= 13) && elem == 32) && !(elem >= '0'
			&& elem <= '9'))
	{
		free(ctab);
		return (-1);
	}
	return (0);
}

int	ft_verify_max_min_int(char **ctab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ft_atoi(ctab[i]) > 2147483647 || ft_atoi(ctab[i]) < -2147483648)
		{
			free(ctab);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	ft_are_numbers(char **ctab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (ctab[i][j])
		{
			if (!(ctab[i][j] == '-' || ctab[i][j] == '+'))
			{
				if (ft_verify_ctab_elem(ctab, ctab[i][j]) == -1)
					return (-1);
			}
			else if (ctab[i][j] == '-' || ctab[i][j] == '+')
			{
				if (ft_verify_ctab_elem(ctab, ctab[i][j + 1]) == -1)
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
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

int	ft_check_doubles(t_list *stack)
{
	t_list	*tmp;

	if (!stack)
		return (0);
	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->content == tmp->content)
				return (0);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (1);
}
