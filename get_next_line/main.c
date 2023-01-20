/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:55:47 by shinfray          #+#    #+#             */
/*   Updated: 2023/01/20 12:19:13 by shinfray         ###   ########.fr       */
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

	n = 12;
	fd = open("one_line_no_nl.txt", O_RDONLY);
	while (n--)
	{
		s = get_next_line(fd);
		printf("\nfrom main:%s", s);
		free(s);
	}
	close(fd);
	return (0);
}
