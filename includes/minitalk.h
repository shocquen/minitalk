/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:06:51 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/03 10:40:41 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define MAX_PID 4194304

# include <signal.h>
# include <sys/signal.h>
# include <stddef.h>

void	post_msg(int pid, char *msg);
int64_t	ft_long_atoi(const char *str);
int		ft_isdigit(int c);
char	*ft_itoa(int n);

#endif