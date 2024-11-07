/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hit_the_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:06:34 by ael-qori          #+#    #+#             */
/*   Updated: 2024/10/21 16:27:47 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static int	get_size_of_matrix(char **str);

void	check_hit(t_container *container)
{
	while (container->player.hit == 0)
	{
		if (container->player.sidedist.horz < container->player.sidedist.vert)
		{
			container->player.sidedist.horz += container->player.delta.horz;
			container->player.mapx += container->player.stepx;
			container->player.side = 0;
		}
		else
		{
			container->player.sidedist.vert += container->player.delta.vert;
			container->player.mapy += container->player.stepy;
			container->player.side = 1;
		}
		if (container->player.mapx < 0 || container->player.mapy < 0 || \
			container->player.mapy >= \
				get_size_of_matrix(container->data->map) || \
			container->player.mapx >= (int)ft_strlen(
				container->data->map[container->player.mapy]))
			container->player.hit = 2;
		else if (container->data->map[container->player.mapy] \
		[container->player.mapx] == '1')
			container->player.hit = 1;
	}
}

static int	get_size_of_matrix(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
