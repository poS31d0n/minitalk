/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscot <sscot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:38:34 by sscot             #+#    #+#             */
/*   Updated: 2022/03/03 19:29:48 by sscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *apFormat, ...)
{
	va_list	str;
	int		i;

	va_start(str, apFormat);
	i = ft_format_check(apFormat, str);
	va_end(str);
	return (i);
}
