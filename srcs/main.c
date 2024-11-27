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

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac >= 2)
	{
		ft_stackchecker(ac, av);
		if (ac == 2)
			data->start_stack_a = ft_stack_maker(ft_split(av[1], ' '));
		else
			data->start_stack_a = ft_stack_maker((av + 1));
		data->stack_a = data->start_stack_a;
	}
	else
		ft_printf("Error!\nNot Enough Arguments.\n");
}
