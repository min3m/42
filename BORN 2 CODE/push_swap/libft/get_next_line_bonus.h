/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:36:16 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/26 22:09:59 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2048
#endif

char	*get_next_line(int fd);
size_t	gnl_strlen(const char *str);
char	*gnl_strjoin(char *s1, char *s2);
void	*gnl_memmove(void *dest, const void *src, size_t n);
char	*gnl_strchr(const char *str, int c);

#endif
