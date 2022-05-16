/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:12:55 by lorfanu           #+#    #+#             */
/*   Updated: 2022/04/08 16:28:04 by lorfanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_maxbits(int ac)
{
	int	max;
	int	bits;

	bits = 0;
	max = ac - 2;
	while (max >> bits)
		bits++;
	return (bits);
}

void	binary_sort(t_list **stack_a, t_list **stack_b, int shift)
{
	int	counter;
	int	size;

	counter = 0;
	size = size_list(*stack_a);
	while (counter < size)
	{
		if ((((*stack_a)->sorted_index >> shift) & 1) == 1)
			rotate_a(stack_a);
		else
			push_b(stack_a, stack_b);
		counter++;
	}
}

void	sort_big(t_list **stack_a, t_list **stack_b, int max_shift)
{
	int	shift;
	int	counter;

	counter = 0;
	shift = 0;
	while (shift <= max_shift)
	{
		binary_sort(stack_a, stack_b, shift);
		counter = 0;
		while ((*stack_b)->next != NULL)
		{
			push_a(stack_a, stack_b);
			counter++;
		}
		if (sorted_checker(stack_a) == 1)
		{
			ft_free_list(stack_a);
			ft_free_list(stack_b);
			exit(EXIT_SUCCESS);
		}
		shift++;
	}
}
