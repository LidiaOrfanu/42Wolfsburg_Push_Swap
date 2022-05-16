/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:26:13 by lorfanu           #+#    #+#             */
/*   Updated: 2022/04/07 15:19:01 by lorfanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Take the first element at the top of b and put it at the top of a.
 * Do nothing if b is empty.
 **/

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*pushed;
	t_list	*result;

	if (size_list(*stack_b) == 0)
		return ;
	pushed = *stack_b;
	result = (*stack_b)->next;
	pushed->next = *stack_a;
	*stack_a = pushed;
	*stack_b = result;
	ft_index_update(stack_a);
	ft_putendl_fd("pa", 1);
}

/**
 * Take the first element at the top of a and put it at the top of b.
 * Do nothing if a is empty
 **/

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*pushed;
	t_list	*result;

	if (size_list(*stack_a) == 0)
		return ;
	pushed = *stack_a;
	result = (*stack_a)->next;
	pushed->next = *stack_b;
	*stack_a = result;
	*stack_b = pushed;
	ft_index_update(stack_a);
	ft_putendl_fd("pb", 1);
}
