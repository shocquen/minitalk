/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:13:15 by shocquen          #+#    #+#             */
/*   Updated: 2021/12/16 18:23:56 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "minitalk.h"

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

static int	ft_error(void)
{
	ft_print_err("The signal cannot be sent to the server\n");
	exit (0);
}

static void	post_msg(int pid, char *msg)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = ft_strlen(msg);
	while (i <= size)
	{
		j = 7;
		while (j > -1)
		{
			if ((msg[i] >> j) & 1)
				if (kill(pid, SIGUSR1) < 0)
					ft_error();
			if (!((msg[i] >> j) & 1))
				if (kill(pid, SIGUSR2) < 0)
					ft_error();
			j--;
			usleep(500);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_is_all_digit(argv[1]))
	{
		ft_print_err("Invalid arguments!\nExpected arguments : <int: PID> <str: message>\n");
		return (0);
	}
	if ( argc == 3 && ft_atoi(argv[1]) >= 4294967295)
	{
		ft_print_err("Invalid PID!\n");
		exit (0);
	}
	else
		post_msg(ft_atoi(argv[1]), argv[2]);
	return (0);
}