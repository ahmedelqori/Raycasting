/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_floor_ceil_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:01:25 by relhamma          #+#    #+#             */
/*   Updated: 2024/10/22 21:49:20 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

char	*purge_space(char *string)
{
	int		i;
	int		size;
	char	*temp;
	int		k;

	k = 0;
	i = 0;
	if (!*string)
		return (string);
	size = (int)ft_strlen(string) - 1;
	while (string[i] && string[i] == ' ')
		i++;
	if (i == (size + 1))
		return (string);
	while (string[size] == ' ')
		size--;
	temp = malloc(size - i + 2);
	while (i <= size)
		temp[k++] = string[i++];
	temp[k] = 0;
	free(string);
	return (temp);
}

int	verify_floor(char **buffer, t_parsing *data, t_parsing_helper *helper)
{
	char	**temp;
	int		i;
	int		error;

	error = 0;
	i = 0;
	if (ft_strcmp("F", *buffer))
		return (0);
	temp = ft_split_with_empty(*(buffer + 1), ',');
	while (temp[i])
	{
		temp[i] = purge_space(temp[i]);
		if (!is_num(temp[i]) || ft_atoi(temp[i]) < 0 || ft_atoi(temp[i]) > 255)
			error = 1;
		i++;
	}
	if (buffer_counting(temp) != 3 || error)
	{
		data->floor = -1;
		return (free_buffer(temp, 1), 1);
	}
	data->floor = create_trgb(0, ft_atoi(temp[0]), ft_atoi(temp[1]),
			ft_atoi(temp[2]));
	helper->f_found++;
	return (free_buffer(temp, 1), 1);
}

int	verify_ceil(char **buffer, t_parsing *data, t_parsing_helper *helper)
{
	char	**temp;
	int		i;
	int		error;

	error = 0;
	i = 0;
	if (ft_strcmp("C", *buffer))
		return (0);
	temp = ft_split_with_empty(*(buffer + 1), ',');
	while (temp[i])
	{
		temp[i] = purge_space(temp[i]);
		if (!is_num(temp[i]) || ft_atoi(temp[i]) < 0 || ft_atoi(temp[i]) > 255)
			error = 1;
		i++;
	}
	if (buffer_counting(temp) != 3 || error)
	{
		data->ceil = -1;
		return (free_buffer(temp, 1), 1);
	}
	data->ceil = create_trgb(0, ft_atoi(temp[0]), ft_atoi(temp[1]),
			ft_atoi(temp[2]));
	helper->c_found++;
	return (free_buffer(temp, 1), 1);
}

int	ft_verify_floor_ceil(char **buffer, t_parsing *data,
		t_parsing_helper *helper)
{
	if (!verify_ceil(buffer, data, helper) && !verify_floor(buffer, data,
			helper))
		return (0);
	return (1);
}
