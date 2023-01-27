/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:29:52 by nabboune          #+#    #+#             */
/*   Updated: 2023/01/26 22:34:54 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push_a(t_list **a, t_list **b)
{
	ft_push_a_no_print(a, b);
	ft_print_double_operation(ft_push_a_no_print);
}

void	ft_push_b(t_list **a, t_list **b)
{
	ft_push_b_no_print(a, b);
	ft_print_double_operation(ft_push_b_no_print);
}
