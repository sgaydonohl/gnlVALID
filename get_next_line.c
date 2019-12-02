/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaydon- <sgaydon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:33:16 by sgaydon-          #+#    #+#             */
/*   Updated: 2019/11/30 22:12:19 by sgaydon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_save(char **saved, char **line)
{
	size_t	return_pos;
	size_t	next_len;
	char	*tmp;

	if (ft_strchr(*saved, '\n') == 0)
	{
		if (!(*line = ft_substr("", 0, 1)))
			return (-1);
		tmp = *saved;
		if (!(*saved = ft_substr(tmp, 1, ft_strlen(tmp) - 1)))
			return (-1);
		free(tmp);
		return (1);
	}
	return_pos = ft_strchr(*saved, '\n');
	next_len = ft_strlen(*saved) - return_pos;
	tmp = *saved;
	if (!(*saved = ft_substr(tmp, return_pos + 1, next_len)))
		return (-1);
	if (!(*line = ft_substr(tmp, 0, return_pos)))
		return (-1);
	free(tmp);
	return (1);
}

int		ft_return(char **saved, char **line)
{
	if (!*saved)
	{
		*line = ft_substr("", 0, 1);
		return (0);
	}
	if (ft_strchr(*saved, '\n') == -1)
	{
		if (!(*line = ft_substr(*saved, 0, ft_strlen(*saved))))
			return (-1);
		free(*saved);
		*saved = NULL;
		return (0);
	}
	else
		return (ft_save(saved, line));
}

int		ft_strjoin2000(char **saved, char *buf, int ret)
{
	char *tmp;

	if (!*saved)
	{
		ret++;
		if (!(*saved = ft_substr(buf, 0, (size_t)ret)))
			return (0);
		return (1);
	}
	tmp = *saved;
	if (!(*saved = ft_substr(tmp, 0, (ft_strlen(tmp) + (size_t)ret))))
		return (0);
	ft_memcpy(*saved + ft_strlen(*saved), buf, (size_t)ret + 1);
	free(tmp);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*s = NULL;
	int			ret;
	char		buf[BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0 || !line || fd < 0 || read(fd, buf, 0))
		return (-1);
	while (ft_strchr(s, '\n') == -1 && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!ft_strjoin2000(&s, buf, ret))
			return (-1);
	}
	return (ft_return(&s, line));
}
