/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:02:04 by relhamma          #+#    #+#             */
/*   Updated: 2024/10/28 21:13:58 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h"

int	ft_strcmp_1(char *s1, char *s2)
{
	if (!*s1 && !*s2)
		return (1);
	else if (*s1 != *s2)
		return (0);
	else
		return (ft_strcmp_1(s1 + 1, s2 + 1));
}

int	is_num(char *line)
{
	int	i;

	if (!line || !*line)
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] < '0' || line[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static char	*ft_strdup_buffer(char **temp_2, char c)
{
	char	*buffer;
	int		i;
	char	*string;
	int		k;

	buffer = malloc(2048);
	string = *temp_2;
	i = 0;
	k = 0;
	while (string[i] && string[i] == ' ')
		i++;
	while (string[i] && string[i] != c)
		buffer[k++] = string[i++];
	*(temp_2) += i;
	buffer[k] = 0;
	return (buffer);
}

char	**ft_split_2(char *string)
{
	char	**buffer;

	buffer = malloc(sizeof(char *) * 3);
	buffer[0] = ft_strdup_buffer(&string, ' ');
	buffer[1] = ft_strdup_buffer(&string, 0);
	buffer[2] = 0;
	return (buffer);
}

int	is_door(char c)
{
	if (c == 'C' || c == 'O')
		return (1);
	return (0);
}
