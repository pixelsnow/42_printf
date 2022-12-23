/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:39:41 by vvagapov          #+#    #+#             */
/*   Updated: 2022/12/23 18:52:26 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

int	print_char(char c);
int	print_string(char *s);
int	print_int(int n);
int	print_unsigned(unsigned int n);
int	print_hex_char(char n, int lowercase);
int	print_hex(unsigned int n, int lowercase);
int	print_pointer(void *p);
int	ft_printf(const char *template, ...);

#endif