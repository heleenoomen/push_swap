/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:12:48 by hoomen            #+#    #+#             */
/*   Updated: 2022/05/05 09:32:14 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<stdlib.h>
# include<unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# define FD_MAX 10240

typedef struct s_struct
{
	char	*newstatic;
	char	*line;
	ssize_t	bytesread;
}			t_struct;

int		ft_strchr_gnl(const char *s, char c);
ssize_t	ft_strlen_gnl(const char *s);
ssize_t	ft_strlen_newline(char *s);
void	ft_strncpy_gnl(char *dst, const char *src, ssize_t n);
void	ft_init(t_struct *t);
char	*ft_error(char *buffer, char *staticline);
char	*ft_read_to_static(int fd, char *staticline, t_struct *t);
void	ft_split_static(char *staticline, t_struct *t);
char	*get_next_line(int fd);

#endif
