/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:35:30 by shinfray          #+#    #+#             */
/*   Updated: 2023/01/25 12:35:34 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	ft_update_stash(char *stash, char *newline)
{
	++newline;
	while (*newline != '\0')
		*stash++ = *newline++;
	*stash = '\0';
}

static char	*ft_parse(int fd, char *line, char *stash, char *newline)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, stash, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		stash[bytes_read] = '\0';
		newline = ft_strchr(stash, '\n');
		if (newline != NULL)
		{
			line = ft_gnl_strnjoin(line, stash, newline - stash + 1);
			if (line != NULL)
				ft_update_stash(stash, newline);
			return (line);
		}
		line = ft_gnl_strnjoin(line, stash, BUFFER_SIZE);
		if (line == NULL)
			return (NULL);
		bytes_read = read(fd, stash, BUFFER_SIZE);
	}
	*stash = '\0';
	if (bytes_read == 0)
		return (line);
	if (line != NULL)
		free(line);
	return (NULL);
}

static char	*ft_retrieve_from_stash(char *line, char *stash, char **newline)
{
	*newline = ft_strchr(stash, '\n');
	if (*newline != NULL)
	{
		line = ft_gnl_strnjoin(NULL, stash, *newline - stash + 1);
		if (line != NULL)
			ft_update_stash(stash, *newline);
		return (line);
	}
	return (ft_gnl_strnjoin(NULL, stash, BUFFER_SIZE));
}

char	*get_next_line(int fd)
{
	static char	stash[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	char		*newline;

	if (fd < 0)
		return (NULL);
	line = NULL;
	newline = NULL;
	if (*stash[fd] != '\0')
	{
		line = ft_retrieve_from_stash(line, stash[fd], &newline);
		if (line == NULL || newline != NULL)
			return (line);
	}
	return (ft_parse(fd, line, stash[fd], newline));
}
