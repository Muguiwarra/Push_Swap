/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:37:04 by nabboune          #+#    #+#             */
/*   Updated: 2022/12/29 02:32:10 by nabboune         ###   ########.fr       */
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

int	ft_is_sorted(t_list *s)
{
	t_list *tmp;

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