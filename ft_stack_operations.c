/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 14:53:19 by nabboune          #+#    #+#             */
/*   Updated: 2022/12/27 22:10:55 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_double_operation(void (*operation)(t_list **, t_list **))
{
	if (operation == &ft_ss)
		ft_printf("ss\n");
	else if (operation == &ft_push_a)
		ft_printf("pa\n");
	else if (operation == &ft_push_b)
		ft_printf("pb\n");
	else if (operation == &ft_rotate)
		ft_printf("rr\n");
	else if (operation == &ft_reverse_rotate)
		ft_printf("rrr\n");
}

void	ft_print_single_operation(void (*operation)(t_list **))
{
	if (operation == &ft_swap_a)
		ft_printf("sa\n");
	if (operation == &ft_swap_b)
		ft_printf("sb\n");
	else if (operation == &ft_rotate_a)
		ft_printf("ra\n");
	else if (operation == &ft_rotate_b)
		ft_printf("rb\n");
	else if (operation == &ft_reverse_rotate_a)
		ft_printf("rra\n");
	else if (operation == &ft_reverse_rotate_b)
		ft_printf("rrb\n");
}

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

void	ft_swap_a(t_list **a)
{
	t_list	*top;

	top = (*a)->next;
	(*a)->next = top->next;
	top->next = *a;
	*a = top;
}

void	ft_swap_b(t_list **b)
{
	t_list	*top;

	top = (*b)->next;
	(*b)->next = top->next;
	top->next = *b;
	*b = top;
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
}

void	ft_push_a(t_list **a, t_list **b)
{
	t_list	*top_b;
	t_list	*top_a;

	if (!(*b))
		return ;
	if (!(*a))
	{
		*a = *b;
		*b = (*b)->next;
		(*a)->next = NULL;
	}
	else
	{
		top_b = (*b)->next;
		top_a = *a;
		(*a) = *b;
		(*a)->next = top_a;
		*b = top_b;
	}
}

void	ft_push_b(t_list **a, t_list **b)
{
	t_list	*top_a;
	t_list	*top_b;

	if (!(*a))
		return ;
	if (!(*b))
	{
		*b = *a;
		*a = (*a)->next;
		(*b)->next = NULL;
	}
	else
	{
		top_a = (*a)->next;
		top_b = *b;
		(*b) = *a;
		(*b)->next = top_b;
		*a = top_a;
	}
}

void	ft_rotate_a(t_list **a)
{
	t_list	*top;
	t_list	*last;

	if (ft_lstsize(*a) == 1)
		return ;
	else if (ft_lstsize(*a) == 2)
		ft_swap_a(a);
	else
	{
		last = ft_lstlast(*a);
		top = *a;
		ft_end_of_stack(a);
		last->next = top;
		*a = last;
	}
}

void	ft_rotate_b(t_list **b)
{
	t_list	*top;
	t_list	*last;

	if (ft_lstsize(*b) == 1)
		return ;
	else if (ft_lstsize(*b) == 2)
		ft_swap_b(b);
	else
	{
		last = ft_lstlast(*b);
		top = *b;
		ft_end_of_stack(b);
		last->next = top;
		*b = last;
	}
}

void	ft_rotate(t_list **a, t_list **b)
{
	ft_rotate_a(a);
	ft_rotate_b(b);
}

void	ft_reverse_rotate_a(t_list **a)
{
	t_list	*top;
	t_list	*second;
	t_list	*last;

	if (ft_lstsize(*a) == 1)
		return ;
	else if (ft_lstsize(*a) == 2)
		ft_swap_a(a);
	else
	{
		last = ft_lstlast(*a);
		top = *a;
		second = top->next;
		last->next = top;
		top->next = NULL;
		*a = second;
	}
}

void	ft_reverse_rotate_b(t_list **b)
{
	t_list	*top;
	t_list	*second;
	t_list	*last;

	if (ft_lstsize(*b) == 1)
		return ;
	else if (ft_lstsize(*b) == 2)
		ft_swap_a(b);
	else
	{
		last = ft_lstlast(*b);
		top = *b;
		second = top->next;
		last->next = top;
		top->next = NULL;
		*b = second;
	}
}

void	ft_reverse_rotate(t_list **a, t_list **b)
{
	ft_reverse_rotate_a(a);
	ft_reverse_rotate_b(b);
}
