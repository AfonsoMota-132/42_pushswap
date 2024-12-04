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

t_stack	*ft_stack_penult(t_stack *stack)
{
	while (stack)
	{
		if (!stack->next->next)
			return (stack);
		stack = stack->next;
	}
	return (stack);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	while (stack)
	{
		if (!stack->next)
			return (stack);
		stack = stack->next;
	}
	return (stack);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (!*stack)
	{
		*stack = new;
	}
	else
	{
		temp = ft_stacklast(*stack);
		temp->next = new;
	}
}

void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

void	ft_stackrmv_back(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp_stack;

	temp_stack = *stack;
	temp = ft_stack_penult(temp_stack);
	free(temp->next);
	temp->next = NULL;
	temp = NULL;
}
