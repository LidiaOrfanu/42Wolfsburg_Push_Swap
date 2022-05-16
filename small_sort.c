/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:10:45 by lorfanu           #+#    #+#             */
/*   Updated: 2022/04/06 18:35:34 by lorfanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_list **stack_a)
{
	int	elem1;
	int	elem2;

	elem1 = (*stack_a)->content;
	elem2 = (*stack_a)->next->content;
	if (elem1 > elem2)
		swap_a(stack_a);
}

void	ft_sort_three(t_list **stack_a)
{
	int	e[3];

	e[0] = (*stack_a)->content;
	e[1] = (*stack_a)->next->content;
	e[2] = (*stack_a)->next->next->content;
	if (e[0] > e[1] && e[0] > e[2])
	{
		rotate_a(stack_a);
		if (e[1] > e[2])
			swap_a(stack_a);
	}
	else if (e[1] > e[0] && e[1] > e[2])
	{
		reverserotate_a(stack_a);
		if (e[2] > e[0])
			swap_a(stack_a);
	}
	else if (e[2] > e[0] && e[2] > e[1])
		if (e[0] > e[1])
			swap_a(stack_a);
}

void	ft_helper(t_list **stack_a, t_list **stack_b)
{
	reverserotate_a(stack_a);
	push_b(stack_a, stack_b);
}

void	ft_sort_four(t_list **stack_a, t_list **stack_b)
{
	int	index_min;

	index_min = find_index_of_min(stack_a);
	if (index_min == 0)
		push_b(stack_a, stack_b);
	else if (index_min == 1)
	{
		rotate_a(stack_a);
		push_b(stack_a, stack_b);
	}
	else if (index_min == 2)
	{
		reverserotate_a(stack_a);
		ft_helper(stack_a, stack_b);
	}
	else if (index_min == 3)
		ft_helper(stack_a, stack_b);
	ft_sort_three(stack_a);
	push_a(stack_a, stack_b);
}

void	ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	int	index_min;

	index_min = find_index_of_min(stack_a);
	if (index_min == 0)
		push_b(stack_a, stack_b);
	else if (index_min == 1)
	{
		rotate_a(stack_a);
		push_b(stack_a, stack_b);
	}
	else if (index_min == 2)
	{
		rotate_a(stack_a);
		rotate_a(stack_a);
		push_b(stack_a, stack_b);
	}
	else if (index_min == 3)
	{
		reverserotate_a(stack_a);
		ft_helper(stack_a, stack_b);
	}
	else if (index_min == 4)
		ft_helper(stack_a, stack_b);
	ft_sort_four(stack_a, stack_b);
	push_a(stack_a, stack_b);
}
