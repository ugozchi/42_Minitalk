/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 22:49:23 by uzanchi           #+#    #+#             */
/*   Updated: 2024/05/29 23:46:56 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Ici on va avoir la fonction qui va nous permettre de free notre
  reserve/archive ca va permettre de modifier ce qu'il y a dans archive
  plus proprement en creant des temporaires pour stocker ce qu'il y a dedans
  puis en reimplementant avec un nouveau malloc ce qu'on avait stocke
  dans le temp/buffer*/
static char	*free_archive(char **archive)
{
	if (*archive)
	{
		free(*archive);
		*archive = NULL;
	}
	return (NULL);
}

/*Ici on joint ce qu'il y a deja dans archive (ou qu'il n'y a pas encore)
  avec le buffer. On va coller ce qui est stocker dans le buffer a la suite
  de ce qu'il ya dans archive. On va free l'ancienne archive avant de
  l'implementer a nouveau avec tout ce dont on a besoin*/
static void	join_archive_and_buffer(char **archive, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(*archive, buffer);
	free_archive(archive);
	*archive = temp;
}

/*On va essayer de trouver la premiere occurence de '\n' et return tous les
  charactere avant celui-ci. Enfin on va supprimer tout ce qu'il y a dans avnt
  le '\n' et le '\n' en lui meme de archive. Dans l'hypothese ou il n'y aurait
  pas de '\n' alors on retourne archive et on la free*/
static char	*extract_line(char **archive)
{
	size_t	length;
	char	*line;
	char	*temp;

	if (ft_strchr(*archive, '\n'))
		length = ft_strchr(*archive, '\n') - *archive + 1;
	else
		length = ft_strlen(*archive);
	line = malloc((length + 1) * sizeof (char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, *archive, length + 1);
	if (ft_strchr(*archive, '\n'))
	{
		temp = ft_strjoin(ft_strchr(*archive, '\n') + 1, "");
		free_archive(archive);
		*archive = temp;
	}
	else
		free_archive(archive);
	return (line);
}

/**/
char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*archive = NULL;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX - 1)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if (!archive)
			archive = ft_strjoin("", buffer);
		else
			join_archive_and_buffer(&archive, buffer);
		if (ft_strchr(archive, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (bytes_read == -1 || !archive || !*archive)
		return (free_archive(&archive));
	return (extract_line(&archive));
}
