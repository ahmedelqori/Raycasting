/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:17:34 by ael-qori          #+#    #+#             */
/*   Updated: 2024/10/24 21:02:52 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h"

static int	change_status_mouse(t_container *container);

int	handle_mouse(int x, int y, t_container *container)
{
	static int	win[2] = {START, START};
	int			center[2];
	int			delta;

	if (change_status_mouse(container) == FAIL)
		return (FAIL);
	if (WX[win] == -1 && WY[win] == -1)
		mlx_get_screen_size(container->mlx, &WX[win], &WY[win]);
	CX[center] = WX[win] / 2;
	CY[center] = WY[win] / 2;
	delta = x - CX[center];
	if (delta != 0)
	{
		camera_left_right(container, delta * MOUSE_SENSITIVITY);
		mlx_mouse_move(container->mlx, container->win, CX[center], CY[center]);
	}
	return (y);
}

static int	change_status_mouse(t_container *container)
{
	static int	hide = FALSE;

	if (container->mouse == TRUE)
	{
		hide = FALSE;
		mlx_mouse_show(container->mlx, container->win);
		return (FAIL);
	}
	if (hide == 0)
	{
		mlx_mouse_hide(container->mlx, container->win);
		hide = TRUE;
	}
	return (SUCCESS);
}
