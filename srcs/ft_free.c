/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 10:26:57 by afogonca          #+#    #+#             */
/*   Updated: 2024/11/30 10:30:24 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"
void	ft_free_stack_a(t_data **data)
{
	if ((*data)->start_stack_a)
	{
		while ((*data)->start_stack_a)
		{
			(*data)->stack_a = (*data)->start_stack_a;
			(*data)->start_stack_a = (*data)->stack_a->next;
			free((*data)->stack_a);
		}
		free((*data)->start_stack_a);
	}

}

void	ft_free_stack_b(t_data **data)
{
	if ((*data)->start_stack_b)
	{
		while ((*data)->start_stack_b)
		{
			(*data)->stack_b = (*data)->start_stack_b;
			(*data)->start_stack_b = (*data)->stack_b->next;
			free((*data)->stack_b);
		}
		free((*data)->start_stack_b);
	}
}
void	ft_free(t_data **data)
{
	t_stack	*stack;
	ft_free_stack_a(data);
	ft_free_stack_b(data);
	if ((*data)->moves)
	{
		while ((*data)->moves)
		{
			stack = (*data)->moves;
			(*data)->moves = (*data)->moves->next;
			free(stack);
		}
		free((*data)->moves);
	}
	free((*data));
}
