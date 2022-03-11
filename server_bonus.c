/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscot <sscot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:21:12 by sscot             #+#    #+#             */
/*   Updated: 2022/03/11 17:16:29 by sscot            ###   ########.fr       */
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

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_handler(int sig, siginfo_t *info, void *context)
{
	static int	c_pid = 0;
	static int	bite = 0;
	static int	c = 0;

	(void)context;
	if (!c_pid || c_pid != info -> si_pid)
	{
		c_pid = info -> si_pid;
		bite = 0;
		c = 0;
	}
	if (sig == SIGUSR1)
		c += 1 << (7 - bite);
	bite++;
	if (bite == 8)
	{
		if (c != 0)
			ft_putchar_fd(c, 1);
		else
			kill(c_pid, SIGUSR2);
		c = 0;
		bite = 0;
	}
	kill(c_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	a;

	(void)argc;
	(void)argv;
	a.sa_flags = SA_SIGINFO;
	a.sa_sigaction = ft_handler;
	sigaction(SIGUSR1, &a, 0);
	sigaction(SIGUSR2, &a, 0);
	write(1, "PID: ", 6);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
	{
		pause();
	}
	return (0);
}
