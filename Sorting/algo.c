/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:54:11 by nabboune          #+#    #+#             */
/*   Updated: 2022/12/30 01:16:11 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_2_numbers(t_list **a)
{
	if ((*a)->content > (*a)->next->content)
		ft_swap_a(a);
}

void	ft_sort_3_numbers(t_list **a)
{
	t_list	*last;
	int		max;

	if (ft_a_is_sorted(*a))
		return ;
	last = ft_lstlast(*a);
	max = ft_get_max(*a);
	if (max == last->content)
	{
		if ((*a)->content > (*a)->next->content)
			ft_swap_a(a);
	}
	else if (max == (*a)->content)
	{
		ft_reverse_rotate_a(a);
		if (!ft_a_is_sorted(*a))
			ft_swap_a(a);
	}
	else
	{
		ft_rotate_a(a);
		if (!ft_a_is_sorted(*a))
			ft_swap_a(a);
	}
}

void	ft_sort_50_numbers(t_list **a)
{
	t_list	*b;
	int		index;
	int		size;

	if (ft_a_is_sorted(*a))
		return ;
	b = NULL;
	while (ft_lstsize(*a) != 3)
	{
		index = ft_get_index(*a, ft_get_min(*a));
		size = ft_lstsize(*a);
		if (index == 0)
		{
			ft_push_b(a, &b);
			continue ;
		}
		if (index < size / 2)
		{
			ft_reverse_rotate_a(a);
		}
		else
			ft_rotate_a(a);
	}
	ft_sort_3_numbers(a);
	while (ft_lstsize(b) != 0)
		ft_push_a(a, &b);
}

void	ft_sort_400_numbers(t_list **a)
{
}