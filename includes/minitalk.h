/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:06:51 by shocquen          #+#    #+#             */
/*   Updated: 2021/12/16 16:37:15 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#	define MINITALK_H

# define MAX_PID 4194304

# include <signal.h>
# include <sys/signal.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

void ft_print_err(char *str);
int64_t	ft_atoi(const char *str);
int		ft_isdigit(int c);

#endif