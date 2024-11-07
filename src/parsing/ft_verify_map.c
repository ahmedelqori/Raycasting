/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:01:28 by relhamma          #+#    #+#             */
/*   Updated: 2024/10/28 21:03:07 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	flood_fill_space(char **line, int i, int j)
{
	if (j < 0)
		return (0);
	if (j > (int)ft_strlen(line[i]))
		return (0);
	if (!line[i][j] || is_space(line[i][j]))
		return (0);
	return (1);
}

int	flood_fill_neighbor(char **line, int i, int j)
{
	return (flood_fill_space(line, i + 1, j) && flood_fill_space(line, i - 1, j)
		&& flood_fill_space(line, i, j + 1) && flood_fill_space(line, i, j
			- 1));
}

int	ft_verify_top_bot_line(char *line)
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

int	ft_verify_regular_line(char **line, int i, t_parsing *data,
		t_parsing_helper *helper)
{
	int	j;

	j = 0;
	while (line[i][j])
	{
		if (!ft_check_entity(line[i][j]) || ((is_empty_space(line[i][j])
					|| is_orientation(line[i][j])) && !flood_fill_neighbor(line,
					i, j)))
			return (0);
		if (is_orientation(line[i][j]))
		{
			helper->player_found++;
			data->direction = line[i][j];
			data->map_y = i;
			data->map_x = j;
		}
		j++;
	}
	return (1);
}

int	ft_verify_map(t_parsing *data)
{
	int					i;
	t_parsing_helper	helper;

	helper.player_found = 0;
	if (!ft_normalize_map(data))
		return (0);
	i = 0;
	while (data->map[i])
	{
		if (i == 0 || !data->map[i + 1])
		{
			if (!ft_verify_top_bot_line(data->map[i]))
				return (0);
		}
		else
		{
			if (!ft_verify_regular_line(data->map, i, data, &helper))
				return (0);
		}
		i++;
	}
	if (helper.player_found != 1)
		return (0);
	return (1);
}
