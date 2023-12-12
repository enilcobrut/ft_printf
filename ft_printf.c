/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:29:07 by cjunker           #+#    #+#             */
/*   Updated: 2022/04/20 15:59:05 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	checkformat(va_list param, char c)
{
	int	nbchars;

	nbchars = 0;
	if (c == 'c')
		nbchars += printchar(va_arg(param, int));
	else if (c == 's')
		nbchars += printstr(va_arg(param, char *));
	else if (c == 'p')
		nbchars += printstr("0x") + printptr(va_arg(param, unsigned long));
	else if (c == 'd' || c == 'i')
		nbchars += printnbr(va_arg(param, int));
	else if (c == 'u')
		nbchars += printunsigned(va_arg(param, unsigned int));
	else if (c == 'x')
		nbchars += printhexa(va_arg(param, unsigned int), 0);
	else if (c == 'X')
		nbchars += printhexa(va_arg(param, unsigned int), 1);
	else if (c == '%')
	{
		write(1, "%", 1);
		nbchars++;
	}
	return (nbchars);
}

int	ft_printf(const char *str, ...)
{
	va_list	param;
	int		nbchars;
	int		i;

	i = 0;
	va_start(param, str);
	nbchars = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			nbchars += checkformat(param, str[i + 1]);
			i++;
		}
		else
			nbchars += printchar(str[i]);
		i++;
	}
	va_end(param);
	return (nbchars);
}
