/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 03:24:50 by nabboune          #+#    #+#             */
/*   Updated: 2023/01/27 23:20:33 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"

int		ft_swap_a_no_print(t_list **a);
int		ft_swap_b_no_print(t_list **b);
int		ft_ss_no_print(t_list **a, t_list **b);
int		ft_push_a_no_print(t_list **a, t_list **b);
int		ft_push_b_no_print(t_list **a, t_list **b);
int		ft_rotate_a_no_print(t_list **a);
int		ft_rotate_b_no_print(t_list **b);
int		ft_rotate_no_print(t_list **a, t_list **b);
int		ft_reverse_rotate_a_no_print(t_list **a);
int		ft_reverse_rotate_b_no_print(t_list **b);
int		ft_reverse_rotate_no_print(t_list **a, t_list **b);

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
void	ft_free_cttab(char ***cttab);
int		ft_are_numbers(char **ctab, int size);
int		ft_verify_max_min_int(char **ctab, int size);
int		*ft_int_tab(int size, char **ctab);
t_list	*ft_stack_creation(int size, int *tab);
int		ft_check_doubles(t_list *stack);
void	ft_print_single_operation(int (*operation)(t_list **));
void	ft_print_double_operation(int (*operation)(t_list **,
				t_list **));

void	ft_end_of_stack(t_list **s);
int		ft_get_index(t_list *stack, int data);
int		ft_get_max(t_list *s);
int		ft_get_min(t_list *s);
int		ft_get_max2(t_list *stack, int max);
int		*get_max1_max2(t_list **b);
int		ft_a_is_sorted(t_list *s);
int		ft_b_is_sorted(t_list *s);
void	fix_stack_a(t_list **a);
void	ft_push(t_list **a, t_list **b, int pos);

void	ft_sort_2_numbers(t_list **a);
void	ft_sort_3_numbers(t_list **a);
void	ft_sort_50_numbers(t_list **a);
void	ft_sort_400_numbers(t_list **a);
void	ft_sort_500_numbers_and_more(t_list **a);
void	ft_push_back(t_list **a, t_list **b);

void	bubble_sort(int *array, int size);
void	ft_get_indexes(int *tab, t_list *stack);

#endif