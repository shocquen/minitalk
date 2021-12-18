/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:13:15 by shocquen          #+#    #+#             */
/*   Updated: 2021/12/18 17:01:09 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft.h"

static int	ft_is_all_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_is_all_digit(argv[1]))
	{
		ft_putstr_fd("Invalid arguments!\nExpected arguments : <int: PID> <str: message>\n", 2);
		return (0);
	}
	if ( argc == 3 && ft_long_atoi(argv[1]) >= 4294967295)
	{
		ft_putstr_fd("Invalid PID!\n", 2);
		exit (0);
	}
	else
		{
			post_msg(ft_atoi(argv[1]), argv[2]);
			post_msg(ft_atoi(argv[1]), ft_itoa((int)getpid()));
			while (1)
				pause();
		}

	return (0);
}
