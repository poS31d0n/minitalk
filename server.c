/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjanis <hjanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:13:06 by hjanis            #+#    #+#             */
/*   Updated: 2022/03/11 14:42:16 by hjanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	sig_handler(int act)
{
	static int	bit;
	static int	c;

	if (act == SIGUSR1)
		c += 1 << (7 - bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	action;

	(void)argv;
	action.sa_handler = &sig_handler;
	if (argc == 1)
	{
		write(1, "PID: ", 6);
		ft_putnbr(getpid());
		write(1, "\n", 1);
		while (42)
		{
			sigaction(SIGUSR1, &action, NULL);
			sigaction(SIGUSR2, &action, NULL);
			pause();
		}
	}
	return (0);
}
