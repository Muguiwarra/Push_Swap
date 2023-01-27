/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 03:07:41 by nabboune          #+#    #+#             */
/*   Updated: 2023/01/28 00:38:17 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_check_inst(char *inst)
{
	if (ft_strncmp(inst, "sa\n", 3) != 0 && ft_strncmp(inst, "sb\n", 3) != 0
		&& ft_strncmp(inst, "ss\n", 3) != 0 && ft_strncmp(inst, "pa\n", 3) != 0
		&& ft_strncmp(inst, "pb\n", 3) != 0 && ft_strncmp(inst, "ra\n", 3) != 0
		&& ft_strncmp(inst, "rb\n", 3) != 0 && ft_strncmp(inst, "rr\n", 3) != 0
		&& ft_strncmp(inst, "rra\n", 4) != 0 && ft_strncmp(inst, "rrb\n", 4) != 0
		&& ft_strncmp(inst, "rrr\n", 4) != 0)
		return (write(2, "Error\n", 6), 0);
	return (1);
}

void	ft_check_op(t_list **a, t_list **b, char *inst)
{
	if (ft_strncmp(inst, "sa\n", 3) == 0)
		ft_swap_a_no_print(a);
	else if (ft_strncmp(inst, "sb\n", 3) == 0)
		ft_swap_b_no_print(b);
	else if (ft_strncmp(inst, "ss\n", 3) == 0)
		ft_ss_no_print(a, b);
	else if (ft_strncmp(inst, "pa\n", 3) == 0)
		ft_push_a_no_print(a, b);
	else if (ft_strncmp(inst, "pb\n", 3) == 0)
		ft_push_b_no_print(a, b);
	else if (ft_strncmp(inst, "ra\n", 3) == 0)
		ft_rotate_a_no_print(a);
	else if (ft_strncmp(inst, "rb\n", 3) == 0)
		ft_rotate_b_no_print(b);
	else if (ft_strncmp(inst, "rr\n", 3) == 0)
		ft_rotate_no_print(a, b);
	else if (ft_strncmp(inst, "rra\n", 4) == 0)
		ft_reverse_rotate_a_no_print(a);
	else if (ft_strncmp(inst, "rrb\n", 4) == 0)
		ft_reverse_rotate_b_no_print(b);
	else if (ft_strncmp(inst, "rrr\n", 4) == 0)
		ft_reverse_rotate_no_print(a, b);
}

int	ft_input(char *inst, t_list **a, t_list **b)
{
	while (1)
	{
		inst = get_next_line(0);
		if (inst == NULL)
			return (1);
		if (ft_check_inst(inst))
			ft_check_op(a, b, inst);
		else
			return (free(inst), 0);
		free(inst);
	}
	return (1);
}

void	ft_result(t_list *a, t_list *b)
{
	if (ft_a_is_sorted(a) && !b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int ac, char **av)
{
	t_var	v;

	if (ac > 1)
	{
		v.cttab = ft_split_arguments(ac, av);
		v.size = ft_how_many_numbers(v.cttab);
		v.ctab = ft_char_tab(v.size, v.cttab);
		if (!v.cttab || !v.ctab || ft_are_numbers(v.ctab, v.size) == -1
			|| ft_verify_max_min_int(v.ctab, v.size) == -1)
			return (write(2, "Error\n", 6), 0);
		v.tab = ft_int_tab(v.size, v.ctab);
		v.stack = ft_stack_creation(v.size, v.tab);
		if (!v.tab || !v.stack || ft_check_doubles(v.stack) == 0)
			return (write(2, "Error\n", 6), 0);
		v.b = NULL;
		if (!ft_input(v.inst, &v.stack, &v.b))
			return (0);
		return (ft_result(v.stack, v.b), 0);
	}
	return (0);
}
