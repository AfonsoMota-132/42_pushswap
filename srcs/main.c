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
	if (ac >= 2)
	{
		check_int(ac, av);

	}
	else
		ft_printf("Error!\nNot Enough Arguments.\n");
}
