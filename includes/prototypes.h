/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:15:05 by ael-qori          #+#    #+#             */
/*   Updated: 2024/10/22 21:43:38 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "cub.h"

// ======================= PARSING ======================= //

int				ft_parsing(char *argument, t_parsing *data);
void			ft_free_parsing(t_parsing *data);
void			free_buffer(char **buffer, int flag);
char			**ft_verify_content(char **file, t_parsing *data);
int				ft_verify_data(char **file, t_parsing *data);
int				ft_verify_textures(char **buffer, t_parsing *data,
					t_parsing_helper *helper);
int				buffer_counting(char **string);
int				ft_verify_floor_ceil(char **buffer, t_parsing *data,
					t_parsing_helper *helper);
int				is_wall(char c);
int				is_space(char c);
int				is_empty_space(char c);
int				is_orientation(char c);
int				ft_check_entity(char c);
int				ft_verify_map(t_parsing *data);
int				ft_normalize_map(t_parsing *data);
char			**get_file(char *string);
void			read_and_update_buffer(char **buffer, ssize_t *bytes, int fd,
					char **new_buffer);
int				ft_memchr_line(char *s, char c);
char			*ft_strdup_line(const char *s1, int j);
char			*get_next_line(int fd);
int				ft_strcmp_1(char *s1, char *s2);
char			*ft_substr(char *str);
char			*ft_strjoin(char *s1, char *s2);
char			**ft_split_2(char *string);
int				is_num(char *line);

// ======================= EXECUTION ======================= //

void			ft_execute(t_parsing *parsing);
void			safe_exit(t_parsing *parsing, int status, char *error);
void			initialize_defaults(t_container *container);
int				terminate_with_cleanup(int key, t_container *container);
int				mouse_hook(t_container *container);
void			handle_events(t_container *container);
int				update_render(t_container *cub);
void			initialize_images(t_container *container);
void			initialize_to_zero(t_container *container);
void			handle_movement(t_container *container);
void			draw_floor_ceil(t_container *container);
void			calc_ray_for_y_x(t_container *container);
void			calculate_camera_direction(t_container *game);
void			calc_step_for_y_x(t_container *container);
void			draw_images_to_game(t_container *game, int x);
void			digital_differential_analysis(t_container *game);
void			check_hit(t_container *container);

#endif
