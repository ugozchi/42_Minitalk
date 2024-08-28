/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:31:25 by uzanchi           #+#    #+#             */
/*   Updated: 2024/05/02 12:31:29 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	length;

	length = 0;
	while (src[length])
		length++;
	if (size == 0)
		return (length);
	while (--size && *src)
		*(dest++) = *(src++);
	*dest = '\0';
	return (length);
}
/*
#include <stdio.h>

int	main()
{
	const char src[] = "Rien !";
	char dest[] = "Je cache quoi ?";

	printf("Avant strlcpy :\n%s\n", dest);
	ft_strlcpy(dest, src, 17);
	printf("Apres strlcpy :\n%s\n", dest);
}
*/
