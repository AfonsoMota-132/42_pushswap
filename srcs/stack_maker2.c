/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_maker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:46:44 by afogonca          #+#    #+#             */
/*   Updated: 2024/11/30 11:46:55 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

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
		{
			return (NULL); // Need to free everything but will do it later
		}
		data->stack_a = data->stack_a->next;
		data->stack_a->id = -1;
		i++;
	}
	data->stack_a->next = NULL;
	data->size = ft_stacklen(data->start_stack_a);
	return (data);
}
