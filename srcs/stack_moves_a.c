/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:29:05 by afogonca          #+#    #+#             */
/*   Updated: 2024/11/28 20:32:15 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ft_stack_swap_a(t_data **data)
{
	t_stack	*temp1;
	t_stack *temp2;

	temp1 = (*data)->start_stack_a;
	temp2 = temp1->next;
	temp1->next = temp2->next;
	temp2->next = temp1;
	(*data)->start_stack_a = temp2;
}

void	ft_stack_push_a(t_data **data)
{
	if (!(*data)->start_stack_b)
	{
		(*data)->start_stack_b = ft_stacknew((*data)->stack_a->content);
		(*data)->start_stack_b->next = NULL;
	}
	else
	{
		ft_stackadd_front(&(*data)->start_stack_b,
			ft_stacknew((*data)->stack_a->content));
	}
	(*data)->start_stack_b->id = (*data)->start_stack_a->id;
	(*data)->stack_a = (*data)->start_stack_a->next;
	ft_stackrmv_front(&(*data)->start_stack_a);
	(*data)->start_stack_a = (*data)->stack_a;
	ft_stackadd_back(&(*data)->moves, ft_stacknew(4));
}

void	ft_stack_rotate_a(t_data **data)
{
	int	temp_cont;
	int	temp_id;

	(*data)->stack_a = (*data)->start_stack_a;
	if (!(*data)->stack_a->next)
		return ;
	temp_cont = (*data)->stack_a->content;
	temp_id = (*data)->stack_a->id;
	ft_stackrmv_front(&(*data)->stack_a);
	ft_stackadd_back(&(*data)->stack_a, ft_stacknew(temp_cont));
	(*data)->start_stack_a = (*data)->stack_a;
	ft_stacklast((*data)->stack_a)->id = temp_id;
	ft_stackadd_back(&(*data)->moves, ft_stacknew(6));
}

void	ft_stack_rrotate_a(t_data **data)
{
	int	temp_cont;
	int	temp_id;

	(*data)->stack_a = (*data)->start_stack_a;
	if (!(*data)->stack_a->next)
		return ;
	temp_cont = ft_stacklast((*data)->stack_a)->content;
	temp_id = ft_stacklast((*data)->stack_a)->id;
	ft_stackrmv_back(&(*data)->stack_a);
	ft_stackadd_front(&(*data)->stack_a, ft_stacknew(temp_cont));
	(*data)->start_stack_a = (*data)->stack_a;
	(*data)->stack_a->id = temp_id;
	ft_stackadd_back(&(*data)->moves, ft_stacknew(9));
}
