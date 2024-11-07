/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:01:50 by relhamma          #+#    #+#             */
/*   Updated: 2024/10/22 21:49:20 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h"

char	*ft_substr(char *str)
{
	char	buffer[2048];
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		buffer[i] = str[i];
		i++;
	}
	buffer[i] = 0;
	free(str);
	return (ft_strdup(buffer));
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp;
	unsigned char	*temp_2;
	size_t			i;

	if (src == NULL && dest == NULL)
		return (0);
	temp = (unsigned char *)dest;
	temp_2 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		temp[i] = temp_2[i];
		i++;
	}
	return (dest);
}

void	read_and_update_buffer(char **buffer, ssize_t *bytes, int fd,
		char **new_buffer)
{
	*buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (*buffer == NULL)
		return ;
	*bytes = read(fd, *buffer, BUFFER_SIZE);
	if (*bytes < 0)
	{
		free(*new_buffer);
		return ;
	}
	if (*bytes == 0)
		return ;
	(*buffer)[*bytes] = 0;
}

int	ft_memchr_line(char *s, char c)
{
	int	i;

	if (s == NULL)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup_line(const char *s1, int j)
{
	int		i;
	char	*dest;
	char	*src;

	if (s1 == NULL || !*s1)
		return (NULL);
	src = (char *)s1;
	dest = (char *)malloc(j * sizeof(char) + 1);
	i = 0;
	while (i < j)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
