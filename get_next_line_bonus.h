/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:25:55 by mchemcha          #+#    #+#             */
/*   Updated: 2024/01/16 09:52:41 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/syslimits.h>
# include <limits.h>

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 10
# endif

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_read_line(char *s);
char	*ft_read_afterline(char *s);
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
#endif