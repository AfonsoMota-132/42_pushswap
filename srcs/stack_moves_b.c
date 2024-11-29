/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:06:42 by afogonca          #+#    #+#             */
/*   Updated: 2024/11/29 09:11:09 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ft_stack_swap_b(t_data **data)
{
	int	temp_content;
	int	temp_id;

	(*data)->stack_b = (*data)->start_stack_b;
	temp_content = (*data)->stack_b->content;
	temp_id = (*data)->stack_b->id;
	(*data)->stack_b->content = (*data)->stack_b->next->content;
	(*data)->stack_b->id = (*data)->stack_b->next->id;
	(*data)->stack_b->next->content = temp_content;
	(*data)->stack_b->next->id = temp_id;
}

void	ft_stack_push_b(t_data **data)
{
	(*data)->stack_b = (*data)->start_stack_b;
	if (!(*data)->start_stack_a)
	{
		(*data)->start_stack_a = ft_stacknew((*data)->stack_b->content);
		(*data)->start_stack_a->next = NULL;
	}
	else
		ft_stackadd_front(&(*data)->start_stack_a, ft_stacknew((*data)->stack_b->content));
	(*data)->stack_a = (*data)->start_stack_a;
	(*data)->start_stack_a->id = (*data)->start_stack_b->id;
	(*data)->stack_b = (*data)->start_stack_b->next;
	ft_stackrmv_front(&(*data)->start_stack_b);
	(*data)->start_stack_b = (*data)->stack_b;
}
