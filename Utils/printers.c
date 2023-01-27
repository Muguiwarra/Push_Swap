/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 14:53:19 by nabboune          #+#    #+#             */
/*   Updated: 2023/01/27 23:19:45 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_print_double_operation(int (*operation)(t_list **, t_list **))
{
	if (operation == &ft_ss_no_print)
		ft_printf("ss\n");
	else if (operation == &ft_push_a_no_print)
		ft_printf("pa\n");
	else if (operation == &ft_push_b_no_print)
		ft_printf("pb\n");
	else if (operation == &ft_rotate_no_print)
		ft_printf("rr\n");
	else if (operation == &ft_reverse_rotate_no_print)
		ft_printf("rrr\n");
}

void	ft_print_single_operation(int (*operation)(t_list **))
{
	if (operation == &ft_swap_a_no_print)
		ft_printf("sa\n");
	if (operation == &ft_swap_b_no_print)
		ft_printf("sb\n");
	else if (operation == &ft_reverse_rotate_a_no_print)
		ft_printf("rra\n");
	else if (operation == &ft_reverse_rotate_b_no_print)
		ft_printf("rrb\n");
	else if (operation == &ft_rotate_a_no_print)
		ft_printf("ra\n");
	else if (operation == &ft_rotate_b_no_print)
		ft_printf("rb\n");
}
