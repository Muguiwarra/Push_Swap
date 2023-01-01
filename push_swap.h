/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 03:24:50 by nabboune          #+#    #+#             */
/*   Updated: 2023/01/01 03:44:23 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"

void	ft_swap_a_no_print(t_list **a);
void	ft_swap_b_no_print(t_list **b);
void	ft_ss_no_print(t_list **a, t_list **b);
void	ft_push_a_no_print(t_list **a, t_list **b);
void	ft_push_b_no_print(t_list **a, t_list **b);
void	ft_rotate_a_no_print(t_list **a);
void	ft_rotate_b_no_print(t_list **b);
void	ft_rotate_no_print(t_list **a, t_list **b);
void	ft_reverse_rotate_a_no_print(t_list **a);
void	ft_reverse_rotate_b_no_print(t_list **b);
void	ft_reverse_rotate_no_print(t_list **a, t_list **b);

void	ft_swap_a(t_list **a);
void	ft_swap_b(t_list **b);
void	ft_ss(t_list **a, t_list **b);
void	ft_push_a(t_list **a, t_list **b);
void	ft_push_b(t_list **a, t_list **b);
void	ft_rotate_a(t_list **a);
void	ft_rotate_b(t_list **b);
void	ft_rotate(t_list **a, t_list **b);
void	ft_reverse_rotate_a(t_list **a);
void	ft_reverse_rotate_b(t_list **b);
void	ft_reverse_rotate(t_list **a, t_list **b);

char	***ft_split_arguments(int ac, char **av);
int		ft_how_many_numbers(char ***cttab);
char	**ft_char_tab(int nb, char ***cttab);
int		*ft_int_tab(int size, char **ctab);
t_list	*ft_stack_creation(int size, int *tab);
void	ft_print_single_operation(void (*operation)(t_list **));
void	ft_print_double_operation(void (*operation)(t_list **,
													t_list **));

void	ft_end_of_stack(t_list **s);
int		ft_get_index(t_list *stack, int data);
int		ft_where_to_push_oe(t_list *s, int x, int min);
int		ft_where_to_push_ue(t_list *s, int x, int max);
int		ft_get_max(t_list *s);
int		ft_get_min(t_list *s);
int		ft_get_max_out_of_3(t_list *s);
int		ft_get_min_out_of_3(t_list *s);
int		ft_a_is_sorted(t_list *s);
int		ft_b_is_sorted(t_list *s);

void	ft_sort_2_numbers(t_list **a);
void	ft_sort_3_numbers(t_list **a);
void	ft_sort_50_numbers(t_list **a);
void	ft_sort_400_numbers(t_list **a);

void	ft_tests(t_list *stack);
void	bubble_sort(int *array, int size);
void	ft_get_indexes(int *tab, t_list *stack);

#endif