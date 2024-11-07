/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:51:58 by ael-qori          #+#    #+#             */
/*   Updated: 2024/10/24 20:59:38 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h"

static void	draw_squares(t_container *container, double *player_mini_map, \
	double *delta, int *map);
static void	draw_circle(t_texturedata *img, int center_x, int center_y, \
	int color);

void	draw_mini_map(t_container *container)
{
	double	player_mini_map[2];
	double	delta[2];
	int		map[3];

	player_mini_map[0] = MINI_MAP_SIZE * MINI_MAP_BLOCK_SIZE / 2;
	player_mini_map[1] = MINI_MAP_SIZE * MINI_MAP_BLOCK_SIZE / 2;
	map[2] = START;
	while (++map[2] < MINI_MAP_SIZE * 2 * MINI_MAP_BLOCK_SIZE)
		draw_squares(container, player_mini_map, delta, map);
	draw_circle(&container->bundles.background, (int)player_mini_map[0], \
		(int)player_mini_map[1], 0xFFFF00);
}

static void	draw_circle(t_texturedata *img, int center_x, int center_y, \
	int color)
{
	int	coord[2];
	int	delta[2];

	coord[1] = center_y - PLAYER_RADIUS;
	while (coord[1] <= center_y + PLAYER_RADIUS)
	{
		coord[0] = center_x - PLAYER_RADIUS;
		while (coord[0] <= center_x + PLAYER_RADIUS)
		{
			delta[0] = coord[0] - center_x;
			delta[1] = coord[1] - center_y;
			if (delta[0] * delta[0] + delta[1] * delta[1] <= RADIUS_SQUARED)
				paint_on_screen_by_pixel(img, coord[0], coord[1], color);
			coord[0]++;
		}
		coord[1]++;
	}
}

static void	draw_squares(t_container *container, double *player_mini_map, \
	double *delta, int *map)
{
	int	x;

	x = START;
	while (++x < MINI_MAP_SIZE * 2 * MINI_MAP_BLOCK_SIZE)
	{
		delta[0] = (x - player_mini_map[0]) / (double)MINI_MAP_BLOCK_SIZE;
		delta[1] = (map[2] - player_mini_map[1]) / (double)MINI_MAP_BLOCK_SIZE;
		map[0] = (int)(container->player.pos.horz + delta[0]);
		map[1] = (int)(container->player.pos.vert + delta[1]);
		if (delta[0] * delta[0] + delta[1] * delta[1] <= MINI_MAP_SIZE * \
			MINI_MAP_SIZE && map[0] >= 0 && map[0] < container->width && \
			map[1] >= 0 && map[1] < container->height)
		{
			if (container->data->map[map[1]][map[0]] == '1')
				paint_on_screen_by_pixel(&container->bundles.background, x, \
					map[2], 0xFFFFFF);
			else if (container->data->map[map[1]][map[0]] == 'O')
				paint_on_screen_by_pixel(&container->bundles.background, x, \
					map[2], 0x00FF00);
			else if (container->data->map[map[1]][map[0]] == 'C')
				paint_on_screen_by_pixel(&container->bundles.background, x, \
					map[2], 0xFF0000);
		}
	}
}

void	paint_on_screen_by_pixel(t_texturedata *img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0x00980088)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
