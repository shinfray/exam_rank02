/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:22:11 by shinfray          #+#    #+#             */
/*   Updated: 2023/01/19 21:17:35 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

char	*get_next_line(int fd);
char	*ft_gnl_strnjoin(char *src1, char *src2, size_t n_of_src2_to_copy);
char	*ft_strchr(const char *s, int c);

#endif
