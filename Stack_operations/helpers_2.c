/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 23:02:24 by nabboune          #+#    #+#             */
/*   Updated: 2023/01/26 23:05:34 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_get_target(int *tar0, int *tar1, int max0, int max1)
{
	*tar0 = max0;
	*tar1 = max1;
}

void	ft_get_max_values(t_list **b, int *max0, int *max1)
{
	*max0 = ft_get_max(*b);
	*max1 = ft_get_max2(*b, *max0);
}

int	*get_max1_max2(t_list **b)
{
	int	res[2];
	int	index[2];
	int	max[2];
	int	*target;

	target = (int *)malloc(2 * sizeof(int));
	if (!target)
		return (free(b), NULL);
	ft_get_max_values(b, &max[0], &max[1]);
	index[0] = ft_get_index(*b, max[0]);
	index[1] = ft_get_index(*b, max[1]);
	if (index[0] < ft_lstsize(*b) / 2)
		res[0] = index[0] + 1;
	else
		res[0] = ft_lstsize(*b) - index[0] + 2;
	if (index[1] < ft_lstsize(*b) / 2)
		res[1] = index[1] + 1;
	else
		res[1] = ft_lstsize(*b) - index[1] + 2;
	if (res[0] < res[1])
		ft_get_target(&target[0], &target[1], max[0], max[1]);
	else
		ft_get_target(&target[0], &target[1], max[1], max[0]);
	return (target);
}
