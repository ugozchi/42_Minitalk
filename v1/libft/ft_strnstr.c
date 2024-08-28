/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:37:13 by uzanchi           #+#    #+#             */
/*   Updated: 2024/05/02 12:37:15 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	char	*big_ptr;

	if (!*little)
		return ((char *) big);
	if (len == 0)
		return (NULL);
	little_len = ft_strlen(little);
	big_ptr = (char *)big;
	while (*big_ptr && len >= little_len)
	{
		if (ft_strncmp(big_ptr, little, little_len) == 0)
			return (big_ptr);
		big_ptr++;
		len--;
	}
	return (NULL);
}
