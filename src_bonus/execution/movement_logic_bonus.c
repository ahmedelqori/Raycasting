/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_logic_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:10:19 by ael-qori          #+#    #+#             */
/*   Updated: 2024/10/24 15:19:27 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h"

static void	move_every_direction(t_container *container, char flag);
static void	forward_backward(t_container *cub, char flag, float distance);
static void	right_left(t_container *container, char flag, float distance);

void	handle_movement(t_container *container)
{
	const char	directions[8] = {UP, DOWN, LEFT, RIGHT,
		CAMERA_LEFT, CAMERA_RIGHT, MOUSE, OPEN};
	int			index;

	index = -1;
	while (++index < 8)
		if (container->mouvements[index])
			move_every_direction(container, directions[index]);
}

static void	move_every_direction(t_container *container, char flag)
{
	if (flag == UP)
		forward_backward(container, flag, DISTANCE_IN_FORWARD);
	if (flag == DOWN)
		forward_backward(container, flag, DISTANCE_IN_BACKWARD);
	if (flag == RIGHT)
		right_left(container, flag, DISTANCE_IN_RIGHT);
	if (flag == LEFT)
		right_left(container, flag, DISTANCE_IN_LEFT);
	if (flag == CAMERA_LEFT)
		camera_left_right(container, (float)FAIL);
	if (flag == CAMERA_RIGHT)
		camera_left_right(container, (float)TRUE);
	if (flag == OPEN)
		open_or_close_doors(container);
	if (flag == MOUSE)
	{
		container->mouse = !container->mouse;
		container->mouvements[6] = FALSE;
	}
}

static void	forward_backward(t_container *container, char flag, float distance)
{
	char	element;

	element = container->data->map[(int)(container->player.pos.vert \
	+ container->player.pln.horz * distance)]
	[(int)(container->player.pos.horz)];
	if (element != WALL && element != LOCK && flag == UP)
		container->player.pos.vert -= container->player.pln.horz * MOVE_SPEED;
	if (element != WALL && element != LOCK && flag == DOWN)
		container->player.pos.vert += container->player.pln.horz * MOVE_SPEED;
	element = container->data->map[(int)(container->player.pos.vert)]
	[(int)(container->player.pos.horz - container->player.pln.vert * distance)];
	if (element != WALL && element != LOCK && flag == UP)
		container->player.pos.horz += container->player.pln.vert * MOVE_SPEED;
	if (element != WALL && element != LOCK && flag == DOWN)
		container->player.pos.horz -= container->player.pln.vert * MOVE_SPEED;
}

static void	right_left(t_container *container, char flag, float distance)
{
	char	element;

	element = container->data->map[(int)(container->player.pos.vert \
	+ container->player.dir.horz * distance)]
	[(int)(container->player.pos.horz)];
	if (element != WALL && element != LOCK && flag == RIGHT)
		container->player.pos.vert += container->player.dir.horz * MOVE_SPEED;
	if (element != WALL && element != LOCK && flag == LEFT)
		container->player.pos.vert -= container->player.dir.horz * MOVE_SPEED;
	element = container->data->map[(int)(container->player.pos.vert)]
	[(int)(container->player.pos.horz - container->player.dir.vert * distance)];
	if (element != WALL && element != LOCK && flag == RIGHT)
		container->player.pos.horz -= container->player.dir.vert * MOVE_SPEED;
	if (element != WALL && element != LOCK && flag == LEFT)
		container->player.pos.horz += container->player.dir.vert * MOVE_SPEED;
}

void	camera_left_right(t_container *container, float flag)
{
	double	direction_x;
	double	plane_x;

	direction_x = container->player.dir.horz;
	container->player.dir.horz = container->player.dir.horz * \
				cos(flag * ROTATION_SPEED) - \
				(container->player.dir.vert * sin(flag * ROTATION_SPEED));
	container->player.dir.vert = direction_x * \
				sin(flag * ROTATION_SPEED) + \
				(container->player.dir.vert * cos(flag * ROTATION_SPEED));
	plane_x = container->player.pln.horz;
	container->player.pln.horz = container->player.pln.horz * \
				cos(flag * ROTATION_SPEED) - \
				(container->player.pln.vert * sin(flag * ROTATION_SPEED));
	container->player.pln.vert = plane_x * \
				sin(flag * ROTATION_SPEED) + \
				(container->player.pln.vert * cos(flag * ROTATION_SPEED));
}
