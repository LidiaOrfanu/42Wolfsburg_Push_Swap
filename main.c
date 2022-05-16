/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:10:57 by lorfanu           #+#    #+#             */
/*   Updated: 2022/05/16 03:05:27 by lorfanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
** Write a program named push_swap that:
** Takes as an argument the stack a formatted as a list of integers.
** The first argument should be at the top of the stack (order matters);
** Must display the smallest list of instructions possible to sort the stack a,
** the smallest number being at the top;
** Instructions must be separated by a ’\n’ and nothing else
** If no parameters are specified, the program must not display anything & 
** give the prompt back
**/

#include "push_swap.h"

static int	ft_isnumeric(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	num_range_check(int ac, char **av)
{
	int	i;
	int	check;
	int	value;

	i = 1;
	check = 0;
	while (i < ac)
	{
		value = ft_atol(av[i]);
		if (ft_isnumeric(av[i]) == 0)
		{
			check = 1;
			return (check);
		}
		if (value < INT_MIN || value > INT_MAX)
		{
			check = 1;
			return (check);
		}
		i++;
	}
	return (check);
}

static int	nodup_checker(int ac, char **av)
{
	int	i;
	int	j;
	int	found;

	i = 1;
	found = 0;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atol(av[i]) == ft_atol(av[j]))
			{
				found = 1;
				return (found);
			}
			j++;
		}
		i++;
	}
	return (found);
}

int	main(int ac, char **av)
{
	if (num_range_check(ac, av) == 1 || nodup_checker(ac, av) == 1)
	{
		ft_putstr_fd("Error\n", 1);
		exit(EXIT_FAILURE);
	}
	else if (ac < 3)
		return (-1);
	else
		push_swap(ac, av);
	return (0);
}
