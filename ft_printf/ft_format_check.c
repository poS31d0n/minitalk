/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscot <sscot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:38:24 by sscot             #+#    #+#             */
/*   Updated: 2022/03/03 19:29:52 by sscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_nomber_format(char apFormat, va_list str)
{
	if (apFormat == '%')
		return (ft_putchar('%'));
	else if (apFormat == 'c')
		return (ft_putchar(va_arg(str, int)));
	else if (apFormat == 's' )
		return (ft_putstr(va_arg(str, char *)));
	else if (apFormat == 'd' || apFormat == 'i')
		return (ft_putnbr(va_arg(str, int)));
	else if (apFormat == 'u')
		return (ft_putnbr_new(va_arg(str, unsigned int)));
	else if (apFormat == 'p')
		return (ft_putnbr_point(va_arg(str, unsigned long)));
	else if (apFormat == 'x')
		return (ft_putnbr_low(va_arg(str, unsigned long)));
	else if (apFormat == 'X')
		return (ft_putnbr_up(va_arg(str, unsigned long)));
	return (0);
}

int	ft_format_check(const char *apFormat, va_list str)
{
	int	i;
	int	result;

	if (!apFormat)
		return (0);
	i = 0;
	result = 0;
	while (apFormat[i])
	{
		if (apFormat[i] != '%')
			result += write(1, apFormat + i, 1);
		if (apFormat[i] == '%')
		{
			result += ft_get_nomber_format(apFormat[i + 1], str);
			i++;
		}
		i++;
	}
	return (result);
}
