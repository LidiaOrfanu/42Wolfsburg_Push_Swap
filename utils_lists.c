/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:10:49 by lorfanu           #+#    #+#             */
/*   Updated: 2022/04/08 14:19:20 by lorfanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*new(int cont, int pos)
{
	t_list	*ret;

	ret = malloc(sizeof(t_list));
	ret->content = cont;
	ret->index = pos;
	ret->next = NULL;
	return (ret);
}

int	size_list(t_list *list)
{
	int	counter;

	counter = 0;
	while (list != NULL)
	{
		counter++;
		list = list->next;
	}
	return (counter);
}

void	ft_free_list(t_list **lst)
{
	t_list	*head;
	t_list	*tmp;

	head = *lst;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	*lst = NULL;
}
