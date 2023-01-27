/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:57:21 by nabboune          #+#    #+#             */
/*   Updated: 2023/01/26 23:08:14 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
		if (!arr)
			return (free(a));
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
