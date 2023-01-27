/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_no_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:01:08 by nabboune          #+#    #+#             */
/*   Updated: 2023/01/27 23:10:25 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_push_a_no_print(t_list **a, t_list **b)
{
	t_list	*top_b;
	t_list	*top_a;

	if (!(*b))
		return (0);
	if (!(*a))
	{
		*a = *b;
		*b = (*b)->next;
		(*a)->next = NULL;
	}
	else
	{
		top_b = (*b)->next;
		top_a = *a;
		(*a) = *b;
		(*a)->next = top_a;
		*b = top_b;
	}
	return (1);
}

int	ft_push_b_no_print(t_list **a, t_list **b)
{
	t_list	*top_a;
	t_list	*top_b;

	if (!(*a))
		return (0);
	if (!(*b))
	{
		*b = *a;
		*a = (*a)->next;
		(*b)->next = NULL;
	}
	else
	{
		top_a = (*a)->next;
		top_b = *b;
		(*b) = *a;
		(*b)->next = top_b;
		*a = top_a;
	}
	return (1);
}
