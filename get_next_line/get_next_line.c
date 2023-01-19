/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:21:58 by shinfray          #+#    #+#             */
/*   Updated: 2023/01/19 20:45:54 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_parse(int fd, char *stash)
{
	ssize_t	bytes_read;
	char	*line;
	char	*newline_address;
	
	bytes_read = read(fd, stash, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		stash[bytes_read] = '\0';
		newline_pos = ft_strchr(stash, '\n');
		if (newline_pos != NULL)
		{
			line = ft_gnl_strnjoin(line, stash, (newline_address - stash) + 1);
			update_stash;--------------------
			return (line)
		}
		line = ft_gnl_strnjoin(line, stash, BUFFER_SIZE);
		if (line == NULL)
			return (NULL);
		bytes_read = read(fd, stash, BUFFER_SIZE);
	}
	if (bytes_read < 0)
	{
		free(line);
		line = NULL;
	}
	return (line);
}

char	*ft_retrieve_from_stash(char **line, char *stash)
{
	const char	*const newline_address = ft_strchr(stash, '\n');

	if (newline_address != NULL)
	{
		*line = ft_gnl_strnjoin(NULL, stash, (newline_address - stash) + 1);
		if (*line == NULL)
			return (NULL);
		update_stash;------------------------
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

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	line = NULL;
	if (stash[0] != '\0')
		if (ft_retrieve_from_stash(&line, stash) != NULL || line == NULL);
			return (line);
	string_from_file = ft_parse(fd, stash);
	if (string_from_file != NULL)
	{
		line = ft_gnl_strnjoin(line, string_from_file);
		free(string_from_file);
		return (line);
	}
	free(line);
	return (NULL);
}
