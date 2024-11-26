/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_maker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 08:49:44 by afogonca          #+#    #+#             */
/*   Updated: 2024/11/26 09:29:55 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_stack	*ft_stacknew(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
/*void	ft_stackadd_back(t_stack **stack, t_stack *new)*/
/*{*/
/**/
/*}*/

t_stack	*stack_maker(char **list_char)
{
	int		i;
	t_stack	*stack;
	t_stack *stack_start;

	stack_start = ft_stacknew(ft_atoi(list_char[0]));
	if (!stack_start)
		return (NULL);
	stack = stack_start;
	i = 1;
	while (list_char[i] != 0)
	{
		stack->next = ft_stacknew(ft_atoi(list_char[i]));
		if (!stack->next)
			return (NULL); // Need to free everything but will do it later
		stack = stack->next;
		i++;
	}
	stack->next = NULL;
	return (stack_start);
}
