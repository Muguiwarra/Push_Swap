/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:32:27 by nabboune          #+#    #+#             */
/*   Updated: 2022/12/29 02:36:16 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_reverse_rotate_a(t_list **a)
{
	ft_reverse_rotate_a_no_print(a);
	ft_print_single_operation(ft_reverse_rotate_a_no_print);
}

void	ft_reverse_rotate_b(t_list **b)
{
	ft_reverse_rotate_b_no_print(b);
	ft_print_single_operation(ft_reverse_rotate_b_no_print);
}

void	ft_reverse_rotate(t_list **a, t_list **b)
{
	ft_reverse_rotate_no_print(a, b);
	ft_print_double_operation(ft_reverse_rotate_no_print);
}