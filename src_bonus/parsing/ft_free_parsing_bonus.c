/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_parsing_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relhamma <relhamma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:01:08 by relhamma          #+#    #+#             */
/*   Updated: 2024/10/23 16:13:56 by relhamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h"

void	free_buffer(char **buffer, int flag)
{
	int	i;

	i = 0;
	while (buffer[i])
		free(buffer[i++]);
	if (flag)
		free(buffer);
}

void	ft_free_parsing(t_parsing *data)
{
	free_buffer(data->map, 0);
	free(data->north);
	free(data->south);
	free(data->west);
	free(data->east);
}
