/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 03:07:41 by nabboune          #+#    #+#             */
/*   Updated: 2023/01/27 18:51:36 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// t_list	*ft_check(t_list **a, char *inst)
// {
// 	t_list	*b;

// 	b = NULL;
// 	while (1)
// 	{
// 		if (ft_strncmp(inst, "sa\n", 3) != 0 && ft_strncmp(inst, "sb\n", 3) != 0 && ft_strncmp(inst, "ss\n", 3) != 0
// 			&& ft_strncmp(inst, "pa\n", 3) != 0 && ft_strncmp(inst, "pb\n", 3) != 0 && ft_strncmp(inst, "ra\n", 3) != 0
// 			&& ft_strncmp(inst, "rb\n", 3) != 0 && ft_strncmp(inst, "rr\n", 3) != 0 && ft_strncmp(inst, "rra\n", 4) != 0
// 			&& ft_strncmp(inst, "rrb\n", 4) != 0 && ft_strncmp(inst, "rrr\n", 4) != 0)
// 			return (write(2, "Error\n", 6), -1);
// 		else
// 		{
// 			if (ft_strncmp(inst, "sa\n", 3) == 0)
// 				ft_swap_a_no_print(&a);
// 			else if (ft_strncmp(inst, "sb\n", 3) == 0)
// 				ft_swap_b_no_print(&b);
// 			else if (ft_strncmp(inst, "ss\n", 3) == 0)
// 				ft_ss_no_print(&a, &b);
// 			else if (ft_strncmp(inst, "pa\n", 3) == 0)
// 				ft_push_a_no_print(&a, &b);
// 			else if (ft_strncmp(inst, "pb\n", 3) == 0)
// 				ft_push_b_no_print(&a, &b);
// 			else if (ft_strncmp(inst, "ra\n", 3) == 0)
// 				ft_rotate_a_no_print(&a);
// 			else if (ft_strncmp(inst, "rb\n", 3) == 0)
// 				ft_rotate_b_no_print(&b);
// 			else if (ft_strncmp(inst, "rr\n", 3) == 0)
// 				ft_rotate_no_print(&a, &b);
// 			else if (ft_strncmp(inst, "rra\n", 4) == 0)
// 				ft_reverse_rotate_a_no_print(&a);
// 			else if (ft_strncmp(inst, "rrb\n", 4) == 0)
// 				ft_reverse_rotate_b_no_print(&b);
// 			else if (ft_strncmp(inst, "rrr\n", 4) == 0)
// 				ft_reverse_rotate_no_print(&a, &b);
// 		}
// 	}
// 	if (ft_a_is_sorted(a) && !b)
// 		return (1);
// 	return (0);
// }

int main(int ac, char **av)
{
	t_list	*stack;
	t_list	*a;
	t_list	*b;
	char	***cttab;
	char	**ctab;
	int		*tab;
	int		size;
	char	*inst;

	if (ac > 1)
	{
		cttab = ft_split_arguments(ac, av);
		size = ft_how_many_numbers(cttab);
		ctab = ft_char_tab(size, cttab);
		if (!cttab || !ctab || ft_are_numbers(ctab, size) == -1
			|| ft_verify_max_min_int(ctab, size) == -1)
			return (write(2, "Error\n", 6), 0);
		tab = ft_int_tab(size, ctab);
		stack = ft_stack_creation(size, tab);
		if (!tab || !stack || ft_check_doubles(stack) == 0)
			return (write(2, "Error\n", 6), 0);

		a = stack;
		b = NULL;
		while (1)
		{
			inst = get_next_line(0);
			if (inst == NULL)
				break;
			if (ft_strncmp(inst, "sa\n", 3) != 0 && ft_strncmp(inst, "sb\n", 3) != 0 && ft_strncmp(inst, "ss\n", 3) != 0
				&& ft_strncmp(inst, "pa\n", 3) != 0 && ft_strncmp(inst, "pb\n", 3) != 0 && ft_strncmp(inst, "ra\n", 3) != 0
				&& ft_strncmp(inst, "rb\n", 3) != 0 && ft_strncmp(inst, "rr\n", 3) != 0 && ft_strncmp(inst, "rra\n", 4) != 0
				&& ft_strncmp(inst, "rrb\n", 4) != 0 && ft_strncmp(inst, "rrr\n", 4) != 0)
				return (write(2, "Error\n", 6), -1);
			else
			{
				if (ft_strncmp(inst, "sa\n", 3) == 0)
					ft_swap_a_no_print(&a);
				else if (ft_strncmp(inst, "sb\n", 3) == 0)
					ft_swap_b_no_print(&b);
				else if (ft_strncmp(inst, "ss\n", 3) == 0)
					ft_ss_no_print(&a, &b);
				else if (ft_strncmp(inst, "pa\n", 3) == 0)
					ft_push_a_no_print(&a, &b);
				else if (ft_strncmp(inst, "pb\n", 3) == 0)
					ft_push_b_no_print(&a, &b);
				else if (ft_strncmp(inst, "ra\n", 3) == 0)
					ft_rotate_a_no_print(&a);
				else if (ft_strncmp(inst, "rb\n", 3) == 0)
					ft_rotate_b_no_print(&b);
				else if (ft_strncmp(inst, "rr\n", 3) == 0)
					ft_rotate_no_print(&a, &b);
				else if (ft_strncmp(inst, "rra\n", 4) == 0)
					ft_reverse_rotate_a_no_print(&a);
				else if (ft_strncmp(inst, "rrb\n", 4) == 0)
					ft_reverse_rotate_b_no_print(&b);
				else if (ft_strncmp(inst, "rrr\n", 4) == 0)
					ft_reverse_rotate_no_print(&a, &b);
			}
		}
		if (ft_a_is_sorted(a) && !b)
			return (ft_printf("OK\n"), 0);
		else
			return (ft_printf("KO\n"), 0);
	}
	return (0);
}