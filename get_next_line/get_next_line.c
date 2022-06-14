/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:10:53 by hoomen            #+#    #+#             */
/*   Updated: 2022/04/28 09:28:04 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

void	ft_init(t_struct *t)
{
	t->newstatic = NULL;
	t->line = NULL;
	t->bytesread = 1;
}

char	*ft_error(char *buffer, char *staticline)
{
	free(buffer);
	free(staticline);
	return (NULL);
}

char	*ft_read_to_static(int fd, char *staticline, t_struct *t)
{
	char		*buffer;
	char		*newstatic;
	ssize_t		staticlen;
	ssize_t		staticlen_new;

	buffer = malloc(BUFFER_SIZE);
	if (buffer == NULL)
		return (ft_error(buffer, staticline));
	t->bytesread = read(fd, buffer, BUFFER_SIZE);
	if (t->bytesread == -1)
		return (ft_error(buffer, staticline));
	staticlen = ft_strlen_gnl(staticline);
	staticlen_new = staticlen + t->bytesread;
	newstatic = malloc(staticlen_new + 1);
	if (newstatic == NULL)
		return (ft_error(buffer, staticline));
	ft_strncpy_gnl(newstatic, staticline, staticlen);
	ft_strncpy_gnl(newstatic + staticlen, buffer, t->bytesread);
	free(staticline);
	free(buffer);
	return (newstatic);
}

void	ft_split_static(char *staticline, t_struct *t)
{
	ssize_t	rem_staticlen;
	ssize_t	linelen;

	linelen = ft_strlen_newline(staticline);
	if (!linelen)
		return ;
	t->line = malloc(linelen + 1);
	if (t->line == NULL)
		return ;
	ft_strncpy_gnl(t->line, staticline, linelen);
	rem_staticlen = ft_strlen_gnl(staticline) - linelen;
	t->newstatic = malloc(rem_staticlen + 1);
	if (t->newstatic == NULL)
	{
		free(t->line);
		t->line = NULL;
		return ;
	}
	ft_strncpy_gnl(t->newstatic, staticline + linelen, rem_staticlen);
}

char	*get_next_line(int fd)
{
	static char	*staticline;
	t_struct	t;

	if (BUFFER_SIZE < 1 || fd < 0 || fd >= FD_MAX)
		return (NULL);
	ft_init(&t);
	if (staticline == NULL)
		staticline = ft_read_to_static(fd, staticline, &t);
	while (staticline != NULL && !ft_strchr_gnl(staticline, '\n')
		&& t.bytesread)
		staticline = ft_read_to_static(fd, staticline, &t);
	if (staticline == NULL)
		return (NULL);
	ft_split_static(staticline, &t);
	free(staticline);
	staticline = t.newstatic;
	return (t.line);
}
