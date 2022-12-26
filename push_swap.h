/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 03:24:50 by nabboune          #+#    #+#             */
/*   Updated: 2022/12/25 22:06:27 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"

// // typedef struct t_stack_element
// // {
// // 	int				data;
// // 	struct t_stack	*next;
// // }					s_stack_element;

// typedef t_list	s_stack_element;

void	ft_end_of_stack(t_list *s);
void	ft_swap_a(t_list *a);
void	ft_swap_b(t_list *b);
void	ft_ss(t_list *a, t_list *b);
void	ft_push_a(t_list *a, t_list *b);
void	ft_push_b(t_list *a, t_list *b);
void	ft_rotate_a(t_list *a);
void	ft_rotate_b(t_list *b);
void	ft_rotate(t_list *a, t_list *b);
void	ft_reverse_rotate_a(t_list *a);
void	ft_reverse_rotate_b(t_list *b);
void	ft_reverse_rotate(t_list *a, t_list *b);

#endif