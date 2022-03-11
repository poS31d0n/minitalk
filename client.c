/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjanis <hjanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:06:49 by hjanis            #+#    #+#             */
/*   Updated: 2022/03/11 14:52:42 by hjanis           ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	long int	num;
	int			i;
	long int	minus;

	minus = 1;
	i = 0;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num * minus > 2147483647)
			return (-1);
		if (num * minus < -2147483648)
			return (0);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(minus * num));
}

void	convert(int c, int pid)
{
	int	i;

	i = 8;
	while (--i >= 0)
	{
		if (c >> i & 1)
		{
			kill(pid, SIGUSR1);
			usleep (500);
		}
		else
		{
			kill(pid, SIGUSR2);
			usleep (500);
		}
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	int					i;

	i = 0;
	pid = ft_atoi(argv[1]);
	if (argc == 3 && pid != 0 && pid > 0)
	{
		while (argv[2][i])
		{
			convert((int)argv[2][i], pid);
			i++;
		}
		convert(0, pid);
	}
	else
		write(1, "Usage: ./client [PID] [STRING_TO_PASS], or Invalid Pid\n", 56);
	return (0);
}
