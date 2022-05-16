/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:53:18 by lorfanu           #+#    #+#             */
/*   Updated: 2022/04/08 14:04:17 by lorfanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = NULL;
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

void	ft_bzero(void	*s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	ft_index_update(t_list **stack)
{
	t_list	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (temp != NULL)
	{
		temp->index = i;
		i++;
		temp = temp->next;
	}
}

int	find_index_of_min(t_list **stack_a)
{
	int		min;
	t_list	*list;
	int		idx_min;

	idx_min = 0;
	list = *stack_a;
	min = list->content;
	list = list->next;
	while (list != NULL)
	{
		if (list->content < min)
		{
			min = list->content;
			idx_min = list->index;
		}
		list = list->next;
	}
	return (idx_min);
}
