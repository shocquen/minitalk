/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:43:04 by shocquen          #+#    #+#             */
/*   Updated: 2021/12/18 12:36:05 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_handler {
	int		(*f)(va_list data);
	char	ctx;
}	t_handler;

void	ft_putnbr_base(size_t nbr, const char *base);
int		ft_lennb(int nb);
int		ft_lennb_unsigned(unsigned long long int nb, int base);
int		ft_print_c(va_list args);
int		ft_print_s(va_list args);
int		ft_print_p(va_list args);
int		ft_print_di(va_list args);
int		ft_print_u(va_list args);
int		ft_print_x(va_list args); //todo fix here
int		ft_print_cap_x(va_list args);
int		ft_print_percent(va_list args);
int		ft_printf(const char *str, ...);

#endif