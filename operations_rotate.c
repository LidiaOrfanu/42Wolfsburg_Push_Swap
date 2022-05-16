/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:44:02 by lorfanu           #+#    #+#             */
/*   Updated: 2022/04/08 15:24:47 by lorfanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Shift up all elements of stack a by 1.
 * The first element becomes the last one
 **/

void	rotate_a(t_list **stack_a)
{
	t_list	*first;
	t_list	*result;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	result = (*stack_a)->next;
	ft_lstadd_back(stack_a, first);
	first->next = NULL;
	*stack_a = result;
	ft_index_update(stack_a);
	ft_putendl_fd("ra", 1);
}

/**
 * Shift up all elements of stack b by 1.
 * The first element becomes the last one
 **/

void	rotate_b(t_list **stack_b)
{
	t_list	*first;
	t_list	*result;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	first = *stack_b;
	result = (*stack_b)->next;
	ft_lstadd_back(stack_b, first);
	first->next = NULL;
	*stack_b = result;
	ft_putendl_fd("rb", 1);
}

/**
 * ra and rb at the same time.
 **/
void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	ft_index_update(stack_a);
	ft_putendl_fd("rr", 1);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		ptr = *lst;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
}
