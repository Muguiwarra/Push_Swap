/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 03:24:43 by nabboune          #+#    #+#             */
/*   Updated: 2022/12/27 01:46:42 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list *stack;
	t_list *a;
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
		// TESTS
		// Test 1 : Swap
		a = stack;
		ft_swap_a(&a);
		while (a)
		{
			printf("%d ==> ", a->content);
			a = a->next;
		}
		// Result Test 1 : OK

		// Test 2 : Push

		// Result Test 1 :
	}
}