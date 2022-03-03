/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscot <sscot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:39:31 by sscot             #+#    #+#             */
/*   Updated: 2022/01/13 13:48:53 by sscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_size(long n)
{
	int	size;

	size = 0;
	if (n <= 0)
	{
		n = n * (-1);
		size++;
	}
	while (n)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static char	*ft_itoa(int n)
{
	char	*result;
	int		i;
	long	number;

	number = n;
	i = get_size(number);
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	result[i] = '\0';
	if (number == 0)
		result[0] = '0';
	if (number < 0)
	{
		result[0] = '-';
		number = number * (-1);
	}
	while (number > 0)
	{
		i--;
		result[i] = (number % 10) + '0';
		number = number / 10;
	}
	return (result);
}

int	ft_putnbr(int number)
{
	char	*res;
	int		i;

	res = ft_itoa(number);
	if (!res)
		return (0);
	i = ft_strlen(res);
	ft_putstr(res);
	free(res);
	return (i);
}
