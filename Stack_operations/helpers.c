/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:37:04 by nabboune          #+#    #+#             */
/*   Updated: 2023/01/01 03:49:06 by nabboune         ###   ########.fr       */
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

// int	ft_get_max_out_of_3(t_list *s)
// {
// 	int		max;
// 	t_list	*last;

// 	max = s->content;
// 	last = ft_lstlast(s);
// 	if (s->next && max < s->next->content)
// 		max = s->next->content;
// 	if (s->next && max < last->content)
// 		max = last->content;
// 	return (max);
// }

int	ft_get_max_out_of_3(t_list *s)
{
	int		max;
	t_list	*last;

	max = s->index;
	last = ft_lstlast(s);
	if (max < s->next->index)
		max = s->next->index;
	if (max < last->index)
		max = last->index;
	return (max);
}

int	ft_get_min_out_of_3(t_list *s)
{
	int		min;
	int		size;
	t_list	*last;

	min = s->index;
	size = ft_lstsize(s);
	last = ft_lstlast(s);
	if (min > s->next->index && last->index > s->next->index)
		return (1);
	if (min > last->index && last->index < s->next->index)
		return (size);
	return (0);
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

int	ft_where_to_push_oe(t_list *s, int x, int min)
{
	int	i;

	i = 0;
	while (s && s->content != min)
	{
		s = s->next;
		i++;
	}
	while (s)
	{
		if (s->content > x)
			return (i);
		i++;
		s = s->next;
	}
	return (i);
}

int	ft_where_to_push_ue(t_list *s, int x, int max)
{
	int	i;

	i = 0;
	while (s && s->content != max)
	{
		s = s->next;
		i++;
	}
	while (s)
	{
		if (s->content < x)
			return (i);
		i++;
		s = s->next;
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
