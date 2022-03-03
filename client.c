/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscot <sscot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:58:43 by sscot             #+#    #+#             */
/*   Updated: 2022/03/03 19:29:20 by sscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	z;
	int	num;

	z = 1;
	num = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
		z = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - 48;
		str++;
	}
	return (num * z);
}

void	send(unsigned char c, int pid)
{
	int	i;
	int	mass[8];

	i = 0;
	while (c > 0)
	{
		if (c % 2 == 1)
			mass[7 - i] = 1;
		else
			mass[7 - i] = 0;
		c /= 2;
		i++;
	}
	i = 0;
	while (i != 8)
	{
		if (mass[i] == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep (1000);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	(void)argc;
	i = 0;
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		send(argv[2][i], pid);
		i++;
	}
}
