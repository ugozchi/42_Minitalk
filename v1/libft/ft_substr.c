/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:33:59 by uzanchi           #+#    #+#             */
/*   Updated: 2024/05/02 12:34:02 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*output;
	char	*output_ptr;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		output = malloc(1 * sizeof(char));
		if (!output)
			return (NULL);
		*output = '\0';
		return (output);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	output = malloc((len + 1) * sizeof(char));
	if (!output)
		return (NULL);
	output_ptr = output;
	s += start;
	while (*s && len--)
		*output_ptr++ = *s++;
	*output_ptr = '\0';
	return (output);
}
/*
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s1;
	unsigned int	s1_len;
	unsigned int	s2_len;

	if (!s)
		return (0);
	s1_len = (int)len;
	s2_len = ft_strlen(s);
	if (start > s2_len)
		s1_len = 0;
	if (ft_strlen(s + start) < len)
		s1_len = ft_strlen(s + start);
	s1 = ft_calloc(s1_len + 1, sizeof(char));
	if (!s1)
		return (0);
	if (start > s2_len)
		return (s1);
	ft_strlcpy(s1, &((char *)s)[start], s1_len + 1);
	return (s1);
}
*/
