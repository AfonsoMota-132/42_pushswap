/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:40:07 by afogonca          #+#    #+#             */
/*   Updated: 2024/12/03 14:48:11 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	ft_check_null(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (av[i][0] == '\0')
		{
			ft_printf("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}

t_data	*ft_initial(int ac, char **av)
{
	t_data	*data;
	char	**temp;

	if (ac == 2 && av[1][0] != '\0')
	{
		temp = ft_split(av[1], ' ');
		data = ft_stack_maker(temp);
		ft_free_split(temp, data->size);
	}
	else if (ac == 2 && av[1][0] == '\0')
	{
		ft_printf("Error\n");
		ft_free_args(av);
		return (NULL);
	}
	else
	{
		if (ft_check_null(ac, av))
			return (NULL);
		data = ft_stack_maker((av + 1));
	}
	return (data);
}

t_data	*ft_initial_data(int ac, char **av)
{
	t_data	*data;

	av = ft_trim_args(ac, av);
	data = ft_initial(ac, av);
	if (!data)
		exit (1);
	data->stack_a = data->start_stack_a;
	data->start_stack_b = NULL;
	if (ft_stackchecker(ac, av, data) || check_repeat(data->stack_a))
	{
		ft_free(&data);
		ft_free_args(av);
		exit (1);
	}
	data->stack_a = data->start_stack_a;
	ft_free_args(av);
	return (data);
}
