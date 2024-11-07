/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:54:51 by ael-qori          #+#    #+#             */
/*   Updated: 2024/10/25 14:36:20 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h"

static void	destroy_images(t_container *container);
static void	destroy_gun_images(t_container *container);

void	safe_exit(t_parsing *parsing, int status, char *error)
{
	ft_free_parsing(parsing);
	printf(BOLDRED " %s "RESET "\n", error);
	exit(status);
}

int	terminate_with_cleanup(int key, t_container *container)
{
	ft_free_parsing(container->data);
	destroy_images(container);
	mlx_destroy_image(container->mlx, container->bundles.background.img);
	destroy_gun_images(container);
	mlx_destroy_window(container->mlx, container->win);
	mlx_destroy_display(container->mlx);
	free(container->mlx);
	free(container);
	key = 0;
	exit(key);
}

int	mouse_hook(t_container *container)
{
	ft_free_parsing(container->data);
	destroy_images(container);
	destroy_gun_images(container);
	mlx_destroy_image(container->mlx, container->bundles.background.img);
	mlx_destroy_window(container->mlx, container->win);
	mlx_destroy_display(container->mlx);
	free(container->mlx);
	free(container);
	exit(0);
}

static void	destroy_images(t_container *container)
{
	if (container->bundles.walls.orientations[0].img)
		mlx_destroy_image(container->mlx, \
			container->bundles.walls.orientations[0].img);
	if (container->bundles.walls.orientations[1].img)
		mlx_destroy_image(container->mlx, \
			container->bundles.walls.orientations[1].img);
	if (container->bundles.walls.orientations[2].img)
		mlx_destroy_image(container->mlx, \
			container->bundles.walls.orientations[2].img);
	if (container->bundles.walls.orientations[3].img)
		mlx_destroy_image(container->mlx, \
			container->bundles.walls.orientations[3].img);
	if (container->bundles.walls.door[0].img)
		mlx_destroy_image(container->mlx, \
			container->bundles.walls.door[0].img);
	if (container->bundles.walls.door[1].img)
		mlx_destroy_image(container->mlx, \
			container->bundles.walls.door[1].img);
}

static void	destroy_gun_images(t_container *container)
{
	int	index;

	index = START;
	while (++index < 6)
		if (container->bundles.walls.gun[index].img)
			mlx_destroy_image(container->mlx, \
				container->bundles.walls.gun[index].img);
}
