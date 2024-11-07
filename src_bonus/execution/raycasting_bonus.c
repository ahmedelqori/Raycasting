/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:42:03 by ael-qori          #+#    #+#             */
/*   Updated: 2024/10/24 11:00:03 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h"

void	digital_differential_analysis(t_container *container)
{
	container->player.x = START;
	while (++(container->player.x) < SCREEN_WIDTH)
	{
		calc_ray_for_y_x(container);
		calc_step_for_y_x(container);
		check_hit(container);
		calculate_camera_direction(container);
		draw_images_to_game(container, container->player.x);
	}
}
