/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init_stack_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 23:03:57 by lorfanu           #+#    #+#             */
/*   Updated: 2022/05/16 03:05:52 by lorfanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init_stack_a(int ac, char **av, t_list *stack)
{
	int		i;
	int		pos;
	t_list	*tmp;

	pos = 0;
	i = 1;
	stack = new(ft_atol(av[i]), pos);
	tmp = stack;
	i++;
	pos++;
	while (i < ac)
	{
		stack->next = new(ft_atol(av[i]), pos);
		stack = stack->next;
		i++;
		pos++;
	}
	stack = tmp;
	return (stack);
}

t_list	*ft_get_sorted_index(t_list *stack_a, t_list *copy)
{
	t_list	*sorted;
	t_list	*s_a;
	int		i;

	i = 0;
	s_a = stack_a;
	sorted = sort_list(copy, ascending);
	while (sorted)
	{
		s_a = stack_a;
		while (s_a)
		{
			if (sorted->content == s_a->content)
			{
				s_a->sorted_index = i;
				i++;
			}
			s_a = s_a->next;
		}
		sorted = sorted->next;
	}
	return (stack_a);
}

/*
** Functions passed as cmp will always return a value different from 
** 0 if a and b are in the right order, 0 otherwise.
** The ascending function used as cmp will sort the list 
** in ascending order:
*/

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int		swapped;
	t_list	*cur;

	swapped = 1;
	cur = lst;
	while (swapped == 1)
	{
		swapped = 0;
		while (cur != 0 && cur->next != 0)
		{
			if (cmp(cur->content, cur->next->content) == 0)
			{
				swap_values(cur, cur->next);
				swapped = 1;
			}
			cur = cur->next;
		}
		cur = lst;
	}
	return (lst);
}

int	ascending(int a, int b)
{
	return (a <= b);
}

void	swap_values(t_list *a, t_list *b)
{
	int	swap;
	int	idx;

	idx = a->index;
	a->index = b->index;
	b->index = idx;
	swap = a->content;
	a->content = b->content;
	b->content = swap;
}
