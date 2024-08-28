/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:42:26 by uzanchi           #+#    #+#             */
/*   Updated: 2024/05/02 12:42:27 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t length)
{
	if (!((char *)dest) && !((char *)src))
		return (0);
	if (dest > src)
	{
		while (length > 0)
		{
			((char *)dest)[length - 1] = ((char *)src)[length - 1];
			length--;
		}
	}
	else
		ft_memcpy(((char *)dest), ((char *)src), length);
	return (((char *)dest));
}
/*
#include <stdio.h>

int main()
{
    char str[] = "Bonjour";
    char dest[20]; 
	
    printf("Destination avant : %s\n", dest);
    ft_memmove(dest, str, ft_strlen(str) + 1); 
    printf("Déplacement avec ft_memmove de votre bibliothèque :\n");
    printf("Source : %s\n", str);
    printf("Destination : %s\n", dest);

    return 0;
}
*/
