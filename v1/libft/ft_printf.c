/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:04:09 by uzanchi           #+#    #+#             */
/*   Updated: 2024/07/03 11:39:43 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	display_data(char specifier, va_list args)
{
	size_t	count;

	count = 0;
	if (specifier == 'c')
		count = putchar_count(va_arg(args, int));
	else if (specifier == 's')
		count = putstr_count(va_arg(args, char *));
	else if (specifier == 'p')
		count = putptr_base_count(va_arg(args, void *), HEX_BASE_LOW, 1);
	else if (specifier == 'd' || specifier == 'i')
		count = putnbr_base10_count(va_arg(args, int), DEC_BASE);
	else if (specifier == 'u')
		count = put_u_base10_count(va_arg(args, unsigned int), DEC_BASE);
	else if (specifier == 'x')
		count = put_u_base10_count(va_arg(args, unsigned int), HEX_BASE_LOW);
	else if (specifier == 'X')
		count = put_u_base10_count(va_arg(args, unsigned int), HEX_BASE_HIGH);
	else if (specifier == '%')
		count = putchar_count('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	printed_count;
	size_t	i;

	i = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	printed_count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '\0')
			return (-1);
		if (str[i] == '%')
		{
			printed_count += display_data(str[++i], args);
			i++;
		}
		else
			printed_count += putchar_count(str[i++]);
	}
	va_end(args);
	return (printed_count);
}
