/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:28:05 by vvagapov          #+#    #+#             */
/*   Updated: 2022/12/23 18:31:00 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	print_unsigned(unsigned int n)
{
	if (n < 10)
		return (print_char('0' + n));
	else
		return (print_unsigned(n / 10) + print_char('0' + n % 10));
}