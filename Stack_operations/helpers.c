/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:37:04 by nabboune          #+#    #+#             */
/*   Updated: 2023/01/03 01:16:08 by nabboune         ###   ########.fr       */
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

int	ft_get_max_index(t_list *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (index < stack->index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

int	ft_get_sum(t_list *stack)
{
	int	sum;

	sum = 0;
	while (stack)
	{
		sum += stack->content;
		stack = stack->next;
	}
	return (sum);
}

int	ft_index_chr(t_list *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (pos);
}

int	ft_steps_to_get_n(t_list *s, int index)
{
	t_list	*tmp;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = ft_lstsize(s);
	while (s)
	{
		if (s->index == index)
			break ;
		i++;
		s = s->next;
	}
	while (tmp)
	{
		if (tmp->index == index - 1)
			break ;
		j++;
		tmp = tmp->next;
	}
	if (size - i < i)
	{
		i = size - i;
		return (-i);
	}
	return (i);
}

int	ft_steps_to_get_n_1(t_list *s, int index)
{
	t_list	*tmp;
	int		i;
	int		size;

	i = 0;
	size = ft_lstsize(s);
	while (s)
	{
		if (s->index == index)
			break ;
		i++;
		s = s->next;
	}
	if (size - i < i)
	{
		i = size - i;
		return (-i);
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
