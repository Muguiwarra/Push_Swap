/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:37:04 by nabboune          #+#    #+#             */
/*   Updated: 2023/01/26 23:06:26 by nabboune         ###   ########.fr       */
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
