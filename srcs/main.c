/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:39:05 by afogonca          #+#    #+#             */
/*   Updated: 2024/11/23 11:40:56 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	ft_check_sort(t_data *data)
{
	if (data->stack_a)
	{
		while (data->stack_a)
		{
			if (data->stack_a->content > data->stack_a->next->content)
			{
				ft_printf("a: %i	b: %i\n", data->stack_a->content, data->stack_a->next->content);
				return (1);
			}
			if (!data->stack_a->next->next)
				break ;
			data->stack_a = data->stack_a->next;
		}
	}
	data->stack_a = data->start_stack_a;
	return (0);
}

int	main(int ac, char **av)
{ 
	t_data	*data;

	if (ac >= 2)
	{
		data = malloc(sizeof(t_data));
		ft_stackchecker(ac, av);
		if (ac == 2)
			data = ft_stack_maker(ft_split(av[1], ' '));
		else
			data = ft_stack_maker((av + 1));	
		data->stack_a = data->start_stack_a;
		data->size = ft_stacklen(data->start_stack_a);
		/*ft_stack_swap_a(&data);*/
		ft_stack_push_a(&data);
		ft_stack_push_a(&data);
		/*ft_stack_rotate_a(&data);*/
		/*ft_stack_rrotate_a(&data);*/

		data->stack_a = data->start_stack_a;
		ft_printf("stack a\n");
		while (data->stack_a)
		{
			ft_printf("content: %i	id: %i\n", data->stack_a->content, data->stack_a->id);
			data->stack_a = data->stack_a->next;
		}	
		data->stack_b = data->start_stack_b;
		ft_printf("stack b\n");
		while (data->stack_b)
		{
			ft_printf("content: %i	id: %i\n", data->stack_b->content, data->stack_b->id);
			data->stack_b = data->stack_b->next;
		}	
	}
	else
		ft_printf("Error!\nNot Enough Arguments.\n");
}
