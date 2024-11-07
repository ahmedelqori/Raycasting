/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_engine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:39:31 by ael-qori          #+#    #+#             */
/*   Updated: 2024/10/25 10:44:14 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub_bonus.h"

static long	get_time_in_ms(void);
static void	fps(long frame_start_time);

int	update_render(t_container *container)
{
	long	frame_start_time;

	frame_start_time = get_time_in_ms();
	draw_floor_ceil(container);
	digital_differential_analysis(container);
	handle_movement(container);
	draw_mini_map(container);
	animation(container);
	fps(frame_start_time);
	return (SUCCESS);
}

static long	get_time_in_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

static void	fps(long frame_start_time)
{
	long	frame_end_time;
	long	frame_duration;

	frame_end_time = get_time_in_ms();
	frame_duration = frame_end_time - frame_start_time;
	if (frame_duration < FRAME_TIME_MS)
		usleep((FRAME_TIME_MS - frame_duration) * 1000);
}
