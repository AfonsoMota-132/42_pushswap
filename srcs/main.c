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

void	ft_print_moves(t_data *data)
{
	while (data->moves)
	{
		if (data->moves->content == 6)
			ft_printf("ra\n");
		else if (data->moves->content == 5)
			ft_printf("pa\n");
		else if (data->moves->content == 4)
			ft_printf("pb\n");
		data->moves = data->moves->next;
	}
}

int	ft_check_sort(t_data *data)
{
	int	id;

	data->stack_a = data->start_stack_a;
	if (data->stack_a)
	{
		id = 0;
		while (data->stack_a)
		{
			if (data->stack_a->id == id)
				id++;
			else
				return (1);
			data->stack_a = data->stack_a->next;
		}
	}
	data->stack_a = data->start_stack_a;
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;
	char	**temp;

	if (ac >= 2)
	{
		ft_stackchecker(ac, av);
		if (ac == 2)
		{
			temp = ft_split(av[1], ' ');
			data = ft_stack_maker(temp);
			ft_free_split(temp, data->size);
		}
		else
			data = ft_stack_maker((av + 1));
		data->stack_a = data->start_stack_a;
		data->moves = NULL;
		ft_putid(&data);
		ft_radix(&data);
		ft_print_moves(data);
		ft_free(&data);
	}
	else
		ft_printf("Error!\nNot Enough Arguments.\n");
}
