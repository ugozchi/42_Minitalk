/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:39:11 by uzanchi           #+#    #+#             */
/*   Updated: 2024/05/02 12:39:12 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	words_count(const char *s, char c)
{
	size_t	count;
	int		previous_is_c;

	count = 0;
	previous_is_c = 1;
	if (s == NULL)
		return (0);
	while (*s)
	{
		if (*s != c && previous_is_c)
		{
			count++;
			previous_is_c = 0;
		}
		if (*s == c)
			previous_is_c = 1;
		s++;
	}
	return (count);
}

static size_t	word_length(const char *s, char c)
{
	size_t	length;

	length = 0;
	while (*s && *s != c)
	{
		length++;
		s++;
	}
	return (length);
}

static int	write_word(const char *src, char **dest, char c)
{
	char	*tmp;

	*dest = malloc((word_length(src, c) + 1) * sizeof(char));
	if (*dest == NULL)
		return (0);
	tmp = *dest;
	while (*src && *src != c)
		*tmp++ = *src++;
	*tmp = '\0';
	return (1);
}

static void	free_output(char **output, char **ptr)
{
	while (ptr-- != output)
		free(*ptr);
	free(output);
}

char	**ft_split(char const *s, char c)
{
	char	**output;
	char	**ptr;
	size_t	count;

	count = words_count(s, c);
	output = malloc((count + 1) * sizeof(char *));
	if (output == NULL || s == NULL)
		return (NULL);
	ptr = output;
	while (*s == c)
		s++;
	while (count--)
	{
		if (write_word(s, ptr, c) == 0)
		{
			free_output(output, ptr);
			return (NULL);
		}
		s += word_length(s, c);
		while (*s == c)
			s++;
		ptr++;
	}
	*ptr = NULL;
	return (output);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*str;
	char	charset;
	char	**substrs;
	int		i;

	str = "Ha ic b";
	charset = ' ';
	substrs = ft_split(str, charset);
	i = 0;
	while (i < 3)
	{
		printf("%s\n", substrs[i]);
		i++;
	}
	return (0);
}
*/
