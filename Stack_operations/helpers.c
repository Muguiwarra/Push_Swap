/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:37:04 by nabboune          #+#    #+#             */
/*   Updated: 2023/01/04 00:00:27 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_end_of_stack(t_list **s)
{
	t_list	*p;

	p = (*s)->next;
	while (p)
	{
		if (p->next && !p->next->next)
		{
			p->next = NULL;
			return ;
		}
		p = p->next;
	}
}

int	ft_get_max(t_list *s)
{
	int	max;

	max = s->content;
	while (s)
	{
		if (s->content > max)
			max = s->content;
		s = s->next;
	}
	return (max);
}

int	ft_get_max2(t_list *stack, int max)
{
	int	max2;

	max2 = stack->content;
	if (stack->content == max)
		max2 = stack->next->content;
	while (stack)
	{
		if (stack->content < max && stack->content > max2)
			max2 = stack->content;
		stack = stack->next;
	}
	return (max2);
}

int	*get_max1_max2(t_list **b)
{
	int	res[2];
	int	index[2];
	int	max[2];
	int	*target;
	int	size;

	target = (int *)malloc(2 * sizeof(int));
	// if (!target)
	// {
	// 	free(b);
	// 	b = NULL;
	// 	return (0);
	// }
	size = ft_lstsize(*b);
	max[0] = ft_get_max(*b);
	max[1] = ft_get_max2(*b, max[0]);
	index[0] = ft_get_index(*b, max[0]);
	index[1] = ft_get_index(*b, max[1]);
	if (index[0] < size / 2)
		res[0] = index[0] + 1;
	else
		res[0] = size - index[0] + 2;
	if (index[1] < size / 2)
		res[1] = index[1] + 1;
	else
		res[1] = size - index[1] + 2;
	if (res[0] < res[1])
	{
		target[0] = max[0];
		target[1] = max[1];
	}
	else
	{
		target[0] = max[1];
		target[1] = max[0];
	}
	return (target);
}

int	ft_get_min(t_list *s)
{
	int	min;

	min = s->content;
	while (s)
	{
		if (s->content < min)
			min = s->content;
		s = s->next;
	}
	return (min);
}

int	ft_get_index(t_list *stack, int data)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->content == data)
			return (i);
		i++;
		stack = stack->next;
	}
	return (i);
}

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
