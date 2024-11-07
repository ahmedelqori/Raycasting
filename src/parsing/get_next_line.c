/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relhamma <relhamma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:01:53 by relhamma          #+#    #+#             */
/*   Updated: 2024/10/21 15:05:21 by relhamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*pointer;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	pointer = (char *)malloc(len1 + len2 + 1);
	if (pointer == NULL)
		return (NULL);
	if (s1)
		ft_memcpy(pointer, s1, len1);
	if (s2)
		ft_memcpy(pointer + len1, s2, len2);
	pointer[len1 + len2] = '\0';
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (pointer);
}

char	*line_up(char **new_buffer, int new_line)
{
	int		l1;
	int		l2;
	char	*s1;
	char	*s2;

	l1 = new_line + 1;
	l2 = ft_strlen((*new_buffer)) - new_line - 1;
	s1 = ft_strdup_line((*new_buffer), l1);
	s2 = ft_strdup_line((*new_buffer) + l1, l2);
	free(*new_buffer);
	*new_buffer = s2;
	return (s1);
}

char	*final_line(char **new_buffer)
{
	char	*s1;

	s1 = ft_strdup_line(*new_buffer, ft_strlen(*new_buffer));
	free(*new_buffer);
	*new_buffer = 0;
	return (s1);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	ssize_t		bytes;
	static char	*new_buffer;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		read_and_update_buffer(&buffer, &bytes, fd, &new_buffer);
		if (buffer == NULL || bytes <= 0)
		{
			free(buffer);
			break ;
		}
		new_buffer = ft_strjoin(new_buffer, buffer);
		if (ft_memchr_line(new_buffer, '\n') >= 0)
			break ;
	}
	if (ft_memchr_line(new_buffer, '\n') >= 0)
		return (line_up(&new_buffer, ft_memchr_line(new_buffer, '\n')));
	if (ft_strlen(new_buffer) > 0)
		return (final_line(&new_buffer));
	return (NULL);
}
