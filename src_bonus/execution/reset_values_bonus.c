/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_values_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:03:59 by ael-qori          #+#    #+#             */
/*   Updated: 2024/10/25 14:51:00 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h"

static int	get_size_of_matrix(char **str);

void	initialize_to_zero(t_container *container)
{
	ft_memset(&container->mouvements, 0, sizeof(container->mouvements));
	ft_memset(&container->player, 1, sizeof(t_playerentity));
	container->width = ft_strlen(container->data->map[0]);
	container->height = get_size_of_matrix(container->data->map);
	container->mouse = FALSE;
}

static int	get_size_of_matrix(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
