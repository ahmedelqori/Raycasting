/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 03:40:07 by ael-qori          #+#    #+#             */
/*   Updated: 2024/10/22 10:17:24 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static void	calc_step_for_x(t_container *container);
static void	calc_step_for_y(t_container *container);

void	calc_ray_for_y_x(t_container *container)
{
	container->player.camerax = 2 * (container->player.x
			/ (double)(SCREEN_WIDTH)) - 1;
	container->player.ray.horz = container->player.dir.horz
		+ container->player.pln.horz * container->player.camerax;
	container->player.ray.vert = container->player.dir.vert
		+ container->player.pln.vert * container->player.camerax;
	container->player.mapx = floor(container->player.pos.horz);
	container->player.mapy = floor(container->player.pos.vert);
	if (container->player.ray.horz == 0)
		container->player.delta.horz = MAXDOUBLE;
	else
		container->player.delta.horz = fabs(1 / container->player.ray.horz);
	if (container->player.ray.vert == 0)
		container->player.delta.vert = MAXDOUBLE;
	else
		container->player.delta.vert = fabs(1 / container->player.ray.vert);
}

void	calculate_camera_direction(t_container *container)
{
	if (container->player.side == 0)
		container->player.perpwalldist = (container->player.sidedist.horz - \
		container->player.delta.horz);
	else
		container->player.perpwalldist = (container->player.sidedist.vert - \
		container->player.delta.vert);
	container->bundles.walls.lineheight = (int)(SCREEN_HEIGHT / \
	container->player.perpwalldist);
	container->bundles.walls.drawstart = -container->bundles.walls.lineheight \
			/ 2 + SCREEN_HEIGHT / 2;
	if (container->bundles.walls.drawstart < 0)
		container->bundles.walls.drawstart = 0;
	container->bundles.walls.drawend = container->bundles.walls.lineheight / 2
		+ SCREEN_HEIGHT / 2;
	if (container->bundles.walls.drawend >= SCREEN_HEIGHT)
		container->bundles.walls.drawend = SCREEN_HEIGHT - 1;
}

void	calc_step_for_y_x(t_container *container)
{
	calc_step_for_x(container);
	calc_step_for_y(container);
}

void	calc_step_for_x(t_container *container)
{
	if (container->player.ray.horz < 0)
	{
		container->player.stepx = -1;
		container->player.sidedist.horz = (container->player.pos.horz
				- container->player.mapx) * container->player.delta.horz;
	}
	else
	{
		container->player.stepx = 1;
		container->player.sidedist.horz = (container->player.mapx + 1.0f
				- container->player.pos.horz) * container->player.delta.horz;
	}
}

void	calc_step_for_y(t_container *container)
{
	if (container->player.ray.vert < 0)
	{
		container->player.stepy = -1;
		container->player.sidedist.vert = (container->player.pos.vert
				- container->player.mapy) * container->player.delta.vert;
	}
	else
	{
		container->player.stepy = 1;
		container->player.sidedist.vert = (container->player.mapy
				+ 1.0f - container->player.pos.vert)
			* container->player.delta.vert;
	}
}
