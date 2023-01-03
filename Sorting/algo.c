/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:54:11 by nabboune          #+#    #+#             */
/*   Updated: 2023/01/03 03:03:19 by nabboune         ###   ########.fr       */
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
	int		size;
	int		chunk;
	int		i;
	int		pos;
	int		max_index;

	size = ft_lstsize(*a) / 5;
	chunk = 1;
	i = 0;
	b = NULL;
	while (*a)
	{
		if ((*a)->index <= size * chunk)
		{
			ft_push_b(a, &b);
			if (b->index < size * (chunk - 0.5))
				ft_rotate_b(&b);
			i++;
		}
		else
			ft_rotate_a(a);
		if (i == size * chunk)
			chunk++;
	}
	while (b)
	{
		max_index = ft_get_max_index(b);
		pos = ft_index_chr(b, max_index);
		if (b->index == max_index)
			ft_push_a(a, &b);
		else if (pos < ft_lstsize(b) / 2)
		{
			while (b->index != max_index)
				ft_rotate_b(&b);
		}
		else
		{
			while (b->index != max_index)
				ft_reverse_rotate_b(&b);
		}
	}
}

void	ft_sort_500_numbers_and_more(t_list **a)
{
	t_list	*b;
	int		size;
	int		chunk;
	int		i;

	size = ft_lstsize(*a) / 9;
	chunk = 1;
	i = 0;
	b = NULL;
	while (*a)
	{
		if ((*a)->index <= size * chunk)
		{
			ft_push_b(a, &b);
			if (b->index < size * (chunk - 0.5))
				ft_rotate_b(&b);
			i++;
		}
		else
			ft_rotate_a(a);
		if (i == size * chunk)
			chunk++;
	}
	ft_push_back(a, &b);
}

// void	ft_push_back(t_list **a, t_list **b)
// {
// 	int max_index;
// 	int pos;
// 	int i;

// 	while (*b)
// 	{
// 		max_index = ft_get_max_index(*b);
// 		pos = ft_index_chr(*b, max_index);
// 		// if ((*b)->index == max_index - 1)
// 		// ft_push_a(a, b);
// 		i = 1;
// 		if ((*b)->index == max_index - i)
// 		{
// 			ft_push_a(a, b);
// 			if ((*a)->next)
// 				ft_rotate_a(a);
// 			i++;
// 			while ((*b)->index == max_index - i)
// 			{
// 				ft_push_a(a, b);
// 				ft_rotate_a(a);
// 				i++;
// 			}
// 		}
// 		if ((*b)->index == max_index)
// 			ft_push_a(a, b);
// 		else if (pos < ft_lstsize(*b) / 2)
// 		{
// 			if (pos == 1)
// 				ft_swap_b(b);
// 			while ((*b)->index != max_index)
// 				ft_rotate_b(b);
// 		}
// 		else
// 		{
// 			while ((*b)->index != max_index)
// 				ft_reverse_rotate_b(b);
// 		}
// 		if (i != 1)
// 		{
// 			while (i != 1)
// 			{
// 				ft_reverse_rotate_a(a);
// 				i--;
// 			}
// 		}
// 		if ((*a) && (*a)->next && (*a)->index > (*a)->next->index
// 			&& (*b)->index < (*b)->next->index)
// 			ft_ss(a, b);
// 		if ((*a) && (*a)->next && (*a)->index > (*a)->next->index)
// 			ft_swap_a(a);
// 	}
// }

void	ft_push_back(t_list **a, t_list **b)
{
	int max_index;
	int pos;
	int i;
	int step_n;
	int step_n_1;

	while (*b)
	{
		max_index = ft_get_max_index(*b);
		pos = ft_index_chr(*b, max_index);
		i = 1;
		step_n = ft_steps_to_get_n(*b, max_index);
		step_n_1 = ft_steps_to_get_n_1(*b, max_index - i);
		if (step_n < 0 && step_n_1 < 0)
		{
			step_n = step_n * (-1);
			step_n_1 = step_n_1 * (-1);
			if (step_n < step_n_1)
			{
				while (step_n != 0)
				{
					ft_reverse_rotate_b(b);
					step_n--;
				}
			}
			else if (step_n > step_n_1)
			{
				while (step_n_1 != 0)
				{
					ft_reverse_rotate_b(b);
					step_n_1--;
				}
			}
		}
		else if (step_n > 0 && step_n_1 > 0)
		{
			if (step_n < step_n_1)
			{
				while (step_n != 0)
				{
					ft_rotate_b(b);
					step_n--;
				}
			}
			else if (step_n > step_n_1)
			{
				while (step_n_1 != 0)
				{
					ft_rotate_b(b);
					step_n_1--;
				}
			}
		}
	}
}