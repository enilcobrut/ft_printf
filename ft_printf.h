/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:39:58 by cjunker           #+#    #+#             */
/*   Updated: 2022/04/20 16:02:48 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	checkformat(va_list arg, char c);
int	printchar(int c);
int	printstr(char *str);
int	printnbr(int n);
int	printunsigned(unsigned int n);
int	printhexa(unsigned int n, int upper);
int	printptr(unsigned long n);
int	printpercent(void);

#endif
