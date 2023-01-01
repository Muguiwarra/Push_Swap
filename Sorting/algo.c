/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:54:11 by nabboune          #+#    #+#             */
/*   Updated: 2023/01/01 04:29:24 by nabboune         ###   ########.fr       */
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
		ft_rotate_a(a);
		if (!ft_a_is_sorted(*a))
			ft_swap_a(a);
	}
	else
	{
		ft_reverse_rotate_a(a);
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
			ft_rotate_a(a);
		}
		else
			ft_reverse_rotate_a(a);
	}
	ft_sort_3_numbers(a);
	while (ft_lstsize(b) != 0)
		ft_push_a(a, &b);
}

void	ft_sort_400_numbers(t_list **a)
{
	t_list	*b;
	int		min_index;
	int		max_index;
	int		size;

	b = NULL;
	while (ft_lstsize(*a) != 3)
	{
		min_index = ft_get_min_out_of_3(*a);
		size = ft_lstsize(*a);
		if (min_index == 1)
		{
			ft_swap_a(a);
			ft_push_b(a, &b);
		}
		else if (min_index == size)
		{
			ft_reverse_rotate_a(a);
			ft_push_a(a, &b);
		}
		else
			ft_push_a(a, &b);
	}
	ft_sort_3_numbers(a);
	while (b)
	{
		max_index = ft_get_max_out_of_3(b);
		size = ft_lstsize(b);
		if (max_index == 1)
			ft_swap_b(&b);
		else if (max_index == size)
			ft_reverse_rotate_b(&b);
		if (b->index)
	}
}

// void	ft_sort_400_numbers(t_list **a)
// {
// 	t_list *b;
// 	t_list *last_a;
// 	int size_b;
// 	int size_a;
// 	int max_b_out_of_3;
// 	int max_a;
// 	int min_a;
// 	int index;
// 	int i;
// 	int j;

// 	if (ft_a_is_sorted(*a))
// 		return ;
// 	b = NULL;
// 	while (ft_lstsize(*a) != 8)
// 		ft_push_b(a, &b);
// 	ft_sort_50_numbers(a);
// 	while (ft_lstsize(b) != 0)
// 	{
// 		max_b_out_of_3 = ft_get_max_out_of_3(b);
// 		max_a = ft_get_max(*a);
// 		min_a = ft_get_min(*a);
// 		index = ft_get_index(b, max_b_out_of_3);
// 		size_b = ft_lstsize(b);
// 		size_a = ft_lstsize(*a);
// 		if (index == 1)
// 			ft_swap_b(&b);
// 		else if (index == size_b)
// 			ft_reverse_rotate_b(&b);
// 		last_a = ft_lstlast(*a);
// 		if (b->content > min_a && b->content < max_a)
// 		{
// 			// while (b->content > (*a)->content)
// 			// 	ft_reverse_rotate_a(a);
// 			if (b->content > (*a)->content)
// 				i = ft_where_to_push_oe(*a, b->content, min_a);
// 			else
// 				i = ft_where_to_push_ue(*a, b->content, max_a);
// 			j = 0;
// 			if (i <= (size_a / 2))
// 			{
// 				while (j++ < i)
// 					ft_rotate_a(a);
// 			}
// 			else if (i == size_a - 1)
// 				ft_reverse_rotate_a(a);
// 			else
// 			{
// 				while (j++ < i)
// 					ft_reverse_rotate_a(a);
// 			}
// 			ft_push_a(a, &b);
// 			// ft_swap_a(a);
// 			// while (i--)
// 			// 	ft_rotate_a(a);
// 			continue ;
// 		}
// 		else if (b->content > max_a)
// 		{
// 			i = ft_get_index(*a, max_a);
// 			j = 0;
// 			if (i < size_a / 2)
// 			{
// 				while (j++ < i + 1)
// 					ft_rotate_a(a);
// 			}
// 			else if (i > size_a / 2)
// 			{
// 				while (i++ < size_a)
// 					ft_reverse_rotate_a(a);
// 			}
// 			else
// 				ft_rotate_a(a);
// 			ft_push_a(a, &b);
// 			ft_swap_a(a);
// 			// ft_rotate_a(a);
// 			continue ;
// 		}
// 		else if (b->content < min_a)
// 		{
// 			i = ft_get_index(*a, min_a);
// 			j = 0;
// 			if (i != 0 && i < size_a / 2)
// 			{
// 				while (j++ < i)
// 					ft_rotate_a(a);
// 			}
// 			else if (i != 0 && i > size_a / 2)
// 			{
// 				while (i++ < size_a)
// 					ft_reverse_rotate_a(a);
// 			}
// 			ft_push_a(a, &b);
// 			continue ;
// 		}
// 		ft_push_a(a, &b);
// 		if (last_a->content < (*a)->content)
// 			ft_rotate_a(a);
// 	}
// }