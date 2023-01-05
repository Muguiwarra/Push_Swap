/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:54:11 by nabboune          #+#    #+#             */
/*   Updated: 2023/01/06 00:10:37 by nabboune         ###   ########.fr       */
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
	// free(b);
}

void	ft_sort_400_numbers(t_list **a)
{
	t_list	*b;
	int		size;
	int		chunk;
	int		i;

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
	ft_push_back(a, &b);
	// free(b);
}

void	ft_sort_500_numbers_and_more(t_list **a)
{
	t_list	*b;
	int		size;
	int		chunk;
	int		i;

	size = ft_lstsize(*a) / 7;
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
	// free(b);
}

void	ft_push_back(t_list **a, t_list **b)
{
	int	*arr;
	int	max;

	while (*b)
	{
		if (ft_lstsize(*b) == 1)
		{
			ft_push_a(a, b);
			continue ;
		}
		max = ft_get_max(*b);
		arr = get_max1_max2(b);
		if (arr == NULL)
		{
			free(a);
			a = NULL;
			return ;
		}
		if (max == arr[0])
			ft_push(a, b, arr[0]);
		else
		{
			ft_push(a, b, arr[0]);
			ft_push(a, b, arr[1]);
		}
		free(arr);
	}
}
