/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_no_print.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:07:25 by nabboune          #+#    #+#             */
/*   Updated: 2023/01/27 23:16:05 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_reverse_rotate_a_no_print(t_list **a)
{
	t_list	*top;
	t_list	*last;

	if (!*a)
		return (0);
	if (ft_lstsize(*a) == 1)
		return (1);
	else if (ft_lstsize(*a) == 2)
		ft_swap_a_no_print(a);
	else
	{
		last = ft_lstlast(*a);
		top = *a;
		ft_end_of_stack(a);
		last->next = top;
		*a = last;
	}
	return (1);
}

int	ft_reverse_rotate_b_no_print(t_list **b)
{
	t_list	*top;
	t_list	*last;

	if (!*b)
		return (0);
	if (ft_lstsize(*b) == 1)
		return (1);
	else if (ft_lstsize(*b) == 2)
		ft_swap_b_no_print(b);
	else
	{
		last = ft_lstlast(*b);
		top = *b;
		ft_end_of_stack(b);
		last->next = top;
		*b = last;
	}
	return (1);
}

int	ft_reverse_rotate_no_print(t_list **a, t_list **b)
{
	if (!ft_rotate_a_no_print(a) || !ft_rotate_b_no_print(b))
		return (0);
	return (1);
}
