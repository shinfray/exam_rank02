/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:21:58 by shinfray          #+#    #+#             */
/*   Updated: 2023/01/20 17:38:29 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void	ft_update_stash(char *stash, char *newline_address)
{
	++newline_address;
	while (*newline_address != '\0')
		*stash++ = *newline_address++;
	*stash = '\0';
}

static char	*ft_parse(int fd, char *stash, ssize_t *bytes_read)
{
	char	*line;
	char	*newline_address;

	line = NULL;
	*bytes_read = read(fd, stash, BUFFER_SIZE);
	while (*bytes_read > 0)
	{
		stash[*bytes_read] = '\0';
		newline_address = ft_strchr(stash, '\n');
		if (newline_address != NULL)
		{
			line = ft_gnl_strnjoin(line, stash, (newline_address - stash) + 1);
			ft_update_stash(stash, newline_address);
			return (line);
		}
		line = ft_gnl_strnjoin(line, stash, BUFFER_SIZE);
		if (line == NULL)
			return (NULL);
		*bytes_read = read(fd, stash, BUFFER_SIZE);
	}
	if (*bytes_read < 0 && line != NULL)
		free(line);
	*stash = '\0';
	return (line);
}

static char	*ft_retrieve_from_stash(char **line, char *stash)
{
	char	*newline_address;

	newline_address = ft_strchr(stash, '\n');
	if (newline_address != NULL)
	{
		*line = ft_gnl_strnjoin(NULL, stash, (newline_address - stash) + 1);
		if (*line == NULL)
			return (NULL);
		ft_update_stash(stash, newline_address);
		return (stash);
	}
	else
		*line = ft_gnl_strnjoin(NULL, stash, BUFFER_SIZE);
	*stash = '\0';
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		*line;
	char		*string_from_file;
	ssize_t		bytes_read;

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	line = NULL;
	bytes_read = 0;
	if (stash[0] != '\0')
		if (ft_retrieve_from_stash(&line, stash) != NULL || line == NULL)
			return (line);
	string_from_file = ft_parse(fd, stash, &bytes_read);
	if (string_from_file != NULL || bytes_read == 0)
	{
		line = ft_gnl_strnjoin(line, string_from_file, 0);
		free(string_from_file);
		return (line);
	}
	free(line);
	return (NULL);
}
