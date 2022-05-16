/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:10:39 by lorfanu           #+#    #+#             */
/*   Updated: 2022/05/16 03:01:58 by lorfanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include<stdio.h>
# include<limits.h>
# include<stdlib.h>
# include<unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				sorted_index;
	struct s_list	*next;
}	t_list;

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
int		size_list(t_list *list);
void	ft_lstadd_front(t_list *lst, t_list *new);
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	reverserotate_a(t_list **stack_a);
void	reverserotate_b(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
size_t	ft_strlen(const char *s);
long	ft_atol(const char *str);
t_list	*new(int cont, int pos);
int		find_index_of_min(t_list **stack_a);
int		sorted_checker(t_list **stack_a);
void	ft_free_list(t_list **lst);
int		ascending(int a, int b);
t_list	*sort_list(t_list *lst, int (*cmp)(int, int));
t_list	*ft_get_sorted_index(t_list *stack_a, t_list *copy);
void	ft_sort_two(t_list **stack_a);
void	ft_sort_three(t_list **stack_a);
void	ft_helper(t_list **stack_a, t_list **stack_b);
void	ft_sort_four(t_list **stack_a, t_list **stack_b);
void	ft_sort_five(t_list **stack_a, t_list **stack_b);
void	sort_big(t_list **stack_a, t_list **stack_b, int max_shift);
int		ft_get_maxbits(int ac);
void	push_swap(int ac, char **av);
t_list	*init_stack_a(int ac, char **av, t_list *stack);
void	ft_index_update(t_list **stack);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void	*s, size_t n);
void	swap_values(t_list *a, t_list *b);

#endif