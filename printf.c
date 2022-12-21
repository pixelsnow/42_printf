/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:39:30 by vvagapov          #+#    #+#             */
/*   Updated: 2022/12/21 20:04:02 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

static size_t count_args(const char *template)
{
	size_t	count;
	size_t	i;

	if (!template)
		return (0);
	i = 0;
	count = 0;
	while(template[i])
	{
		
	}
}

int	ft_printf(const char *template, ...)
{
	va_list	ap;
	size_t	arg_count;
	char 	*res;

	va_start(ap, template);
	arg_count = count_args(template);

	for (int i = 0; i < n; i++)
		sum += va_arg(ap, int);
	va_end(ap);
	return (sum);
}

int	main(void)
{
	printf("%d\n", ft_printf("%c", 'g'));
}