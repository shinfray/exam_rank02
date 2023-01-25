/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:08:25 by shinfray          #+#    #+#             */
/*   Updated: 2023/01/22 20:13:28 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_gnl_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		++i;
	return (i);
}

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*cast_dst;
	const char	*cast_src;

	cast_dst = (char *)dst;
	cast_src = (const char *)src;
	if (cast_src == cast_dst)
		return (dst);
	while (n-- > 0)
		*cast_dst++ = *cast_src++;
	return (dst);
}

static void	*ft_calloc(size_t count, size_t size)
{
	const size_t	full_size = size * count;
	size_t			i;
	char			*ptr;

	i = 0;
	ptr = malloc(full_size);
	if (ptr != NULL)
		while (i < full_size)
			ptr[i++] = '\0';
	return (ptr);
}

char	*ft_gnl_strnjoin(char *src1, char *src2, size_t n_of_src2_to_copy)
{
	size_t	src1_len;
	size_t	src2_len;
	char	*dest_str;

	if (src1 == NULL && src2 == NULL)
		return (NULL);
	src1_len = ft_gnl_strlen(src1);
	src2_len = ft_gnl_strlen(src2);
	if (src2_len > n_of_src2_to_copy)
		src2_len = n_of_src2_to_copy;
	dest_str = ft_calloc(src1_len + src2_len + 1, sizeof(*dest_str));
	if (dest_str != NULL)
	{
		ft_memcpy(dest_str, src1, src1_len);
		ft_memcpy(dest_str + src1_len, src2, src2_len);
	}
	if (src1 != NULL)
		free(src1);
	return (dest_str);
}

char	*ft_strchr(const char *s, int c)
{
	const char	cast_c = c;

	while (*s != cast_c)
		if (*s++ == '\0')
			return (NULL);
	return ((char *)s);
}
