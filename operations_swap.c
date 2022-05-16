/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:43:58 by lorfanu           #+#    #+#             */
/*   Updated: 2022/04/08 14:24:46 by lorfanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Swap the first 2 elements at the top of stack a.
 * Do nothing if there is only one or no elements.
 **/

void	swap_a(t_list **stack_a)
{
	t_list	*first;
	t_list	*tmp;

	tmp = *stack_a;
	first = tmp->next;
	tmp->next = tmp->next->next;
	first->next = tmp;
	*stack_a = first;
	ft_index_update(stack_a);
	ft_putendl_fd("sa", 1);
}

/**
 * Swap the first 2 elements at the top of stack b.
 * Do nothing if there is only one or no elements.
 **/

void	swap_b(t_list **stack_b)
{
	t_list	*first;
	t_list	*tmp;

	tmp = *stack_b;
	first = tmp->next;
	tmp->next = tmp->next->next;
	first->next = tmp;
	*stack_b = first;
	ft_putendl_fd("sb", 1);
}

/**
 * sa and sb at the same time.
 **/

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	ft_index_update(stack_a);
	ft_putendl_fd("ss", 1);
}
