/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:54:11 by nabboune          #+#    #+#             */
/*   Updated: 2022/12/29 02:43:47 by nabboune         ###   ########.fr       */
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

	if (ft_is_sorted(*a))
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
		if (!ft_is_sorted(*a))
			ft_swap_a(a);
	}
	else
	{
		ft_rotate_a(a);
		if (!ft_is_sorted(*a))
			ft_swap_a(a);
	}
}

void	ft_sort_5_numbers(t_list **a)
{
}