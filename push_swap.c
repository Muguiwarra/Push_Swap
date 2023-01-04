/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 03:24:43 by nabboune          #+#    #+#             */
/*   Updated: 2023/01/04 02:06:37 by nabboune         ###   ########.fr       */
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
		bubble_sort(tab, size);
		ft_get_indexes(tab, stack);
		// free(tab);
		if (size == 2)
			ft_sort_2_numbers(&stack);
		else if (size == 3)
			ft_sort_3_numbers(&stack);
		else if (size <= 50)
			ft_sort_50_numbers(&stack);
		else if (size <= 499)
			ft_sort_400_numbers(&stack);
		else
			ft_sort_500_numbers_and_more(&stack);
		system("leaks push_swap");
	}
}