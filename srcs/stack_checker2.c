/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_checker2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:45:02 by afogonca          #+#    #+#             */
/*   Updated: 2024/12/04 15:51:14 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	has_sign_but_no_nbr(int ac, char **av)
{
	int	i;
	int	j;

	j = 0;
	while (++j < ac)
	{
		i = 0;
		while (av[j][i])
		{
			if ((av[j][i] == '-' || av[j][i] == '+')
				&& !ft_isdigit(av[j][i + 1]))
			{
				ft_printf("Error\n");
				exit (1);
			}
			i++;
		}
	}
	return (0);
}
