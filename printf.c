/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:39:30 by vvagapov          #+#    #+#             */
/*   Updated: 2022/12/21 23:40:41 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
#include <limits.h>

static int	print_char(char c)
{
	return (write(1, &c, 1));
}

static int	print_hex_char(char n, int lowercase)
{
	if (n < 10)
		return print_char('0' + n);
	else
		return print_char('A' - 10 + n + lowercase * ('a' - 'A'));
}

static int	print_hex(unsigned int n, int lowercase)
{
	if (n < 16)
		return print_hex_char(n, lowercase);	
	else
		return (print_hex(n / 16, lowercase) + print_hex_char(n % 16, lowercase));
}

static int	print_unsigned(unsigned int n)
{
	if (n < 10)
		return print_char('0' + n);
	else
		return (print_unsigned(n / 10) + print_char('0' + n % 10));
}

static int	print_int(int n)
{
	int	additional_char;

	additional_char = 0; 
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putstr_fd("-2147483648", 1);
			return (11);
		}
		ft_putchar_fd('-', 1);
		n *= -1;
		additional_char = 1;
	}
	if (n < 10)
		return print_char('0' + n);
	else
		return (print_int(n / 10) + print_char('0' + n % 10));
}

static int print_long_hex(unsigned long int n)
{
	if (n < 16)
		return print_hex_char(n, 1);	
	else
		return (print_long_hex(n / 16) + print_hex_char(n % 16, 1));
}

static int print_pointer(void * p)
{
	ft_putstr_fd("0x", 1);
	return (2 + print_long_hex((unsigned long int)p));
}

static int	handle_arg(char type, va_list ap)
{
	int	arg_len;

	arg_len = 0;
	if (type == 'c')
		arg_len += print_char(va_arg(ap, int));
	else if (type == 'd' || type == 'i')
		arg_len += print_int(va_arg(ap, int));
	else if (type == 'u')
		arg_len += print_unsigned(va_arg(ap, unsigned int));
	else if (type == 'x')
		arg_len += print_hex(va_arg(ap, unsigned int), 1);
	else if (type == 'X')
		arg_len += print_hex(va_arg(ap, unsigned int), 0);
	else if (type == '%')
		arg_len += print_char('%');
	else if (type == 'p')
		arg_len += print_pointer(va_arg(ap, void *));
	return (arg_len);
}

static int	parse_args(const char *template, va_list ap)
{
	size_t	i;
	int		res_len;

	res_len = 0;
	i = 0;
	while (template[i])
	{
		if (template[i] != '%')
			res_len += print_char(template[i]);
		else
		{
			i++;
			res_len += handle_arg(template[i], ap);
		}
		i++;
	}
	return (res_len);
}

static int	ft_printf(const char *template, ...)
{
	va_list	ap;
	int		res_len;

	va_start(ap, template);
	res_len = parse_args(template, ap);
	va_end(ap);
	return (res_len);
}

int	main(void)
{
	int len;
	int a;

	len = printf("%x\n", 6171407048);
	printf("%d\n", len);
	len = ft_printf("%x\n", 6171407048);
	printf("%d\n", len);
}

// INTERSTING TEST CASES
/*
ft_printf("%\n");
*/