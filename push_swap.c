/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:25:40 by nabboune          #+#    #+#             */
/*   Updated: 2023/01/27 01:44:59 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(int size, t_list **stack)
{
	if (size == 2)
		ft_sort_2_numbers(stack);
	else if (size == 3)
		ft_sort_3_numbers(stack);
	else if (size <= 50)
		ft_sort_50_numbers(stack);
	else if (size <= 499)
		ft_sort_400_numbers(stack);
	else
		ft_sort_500_numbers_and_more(stack);
}

int	main(int ac, char **av)
{
	t_list	*stack;
	char	***cttab;
	char	**ctab;
	int		*tab;
	int		size;

	if (ac > 1)
	{
		cttab = ft_split_arguments(ac, av);
		size = ft_how_many_numbers(cttab);
		ctab = ft_char_tab(size, cttab);
		if (!cttab || !ctab || ft_are_numbers(ctab, size) == -1
			|| ft_verify_max_min_int(ctab, size) == -1)
			return (ft_printf("Error\n"), 0);
		tab = ft_int_tab(size, ctab);
		stack = ft_stack_creation(size, tab);
		if (!tab || !stack || ft_check_doubles(stack) == 0)
			return (ft_printf("Error\n"), 0);
		bubble_sort(tab, size);
		ft_get_indexes(tab, stack);
		ft_sort(size, &stack);
		return (0);
	}
	return (0);
}
