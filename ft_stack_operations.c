/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 14:53:19 by nabboune          #+#    #+#             */
/*   Updated: 2022/12/27 01:05:28 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_end_of_stack(t_list *s)
{
	t_list	*p;

	p = s->next;
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

void	ft_swap_a(t_list **a)
{
	t_list	*top;

	top = (*a)->next;
	(*a)->next = top->next;
	top->next = *a;
	*a = top;
	ft_printf("sa\n");
}

void	ft_swap_b(t_list **b)
{
	t_list	*top;

	top = (*b)->next;
	(*b)->next = top->next;
	top->next = *b;
	*b = top;
	ft_printf("sb\n");
}

void	ft_ss(t_list **a, t_list **b)
{
	t_list	*top;

	top = (*a)->next;
	(*a)->next = top->next;
	top->next = *a;
	*a = top;
	top = (*b)->next;
	(*b)->next = top->next;
	top->next = *b;
	*b = top;
	ft_printf("ss\n");
}

void	ft_push_a(t_list *a, t_list *b)
{
	t_list	*top_a;
	t_list	*top_b;
	t_list	*tmp;

	top_a = a;
	top_b = b;
	tmp = top_a->next;
	top_a->next = top_b;
	b = top_b;
	a = tmp;
	ft_printf("pa\n");
}

void	ft_push_b(t_list *a, t_list *b)
{
	t_list	*top_a;
	t_list	*top_b;
	t_list	*tmp;

	top_a = a;
	top_b = b;
	tmp = top_b->next;
	top_b->next = top_a;
	a = top_a;
	b = tmp;
	ft_printf("pb\n");
}

void	ft_rotate_a(t_list *a)
{
	t_list	*top;
	t_list	*last;

	last = ft_lstlast(a);
	top = a;
	ft_end_of_stack(a);
	last->next = top;
	a = last;
	ft_printf("ra\n");
}

void	ft_rotate_b(t_list *b)
{
	t_list	*top;
	t_list	*last;

	last = ft_lstlast(b);
	top = b;
	ft_end_of_stack(b);
	last->next = top;
	b = last;
	ft_printf("rb\n");
}

void	ft_rotate(t_list *a, t_list *b)
{
	t_list	*top;
	t_list	*last;

	last = ft_lstlast(a);
	top = a;
	ft_end_of_stack(a);
	last->next = top;
	a = last;
	last = ft_lstlast(b);
	top = b;
	ft_end_of_stack(b);
	last->next = top;
	b = last;
	ft_printf("rr\n");
}

void	ft_reverse_rotate_a(t_list *a)
{
	t_list	*top;
	t_list	*last;

	last = ft_lstlast(a);
	top = a->next;
	a->next = NULL;
	last->next = a;
	a = top;
	ft_printf("rra\n");
}

void	ft_reverse_rotate_b(t_list *b)
{
	t_list	*top;
	t_list	*last;

	last = ft_lstlast(b);
	top = b->next;
	b->next = NULL;
	last->next = b;
	b = top;
	ft_printf("rrb\n");
}

void	ft_reverse_rotate(t_list *a, t_list *b)
{
	t_list	*top;
	t_list	*last;

	last = ft_lstlast(a);
	top = a->next;
	a->next = NULL;
	last->next = a;
	a = top;
	last = ft_lstlast(b);
	top = b->next;
	b->next = NULL;
	last->next = b;
	b = top;
	ft_printf("rrr\n");
}
