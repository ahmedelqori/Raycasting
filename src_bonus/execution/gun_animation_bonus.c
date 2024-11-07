/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_animation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:11:15 by ael-qori          #+#    #+#             */
/*   Updated: 2024/10/25 14:36:30 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h"

static char	*gun_images(int index);
static void	draw_gun_to_window(t_container *container, t_texturedata *gun);
static void	set_images_to_null(t_container *container);

void	create_images(t_container *container)
{
	int	i;

	i = 0;
	set_images_to_null(container);
	while (i < 6)
	{
		container->bundles.walls.gun[i].img = \
			mlx_xpm_file_to_image(container->mlx, gun_images(i), \
				&container->bundles.walls.gun[i].width, \
					&container->bundles.walls.gun[i].height);
		if (container->bundles.walls.gun[i].img == NULL)
			mouse_hook(container);
		container->bundles.walls.gun[i].addr = \
			mlx_get_data_addr(container->bundles.walls.gun[i].img, \
				&container->bundles.walls.gun[i].bits_per_pixel, \
					&container->bundles.walls.gun[i].line_length, \
						&container->bundles.walls.gun[i].endian);
		container->bundles.walls.gun[i].start_horz = SCREEN_WIDTH / 2 - \
			(container->bundles.walls.gun[i].width / 2);
		container->bundles.walls.gun[i].start_vert = SCREEN_HEIGHT / 2 - \
			(container->bundles.walls.gun[i].height / 2) + 250;
		i++;
	}
}

void	animation(t_container *container)
{
	static int	i = FALSE;

	if (i == 6)
	{
		container->player.fire = FALSE;
		i = 0;
	}
	draw_gun_to_window(container, &container->bundles.walls.gun[i]);
	if (container->player.fire == TRUE)
		i++;
}

static void	draw_gun_to_window(t_container *container, t_texturedata *gun)
{
	unsigned int	color;
	int				x;
	int				y;
	int				px;

	y = 0;
	while (y < gun->height)
	{
		x = 0;
		while (x < gun->width)
		{
			px = (y * gun->line_length) + (x * (gun->bits_per_pixel / 8));
			color = *(int *)(gun->addr + px);
			if (color != 0x000000)
				mlx_pixel_put(container->mlx, \
					container->win, x + gun->start_horz + 100, y + \
						gun->start_vert + 44, color);
			x++;
		}
		y++;
	}
}

static char	*gun_images(int index)
{
	const char	*images[7] = {\
		FRAME_ONE, \
		FRAME_TWO, \
		FRAME_THREE, \
		FRAME_FOUR, \
		FRAME_FIVE, \
		FRAME_SIX, \
		NULL};

	return ((char *)index[images]);
}

static void	set_images_to_null(t_container *container)
{
	int	i;

	i = START;
	while (++i < 6)
		container->bundles.walls.gun[i].img = NULL;
}
