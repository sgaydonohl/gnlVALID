/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaydon- <sgaydon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:43:05 by sgaydon-          #+#    #+#             */
/*   Updated: 2019/11/29 12:06:09 by sgaydon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			if (s[i] == (char)c)
				return (i);
			i++;
		}
	}
	return (-1);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_ptr;
	const char	*src_ptr;

	src_ptr = (const char *)src;
	dst_ptr = (char *)dst;
	if (!n || (src_ptr == dst_ptr && src_ptr == NULL))
		return (dst);
	while (n > 0)
	{
		*dst_ptr++ = *src_ptr++;
		n--;
	}
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s || !len || (unsigned int)ft_strlen(s) < start)
	{
		if (!(str = (char*)malloc(sizeof(char))))
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
