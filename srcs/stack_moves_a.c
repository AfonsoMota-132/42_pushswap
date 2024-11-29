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
	int	temp_content;
	int	temp_id;

	(*data)->stack_a = (*data)->start_stack_a;
	temp_content = (*data)->stack_a->content;
	temp_id = (*data)->stack_a->id;
	(*data)->stack_a->content = (*data)->stack_a->next->content;
	(*data)->stack_a->id = (*data)->stack_a->next->id;
	(*data)->stack_a->next->content = temp_content;
	(*data)->stack_a->next->id = temp_id;
	(*data)->start_stack_a = (*data)->stack_a;
}

void	ft_stack_push_a(t_data **data)
{
	/*int	temp_id;*/

	(*data)->stack_a = (*data)->start_stack_a;
	if (!(*data)->start_stack_b)
	{
		(*data)->start_stack_b = ft_stacknew((*data)->stack_a->content);
		(*data)->start_stack_b->next = NULL;
	}
	else
		ft_stackadd_front(&(*data)->start_stack_b, ft_stacknew((*data)->stack_a->content));
	(*data)->stack_b = (*data)->start_stack_b;
	(*data)->start_stack_b->id = (*data)->start_stack_a->id;
	(*data)->stack_a = (*data)->start_stack_a->next;
	ft_stackrmv_front(&(*data)->start_stack_a);
	(*data)->start_stack_a = (*data)->stack_a;
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
}
