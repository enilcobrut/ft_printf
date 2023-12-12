/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:18:58 by cjunker           #+#    #+#             */
/*   Updated: 2022/04/20 15:13:02 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printnbr(int n)
{
	if (n == -2147483648)
		return (printstr("-2147483648"));
	else if (n < 0)
		return (printchar('-') + printnbr(-n));
	else if (n > 9)
		return (printnbr(n / 10) + printnbr(n % 10));
	else
		return (printchar(n + '0'));
}

int	printhexa(unsigned int n, int upper)
{
	char	*base;

	base = "0123456789abcdef";
	if (upper)
		base = "0123456789ABCDEF";
	if (n < 16)
		return (printchar(base[n]));
	else
		return (printhexa(n / 16, upper) + printhexa(n % 16, upper));
}

int	printunsigned(unsigned int n)
{
	if (n > 9)
		return (printunsigned(n / 10) + printunsigned(n % 10));
	else
		return (printchar(n + '0'));
}

int	printptr(unsigned long n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n < 16)
		return (printchar(base[n]));
	else
		return (printptr(n / 16) + printptr(n % 16));
}
