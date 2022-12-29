/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_no_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:00:01 by nabboune          #+#    #+#             */
/*   Updated: 2022/12/28 20:30:36 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_a_no_print(t_list **a)
{
	t_list	*top;

	top = (*a)->next;
	(*a)->next = top->next;
	top->next = *a;
	*a = top;
}

void	ft_swap_b_no_print(t_list **b)
{
	t_list	*top;

	top = (*b)->next;
	(*b)->next = top->next;
	top->next = *b;
	*b = top;
}

void	ft_ss_no_print(t_list **a, t_list **b)
{
	t_list	*top;

	top = (*a)->next;
	(*a)->next = top->next;
	top->next = *a;
	*a = top;
	top = (*b)->next;
	(*b)->next = top->next;
	top->next = *b;
	*b = top;
}
