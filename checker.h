/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:22:32 by nabboune          #+#    #+#             */
/*   Updated: 2023/01/28 00:36:29 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

typedef struct variables
{
	t_list	*stack;
	t_list	*b;
	char	***cttab;
	char	**ctab;
	int		*tab;
	int		size;
	char	*inst;
}				t_var;

#endif