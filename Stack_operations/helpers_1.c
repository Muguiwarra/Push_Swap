/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 23:02:19 by nabboune          #+#    #+#             */
/*   Updated: 2023/01/26 23:06:19 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_a_is_sorted(t_list *s)
{
	t_list	*tmp;

	tmp = s->next;
	while (tmp)
	{
		if (s->content > tmp->content)
			return (0);
		s = s->next;
		tmp = tmp->next;
	}
	return (1);
}

int	ft_b_is_sorted(t_list *s)
{
	t_list	*tmp;

	tmp = s->next;
	while (tmp)
	{
		if (s->content < tmp->content)
			return (0);
		s = s->next;
		tmp = tmp->next;
	}
	return (1);
}

void	fix_stack_a(t_list **a)
{
	if (ft_lstsize(*a) > 1)
		if ((*a)->content > (*a)->next->content)
			ft_swap_a(a);
}

void	ft_push(t_list **a, t_list **b, int data)
{
	int	size;
	int	index;

	fix_stack_a(a);
	while (1)
	{
		size = ft_lstsize(*b);
		index = ft_get_index(*b, data);
		if (index == 0)
		{
			ft_push_a(a, b);
			fix_stack_a(a);
			break ;
		}
		if (index > size / 2)
			ft_reverse_rotate_b(b);
		else
			ft_rotate_b(b);
	}
}
