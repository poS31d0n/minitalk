/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscot <sscot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:59:05 by sscot             #+#    #+#             */
/*   Updated: 2022/03/03 19:29:14 by sscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include "ft_printf/ft_printf.h"

void	sig_handler(int act);
void	ft_putchar_fd(char c, int fd);
int		ft_atoi(const char *str);
void	send(unsigned char c, int pid);
#endif
