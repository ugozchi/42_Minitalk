/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:25:50 by uzanchi           #+#    #+#             */
/*   Updated: 2024/05/02 12:26:43 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int main() {
    char src[] = "Hello, world!";
    char dest[20]; 
    char src1[] = "Petite merde !";

    printf("Destination avant copie: %s\n", dest);
    memcpy(dest, src, strlen(src) + 1);

    printf("Copie avec memcpy de la bibliothèque standard C :\n");
    printf("Source : %s\n", src);
    printf("Destination : %s\n", dest);

 	printf("\nDestination avant copie: %s\n", dest);
    ft_memcpy(dest, src1, ft_strlen(src1) + 1);

    printf("Copie avec ft_memcpy de votre bibliothèque :\n");
    printf("Source : %s\n", src1);
    printf("Destination : %s\n", dest);

    return 0;
}
*/
