/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_manager_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:07:00 by meedivo           #+#    #+#             */
/*   Updated: 2024/10/25 14:46:10 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h"

static t_texturedata	*array_of_images(t_container *cub, int index);
static void				converte_img_to_xpm(t_container *cub, \
t_texturedata *image, char *texture);
static void				get_data_from_textures(t_texturedata *image);
static char				*array_of_textures(t_container *cub, int index);

void	initialize_images(t_container *container)
{
	int	index;

	index = -1;
	container->bundles.background.img = mlx_new_image(container->mlx, \
	SCREEN_WIDTH, SCREEN_HEIGHT);
	get_data_from_textures(&container->bundles.background);
	while (++index < 6)
		converte_img_to_xpm(container, array_of_images(container, index), \
		array_of_textures(container, index));
	index = -1;
	if (!container->bundles.walls.orientations[0].img || \
	!container->bundles.walls.orientations[1].img || \
	!container->bundles.walls.orientations[2].img \
	|| !container->bundles.walls.orientations[3].img \
	|| !container->bundles.walls.door[0].img \
	|| !container->bundles.walls.door[1].img
	)
	{
		printf(ERROR_TEXTURES);
		mouse_hook(container);
	}
	while (++index < 6)
		get_data_from_textures(array_of_images(container, index));
}

static void	get_data_from_textures(t_texturedata *image)
{
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, \
	&image->line_length, &image->endian);
}

static void	converte_img_to_xpm(t_container *cub, t_texturedata *img, char *txt)
{
	img->img = mlx_xpm_file_to_image(cub->mlx, txt, &img->width, &img->height);
}

static t_texturedata	*array_of_images(t_container *cub, int index)
{
	const t_texturedata	*array[6] = {&cub->bundles.walls.orientations[0], \
	&cub->bundles.walls.orientations[1], &cub->bundles.walls.orientations[2], \
	&cub->bundles.walls.orientations[3], &cub->bundles.walls.door[0], \
		&cub->bundles.walls.door[1]};

	return ((t_texturedata *)array[index]);
}

static char	*array_of_textures(t_container *cub, int index)
{
	const char	*array[6] = {cub->data->north, cub->data->south, \
	cub->data->east, cub->data->west, DOOR_CLOSE, DOOR_OPEN};

	return ((char *)array[index]);
}
