/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:02:26 by uzanchi           #+#    #+#             */
/*   Updated: 2024/05/31 12:11:04 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	putchar_count(int c)
{
	write(1, &c, 1);
	return (1);
}

size_t	putstr_count(char *str)
{
	size_t	count;

	if (!str)
	{
		write(1, NULL_DISPLAY, ft_strlen(NULL_DISPLAY));
		return (6);
	}
	count = 0;
	while (*str)
	{
		write(1, str++, 1);
		count++;
	}
	return (count);
}

size_t	putnbr_base10_count(int nbr, char *base)
{
	int		base_length;
	long	long_nbr;
	size_t	count;

	base_length = ft_strlen(base);
	long_nbr = nbr;
	count = 0;
	if (long_nbr < 0)
	{
		count += putchar_count('-');
		long_nbr *= -1;
	}
	if (long_nbr >= base_length)
		count += putnbr_base10_count(long_nbr / base_length, base);
	count += putchar_count(base[long_nbr % base_length]);
	return (count);
}

size_t	put_u_base10_count(unsigned int nbr, char *base)
{
	unsigned long long	lnbr;
	unsigned int		base_length;
	size_t				count;

	lnbr = nbr;
	base_length = ft_strlen(base);
	count = 0;
	if (lnbr >= base_length)
		count += putnbr_base10_count(lnbr / base_length, base);
	count += putchar_count(base[lnbr % base_length]);
	return (count);
}

size_t	putptr_base_count(void *ptr, char *base, int first_loop_flag)
{
	unsigned long long	nbr;
	size_t				base_length;
	size_t				count;

	nbr = (unsigned long long)ptr;
	base_length = ft_strlen(base);
	count = 0;
	if (ptr == NULL)
	{
		count += putstr_count(NIL_DISPLAY);
		return (count);
	}
	if (first_loop_flag == 1)
		count += putstr_count(POINTER_PREFIX);
	if (nbr >= base_length)
		count += putptr_base_count((void *)(nbr / base_length), base, 0);
	count += putchar_count(base[nbr % base_length]);
	return (count);
}
