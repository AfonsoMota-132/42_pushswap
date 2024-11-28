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
	new->next= *stack;
	*stack = new;
}

void	ft_stackrmv_back(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp_stack;

	temp_stack = *stack;
	temp = ft_stack_penult(temp_stack);
	temp->next = NULL;
}
void	ft_stackrmv_front(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

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

t_data	*ft_stack_maker(char **list_char)
{
	int		i;
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->start_stack_a = ft_stacknew(ft_atoi(list_char[0]));
	if (!data->start_stack_a)
		return (NULL);
	data->stack_a = data->start_stack_a;
	data->stack_a->id = -1;
	i = 1;
	while (list_char[i] != 0)
	{
		data->stack_a->next = ft_stacknew(ft_atoi(list_char[i]));
		if (!data->stack_a->next)
			return (NULL); // Need to free everything but will do it later
		data->stack_a = data->stack_a->next;
		data->stack_a->id = -1;
		i++;
	}
	data->stack_a->next = NULL;
	return (data);
}
