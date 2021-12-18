/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 18:30:15 by shocquen          #+#    #+#             */
/*   Updated: 2021/12/18 16:54:11 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft.h"

static int	ft_error(void)
{
	ft_putstr_fd("The signal cannot be sent to the server\n", 2);
	exit (0);
}

void	post_msg(int pid, char *msg)
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

int64_t 	ft_long_atoi(const char *str)
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

static size_t	intlen(int n)
{
	size_t	count;

	if (n != 0)
		count = 0;
	else
		count = 1;
	while (n)
	{
		n = n / 10;
		++count;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t			len;
	size_t			n_tmp;
	char			*str;

	if (n < 0)
		n_tmp = -(unsigned int)n;
	else
		n_tmp = n;
	if (n < 0)
		len = intlen(n_tmp) + 1;
	else
		len = intlen(n_tmp);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = n_tmp % 10 + '0';
		n_tmp /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}