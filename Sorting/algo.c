/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:54:11 by nabboune          #+#    #+#             */
/*   Updated: 2022/12/31 03:17:42 by nabboune         ###   ########.fr       */
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
	t_list *b;
	t_list *last_a;
	int size;
	int max_b_out_of_3;
	int max_a;
	int min_a;
	int index;
	int i;

	if (ft_a_is_sorted(*a))
		return ;
	b = NULL;
	while (ft_lstsize(*a) != 8)
		ft_push_b(a, &b);
	ft_sort_50_numbers(a);
	while (ft_lstsize(b) != 0)
	{
		max_b_out_of_3 = ft_get_max_out_of_3(b);
		max_a = ft_get_max(*a);
		min_a = ft_get_min(*a);
		index = ft_get_index(b, max_b_out_of_3);
		size = ft_lstsize(b);
		if (index == 0)
			ft_reverse_rotate_b(&b);
		else if (index == size - 1)
			ft_rotate_b(&b);
		last_a = ft_lstlast(*a);
		i = 0;
		if (b->content > (*a)->content && b->content < last_a->content)
		{
			while (b->content > (*a)->content)
				ft_reverse_rotate_a(a);
			// 	i++;
			ft_push_a(a, &b);
			// while (i--)
			// 	ft_rotate_a(a);
			continue ;
		}
		ft_push_a(a, &b);
		if (last_a->content < (*a)->content)
			ft_reverse_rotate_a(a);
	}
}