/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:30:52 by nabboune          #+#    #+#             */
/*   Updated: 2023/01/26 22:35:17 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_a(t_list **a)
{
	ft_swap_a_no_print(a);
	ft_print_single_operation(ft_swap_a_no_print);
}

void	ft_swap_b(t_list **b)
{
	ft_swap_b_no_print(b);
	ft_print_single_operation(ft_swap_b_no_print);
}

void	ft_ss(t_list **a, t_list **b)
{
	ft_ss_no_print(a, b);
	ft_print_double_operation(ft_ss_no_print);
}
