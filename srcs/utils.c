/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 18:30:15 by shocquen          #+#    #+#             */
/*   Updated: 2021/12/16 17:19:47 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "ft_printf.h"

void	ft_print_err(char *str)
{
		write(2, str, ft_strlen(str));
}
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int64_t 	ft_atoi(const char *str)
{
	int64_t	nb;
	int				sign;

	sign = 1;
	while (*str && ((*str >= '\t' && *str <= '\r') || (*str == ' ')))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	nb = 0;
	while (*str && ft_isdigit(*str))
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (nb * sign);
}

