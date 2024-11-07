/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relhamma <relhamma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:01:08 by relhamma          #+#    #+#             */
/*   Updated: 2024/10/21 15:01:09 by relhamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

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
