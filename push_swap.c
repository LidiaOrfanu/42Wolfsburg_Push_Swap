/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 19:02:36 by lorfanu           #+#    #+#             */
/*   Updated: 2022/04/08 14:13:40 by lorfanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_checker(t_list **stack_a)
{
	t_list	*a;
	t_list	*b;

	a = *stack_a;
	b = (*stack_a)->next;
	while (b != NULL)
	{
		if (a->content > b->content)
			return (0);
		a = a->next;
		b = b->next;
	}
	return (1);
}

void	select_sorting(int ac, t_list **stack_a, t_list **stack_b)
{
	int		max_shift;

	if (ac == 3)
		ft_sort_two(stack_a);
	else if (ac == 4)
		ft_sort_three(stack_a);
	else if (ac == 5)
		ft_sort_four(stack_a, stack_b);
	else if (ac == 6)
		ft_sort_five(stack_a, stack_b);
	else
	{
		max_shift = ft_get_maxbits(ac);
		sort_big(stack_a, stack_b, max_shift);
	}
}

void	push_swap(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*copy;
	t_list	*stack_b;

	copy = NULL;
	stack_a = NULL;
	stack_b = NULL;
	copy = init_stack_a(ac, av, copy);
	stack_a = init_stack_a(ac, av, stack_a);
	if (sorted_checker(&stack_a) == 1)
	{
		ft_free_list(&stack_a);
		ft_free_list(&copy);
		exit(EXIT_SUCCESS);
	}
	stack_b = ft_calloc(1, sizeof(t_list));
	stack_a = ft_get_sorted_index(stack_a, copy);
	ft_free_list(&copy);
	select_sorting(ac, &stack_a, &stack_b);
	ft_free_list(&stack_a);
	free(stack_b);
}
