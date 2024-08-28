/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:35:11 by uzanchi           #+#    #+#             */
/*   Updated: 2024/05/02 12:35:15 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*output;

	if (!s1 || !s2)
		return (NULL);
	output = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!output)
		return (NULL);
	ft_memcpy(output, s1, ft_strlen(s1));
	ft_memcpy(output + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (output);
}
