/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relhamma <relhamma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:01:13 by relhamma          #+#    #+#             */
/*   Updated: 2024/10/21 15:04:11 by relhamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

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
	return (1);
}
