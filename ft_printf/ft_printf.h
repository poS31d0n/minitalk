/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscot <sscot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:38:53 by sscot             #+#    #+#             */
/*   Updated: 2022/03/03 19:29:43 by sscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}						t_list;

size_t	ft_strlen(const char *s);
int		ft_putchar(char c);
int		ft_putnbr_low(unsigned int n);
int		ft_putnbr_new(unsigned int number);
int		ft_putnbr_point(size_t n);
int		ft_putnbr_up(unsigned int n);
int		ft_putnbr(int number);
int		ft_putstr(char *s);

int		ft_format_check(const char *apFormat, va_list str);
int		ft_printf(const char *apFormat, ...);

#endif
