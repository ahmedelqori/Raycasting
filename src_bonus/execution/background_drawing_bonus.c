/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_drawing_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:34:23 by ael-qori          #+#    #+#             */
/*   Updated: 2024/10/24 11:00:03 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h"

static void	draw_line_of_background(t_container *cub, int *coordinates);
static void	pixel_to_screen(t_texturedata *img, int x, int y, int color);

void	draw_floor_ceil(t_container *container)
{
	int	*coordinates;

	coordinates = ft_calloc(2, sizeof(int));
	while (coordinates[1] < SCREEN_HEIGHT)
	{
		draw_line_of_background(container, coordinates);
		coordinates[1]++;
	}
	free(coordinates);
	mlx_put_image_to_window(container->mlx, container->win, \
	container->bundles.background.img, 0, 0);
}

static void	draw_line_of_background(t_container *container, int *coordinates)
{
	coordinates[0] = 0;
	while (coordinates[0] < SCREEN_WIDTH)
	{
		if (SCREEN_HEIGHT / 2 > coordinates[1])
			pixel_to_screen(&container->bundles.background, \
			coordinates[0], coordinates[1], container->data->ceil);
		else
			pixel_to_screen(&container->bundles.background, \
			coordinates[0], coordinates[1], container->data->floor);
		coordinates[0]++;
	}
}

static void	pixel_to_screen(t_texturedata *img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0x00980088 || color == (int)16711935)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
