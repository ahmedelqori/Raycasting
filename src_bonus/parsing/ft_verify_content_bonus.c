/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_content_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:01:21 by relhamma          #+#    #+#             */
/*   Updated: 2024/10/22 21:49:20 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h"

int	is_border(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	ft_get_map(char **file, int index, t_parsing *data)
{
	int	i;

	i = 0;
	while (file[index])
		data->map[i++] = ft_strdup(file[index++]);
	data->map[i] = 0;
}

char	**ft_get_information(char **file, int index)
{
	int		i;
	char	**buffer;
	int		j;

	j = 0;
	buffer = malloc((index + 1) * sizeof(char *));
	i = 0;
	while (i < index)
	{
		if (file[i][0])
			buffer[j++] = ft_strdup(file[i]);
		i++;
	}
	buffer[j] = NULL;
	free_buffer(file, 1);
	return (buffer);
}

char	**ft_verify_content(char **file, t_parsing *data)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (!file[i][0])
		{
			i++;
			continue ;
		}
		if (is_border(file[i]))
			break ;
		i++;
	}
	if (!file[i])
		return (free_buffer(file, 1), NULL);
	ft_get_map(file, i, data);
	file = ft_get_information(file, i);
	return (file);
}
