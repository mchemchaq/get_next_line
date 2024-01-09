/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:52:19 by mchemcha          #+#    #+#             */
/*   Updated: 2024/01/07 19:22:57 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char *ft_read_line(char *s)
{
    int i;
    char *rst;
    
    i = 0;
    while(s && s[i])
    {
        if(s[i] == '\n')
            break;
        i++;
    }
    if (i == 0)
        return (NULL);
    rst = ft_substr(s, 0, i + 1);
    return (rst);
}
char *ft_read_afterline(char *s)
{
    int i;
    char *stat;
    
    i = 0;
    while (s && s[i])
    {
        if (s[i] != '\n')
            i++;
        else
            break;
    }
    if (s[i] == '\n')
        i++;
    stat = ft_substr(s, i, ft_strlen(s) - i + 1);
    return (stat);
    
}
char *get_next_line(int fd)
{
    char        *rst;
    char        *buffer;
    int         read_byte;
    static char *s;
  
    if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    if (!s)
        s = ft_strdup("");
    buffer = (char *)malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return(NULL);
    while (1)
    {
        if (ft_strchr(s, '\n'))
            break;
        read_byte = read(fd, buffer, BUFFER_SIZE);
        if (read_byte == 0)
            return(NULL);
        if (read_byte == -1)
            return (free (buffer), NULL);
        buffer[read_byte] = '\0';
        s = ft_strjoin(s, buffer);
    }
    rst = ft_read_line(s);
    s = ft_read_afterline(s);
    return (rst);
}
int main()
{
    int fd = open("TEST.txt", O_RDONLY, 0777);
    char *s = get_next_line(fd);
    while (s)
    {
        printf("%s", s);
        free(s);
        s= get_next_line(fd);
    }
}