/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:13:20 by mchemcha          #+#    #+#             */
/*   Updated: 2024/01/11 16:27:15 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_line(char *s)
{
	int		i;
	char	*rst;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '\n')
			break ;
		i++;
	}
	if (i == 0 && s[i] == '\0')
		return (NULL);
	rst = ft_substr(s, 0, i + 1);
	return (rst);
}

char	*ft_read_afterline(char *s)
{
	int		i;
	char	*stat;

	i = 0;
	if (!s)
		return (free(s), NULL);
	while (s && s[i])
	{
		if (s[i] != '\n')
			i++;
		else
			break ;
	}
	if (s[i] == '\n')
		i++;
	stat = ft_substr(s, i, ft_strlen(s) - i + 1);
	return (free(s), stat);
}

int	ft_f(char *buffer, char **s, int fd)
{
	int	read_byte;

	while (1)
	{
		if (ft_strchr(*s, '\n'))
			break ;
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == 0)
			break ;
		if (read_byte == -1)
			return (free (buffer), free (*s), *s = NULL, 1);
		buffer[read_byte] = '\0';
		*s = ft_strjoin(*s, buffer);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*rst;
	char		*buffer;
	static char	*s[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!s[fd])
		s[fd] = ft_strdup("");
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (ft_f(buffer, &s[fd], fd))
		return (NULL);
	rst = ft_read_line(s[fd]);
	if (rst == NULL)
		return (free(s[fd]), free(buffer), s[fd] = NULL, NULL);
	s[fd] = ft_read_afterline(s[fd]);
	return (free (buffer), rst);
}
