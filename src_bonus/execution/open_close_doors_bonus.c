/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close_doors_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:23:30 by ael-qori          #+#    #+#             */
/*   Updated: 2024/10/25 10:53:33 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h"

static void	calc_delta(t_container *container, t_playerentity *player);
static void	calc_sidedist(t_container *container, t_playerentity *player);
static void	hit_ray_with_door(t_container *container, t_playerentity *player);
static int	repalce_door_after_hit(t_container *container, \
			t_playerentity *player);

void	open_or_close_doors(t_container *container)
{
	t_playerentity	player;

	calc_delta(container, &player);
	calc_sidedist(container, &player);
	hit_ray_with_door(container, &player);
}

static void	calc_delta(t_container *container, t_playerentity *player)
{
	player->mapx = floor(container->player.pos.horz);
	player->mapy = floor(container->player.pos.vert);
	if (container->player.dir.horz == 0)
		player->delta.horz = MAXDOUBLE;
	else
		player->delta.horz = fabs(1 / container->player.dir.horz);
	if (container->player.dir.vert == 0)
		player->delta.vert = MAXDOUBLE;
	else
		player->delta.vert = fabs(1 / container->player.dir.vert);
}

static void	calc_sidedist(t_container *container, t_playerentity *player)
{
	if (container->player.dir.horz < 0)
	{
		player->stepx = -1;
		player->sidedist.horz = (container->player.pos.horz - \
			player->mapx) * player->delta.horz;
	}
	else
	{
		player->stepx = 1;
		player->sidedist.horz = (player->mapx + 1.0f - \
			container->player.pos.horz) * player->delta.horz;
	}
	if (container->player.dir.vert < 0)
	{
		player->stepy = -1;
		player->sidedist.vert = (container->player.pos.vert - \
			player->mapy) * player->delta.vert;
	}
	else
	{
		player->stepy = 1;
		player->sidedist.vert = (player->mapy + 1.0f - \
			container->player.pos.vert) * player->delta.vert;
	}
}

static void	hit_ray_with_door(t_container *container, \
	t_playerentity *player)
{
	while (1)
	{
		if (player->sidedist.horz < player->sidedist.vert)
		{
			player->sidedist.horz += player->delta.horz;
			player->mapx += player->stepx ;
		}
		else
		{
			player->sidedist.vert += player->delta.vert;
			player->mapy += player->stepy;
		}
		if (repalce_door_after_hit(container, player))
			break ;
	}
	container->mouvements[7] = FALSE;
	container->player.fire = TRUE;
}

static int	repalce_door_after_hit(t_container *container, \
	t_playerentity *player)
{
	char	element;

	if (player->mapx < 0 || player->mapy < 0 || \
		player->mapy >= \
			container->height || \
		player->mapx >= container->width)
		return (TRUE);
	element = container->data->map[player->mapy][player->mapx];
	if (element == '1')
		;
	else if (element == 'C')
		container->data->map[player->mapy][player->mapx] = 'O';
	else if (element == 'O')
		container->data->map[player->mapy][player->mapx] = 'C';
	else
		return (FALSE);
	return (TRUE);
}
