/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:51:51 by shinfray          #+#    #+#             */
/*   Updated: 2023/01/17 13:30:06 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char
ft_check_doubles(const char *str, const char *const c)
{
	for (;*str != '\0' && str != c; ++str)
		if (*str == *c)
			return (1);
	return (0);
}

int
main(int argc, char **argv)
{
	if (argc == 3)
		for (size_t i = 0; argv[1][i] != '\0'; ++i)
			if (ft_check_doubles(argv[2], &argv[1][i]) != 0 &&
			    ft_check_doubles(argv[1], &argv[1][i]) == 0)
				write(1, &argv[1][i], 1);
	return (write(1, "\n", 1));
}
