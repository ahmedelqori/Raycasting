/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_map_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relhamma <relhamma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:01:13 by relhamma          #+#    #+#             */
/*   Updated: 2024/10/24 20:31:41 by relhamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h"

size_t	get_bigger_line(char **buffer)
{
	size_t	size;
	int		i;

	i = 0;
	size = 0;
	while (buffer[i])
	{
		if (ft_strlen(buffer[i]) > size)
			size = ft_strlen(buffer[i]);
		i++;
	}
	return (size);
}

char	*ft_normalize_line(char *line, size_t size)
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = malloc(size + 1);
	while (line[i])
	{
		temp[i] = line[i];
		i++;
	}
	while (i < size)
	{
		temp[i] = ' ';
		i++;
	}
	temp[i] = 0;
	free(line);
	return (temp);
}

void	ft_normalize_lines(t_parsing *data)
{
	size_t	size;
	int		i;

	i = 0;
	size = get_bigger_line(data->map);
	while (data->map[i])
	{
		data->map[i] = ft_normalize_line(data->map[i], size);
		i++;
	}
}

int	ft_normalize_map(t_parsing *data)
{
	int	size;
	int	i;

	size = buffer_counting(data->map);
	size -= 1;
	while (size >= 0 && !data->map[size][0])
		free(data->map[size--]);
	data->map[size + 1] = 0;
	i = 0;
	while (i <= size)
	{
		if (!data->map[i][0])
			return (0);
		i++;
	}
	ft_normalize_lines(data);
	return (1);
}

int	ft_verify_door(char **line, int i, int j)
{
	if (((line[i][j - 1] == '1' || is_door(line[i][j - 1])) && (line[i][j
				+ 1] == '1' || is_door(line[i][j + 1]))))
	{
		if (((line[i + 1][j] == '0' || is_door(line[i + 1][j])) && (line[i
					- 1][j] == '0' || is_door(line[i - 1][j]))))
			return (1);
	}
	else if (((line[i + 1][j] == '1' || is_door(line[i + 1][j])) && (line[i
				- 1][j] == '1' || is_door(line[i - 1][j]))))
	{
		if (((line[i][j + 1] == '0' || is_door(line[i][j + 1])) && (line[i][j
					- 1] == '0' || is_door(line[i][j - 1]))))
			return (1);
	}
	return (0);
}
