#include "push_swap.h"

void	ft_tests(t_list *stack)
{
	t_list *a;
	// t_list *b;
	// t_list *c;
	// t_list *d;
	t_list *tmp;

	tmp = stack;
	// TESTS
	// Test 1 : Swap
	a = stack;
	while (tmp)
	{
		printf("%d ==> ", tmp->content);
		tmp = tmp->next;
	}
	// printf("\n");
	// ft_swap_a(&a);
	// stack = a;
	// tmp = stack;
	// while (tmp)
	// {
	// 	printf("{%d, %d} ==> ", tmp->content, tmp->index);
	// 	tmp = tmp->next;
	// }
	// printf("\n");
	// // Result Test 1 : OK

	// // Test 2 : Pushing to an empty stack
	// b = NULL;
	// ft_push_b(&a, &b);
	// d = a;
	// while (d)
	// {
	// 	printf("{%d, %d} ==> ", d->content, d->index);
	// 	d = d->next;
	// }
	// printf("\n");
	// c = b;
	// while (c)
	// {
	// 	printf("{%d, %d} ==> ", c->content, c->index);
	// 	c = c->next;
	// }
	// printf("\n");
	// // Result Test 2 : OK

	// // Test 3 : Pushing to a loaded stack
	// ft_push_b(&a, &b);
	// ft_push_b(&a, &b);
	// ft_push_b(&a, &b);
	// ft_push_b(&a, &b);
	// d = a;
	// while (d)
	// {
	// 	printf("{%d, %d} ==> ", d->content, d->index);
	// 	d = d->next;
	// }
	// printf("\n");
	// c = b;
	// while (c)
	// {
	// 	printf("%d ==> ", c->content);
	// 	c = c->next;
	// }
	// printf("\n");
	// // Result Test 3 : OK

	// // Test 4 : Rotation
	// ft_rotate(&a, &b);
	// d = a;
	// while (d)
	// {
	// 	printf("%d ==> ", d->content);
	// 	d = d->next;
	// }
	// printf("\n");
	// d = b;
	// while (d)
	// {
	// 	printf("%d ==> ", d->content);
	// 	d = d->next;
	// }
	// printf("\n");
	// // Result Test 4 : OK

	// // Test 5 : Reverse Rotation
	// ft_reverse_rotate(&a, &b);
	// ft_reverse_rotate(&a, &b);
	// ft_reverse_rotate(&a, &b);
	// ft_reverse_rotate(&a, &b);
	// d = a;
	// while (d)
	// {
	// 	printf("%d ==> ", d->content);
	// 	d = d->next;
	// }
	// printf("\n");
	// d = b;
	// while (d)
	// {
	// 	printf("%d ==> ", d->content);
	// 	d = d->next;
	// }
	// printf("\n");
	// // Result Test 5 : OK
}