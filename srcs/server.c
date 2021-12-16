/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:04:38 by shocquen          #+#    #+#             */
/*   Updated: 2021/12/16 17:43:30 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "ft_printf.h"

static void get_chr(int sig)
{
	static int	size = 8;
	static char	chr = 0x00;

	while (--size < 0)
	{
		if (sig == SIGUSR1)
			chr += (1 << size);
	}
	ft_printf("%c", chr);
	size = 8;
	chr = 0x00;
}

int	main(void)
{
	ft_printf("PID: %d!\n", getpid());
	signal(SIGUSR1, get_chr);
	signal(SIGUSR2, get_chr);
	while (1)
		pause();
	return (0);
}
