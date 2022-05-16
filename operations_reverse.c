/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:44:05 by lorfanu           #+#    #+#             */
/*   Updated: 2022/04/08 14:25:00 by lorfanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Shift up all elements of stack a by 1.
 * The first element becomes the last one
 **/

void	reverserotate_a(t_list **stack_a)
{
	t_list	*result;
	t_list	*first;
	t_list	*temp;

	temp = *stack_a;
	while (temp->next->next != NULL)
		temp = temp->next;
	first = temp->next;
	temp->next = NULL;
	result = first;
	result->next = *stack_a;
	*stack_a = result;
	ft_index_update(stack_a);
	ft_putendl_fd("rra", 1);
}

/**
 * Shift down all elements of stack b by 1.
 * The last element becomes the first one
 **/
void	reverserotate_b(t_list **stack_b)
{
	t_list	*result;
	t_list	*first;
	t_list	*temp;

	temp = *stack_b;
	while (temp->next->next != NULL)
		temp = temp->next;
	first = temp->next;
	temp->next = NULL;
	result = first;
	result->next = *stack_b;
	*stack_b = result;
	ft_putendl_fd("rrb", 1);
}

/**
 * rra and rrb at the same time.
 **/

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverserotate_a(stack_a);
	reverserotate_b(stack_b);
	ft_index_update(stack_a);
	ft_putendl_fd("rrr", 1);
}
