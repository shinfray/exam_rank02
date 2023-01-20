/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:55:47 by shinfray          #+#    #+#             */
/*   Updated: 2023/01/20 01:04:11 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*s;
	int		fd;
	int		n;

	n = 5;
	fd = open("text.txt", O_RDONLY);
	while (n--)
	{
		s = get_next_line(fd);
		printf("\ntest: %s\n", s);
		free(s);
	}
	close(fd);
	return (0);
}
