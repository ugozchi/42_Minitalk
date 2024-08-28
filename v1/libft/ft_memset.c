/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:41:58 by uzanchi           #+#    #+#             */
/*   Updated: 2024/05/02 12:42:09 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int value, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *) str)[i] = value;
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char chaine[20];

	printf("La chaine avant memset : %s\n", chaine);

	memset(chaine, 'A', 20);

	printf("La chaine après memset : %s\n", chaine);

	ft_memset(chaine, 'B', 19);

	printf("La chaine apres ft_memset : %s\n", chaine);

	return (0);
}
*/
