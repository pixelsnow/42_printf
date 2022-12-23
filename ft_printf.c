/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:39:30 by vvagapov          #+#    #+#             */
/*   Updated: 2022/12/23 21:38:10 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Takes a type indicator and an argument list,
// Depending on the type indicator calls a corresponding printing function
static int	handle_arg(char type, va_list ap)
{
	int	arg_len;

	arg_len = 0;
	if (type == 'c')
		arg_len += print_char(va_arg(ap, int));
	else if (type == 's')
		arg_len += print_string(va_arg(ap, char *));
	else if (type == 'p')
		arg_len += print_pointer(va_arg(ap, void *));
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
	return (arg_len);
}

// Depermines whether a character corresponds to one of the supported types
static int	is_valid_type(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%');
}

// Parses the template string and sends type indicators and an argument list
// to be handled by handle_arg()
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
		else if (is_valid_type(template[i + 1]))
		{
			res_len += handle_arg(template[i + 1], ap);
			i++;
		}
		i++;
	}
	return (res_len);
}

int	ft_printf(const char *template, ...)
{
	va_list	ap;
	int		res_len;

	va_start(ap, template);
	res_len = parse_args(template, ap);
	va_end(ap);
	return (res_len);
}
