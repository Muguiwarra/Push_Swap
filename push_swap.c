/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 03:24:43 by nabboune          #+#    #+#             */
/*   Updated: 2022/12/29 02:36:45 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list *stack;
	char ***cttab;
	char **ctab;
	int *tab;
	int size;

	if (ac > 1)
	{
		cttab = ft_split_arguments(ac, av);
		size = ft_how_many_numbers(cttab);
		ctab = ft_char_tab(size, cttab);
		tab = ft_int_tab(size, ctab);
		stack = ft_stack_creation(size, tab);
		if (size == 2)
			ft_sort_2_numbers(&stack);
		else if (size == 3)
			ft_sort_3_numbers(&stack);
		// ft_reverse_rotate_a(&stack);
		ft_tests(stack);
	}
}