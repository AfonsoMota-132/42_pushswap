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
	char	**list;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*start_stack_a;
	t_stack	*start_stack_b;

	if (ac >= 2)
	{
		check_int(ac, av);
		list = ft_split(av[1], ' ');
		start_stack_a = stack_maker(list);
		ft_stack_swap(&start_stack_a);
		/*ft_push_stack(&start_stack_b, &start_stack_a);*/
		ft_push_stack(&start_stack_b, &start_stack_a);
		/*ft_stack_swap(&start_stack_b);*/
		/*ft_push_stack(&start_stack_a, &start_stack_b);*/
		/*ft_rrotate_stack(&start_stack_a);*/
		/*start_stack_b = ft_stacknew(0);*/

		stack_b = start_stack_b;

		stack_a = start_stack_a;
		ft_printf("stack a\n");
		while (stack_a)
		{
			ft_printf("%i\n", stack_a->content);
			stack_a = stack_a->next;
		}
		ft_printf("stack b\n");
		while (stack_b)
		{
			ft_printf("%i\n", stack_b->content);
			stack_b = stack_b->next;
		}
	}
	else
		ft_printf("Error!\nNot Enough Arguments.\n");
}
