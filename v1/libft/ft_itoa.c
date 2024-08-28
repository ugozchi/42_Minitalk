/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:41:07 by uzanchi           #+#    #+#             */
/*   Updated: 2024/05/02 12:41:48 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_number_length(int n)
{
	size_t	length;

	if (n > 0)
		length = 0;
	else
		length = 1;
	while (n)
	{
		length++;
		n /= 10;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	int		length;
	char	*output;
	long	long_n;

	length = get_number_length(n);
	output = malloc((length + 1) * sizeof(char));
	if (output == NULL)
		return (NULL);
	long_n = n;
	if (long_n < 0)
		long_n *= -1;
	output[length] = '\0';
	while (--length >= 0)
	{
		output[length] = long_n % 10 + '0';
		long_n /= 10;
	}
	if (n < 0)
		output[0] = '-';
	return (output);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	printf("%s\n", ft_itoa(atoi(av[1])));
	printf("Correct car on utilise %%s pour afficher le nombre :)\n");
}
*/
