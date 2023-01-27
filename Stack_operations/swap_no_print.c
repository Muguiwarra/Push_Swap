/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_no_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:00:01 by nabboune          #+#    #+#             */
/*   Updated: 2023/01/27 23:17:51 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_swap_a_no_print(t_list **a)
{
	t_list	*top;

	if (!*a)
		return (0);
	top = (*a)->next;
	(*a)->next = top->next;
	top->next = *a;
	*a = top;
	return (1);
}

int	ft_swap_b_no_print(t_list **b)
{
	t_list	*top;

	if (!*b)
		return (0);
	top = (*b)->next;
	(*b)->next = top->next;
	top->next = *b;
	*b = top;
	return (1);
}

int	ft_ss_no_print(t_list **a, t_list **b)
{
	t_list	*top;

	if (!*a || !*b)
		return (0);
	top = (*a)->next;
	(*a)->next = top->next;
	top->next = *a;
	*a = top;
	top = (*b)->next;
	(*b)->next = top->next;
	top->next = *b;
	*b = top;
	return (1);
}
