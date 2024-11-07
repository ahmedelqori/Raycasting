/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:16:18 by ael-qori          #+#    #+#             */
/*   Updated: 2024/10/24 15:00:31 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# include "cub.h"

// ================== Colors =============

# define RESET "\033[0m"
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define BOLDBLACK "\033[1m\033[30m"
# define BOLDRED "\033[1m\033[31m"
# define BOLDGREEN "\033[1m\033[32m"
# define BOLDYELLOW "\033[1m\033[33m"
# define BOLDBLUE "\033[1m\033[34m"
# define BOLDMAGENTA "\033[1m\033[35m"
# define BOLDCYAN "\033[1m\033[36m"
# define BOLDWHITE "\033[1m\033[37m"

// ================== Status =============

# define FAIL -1 // check error
# define SUCCESS 0

# define TRUE 1
# define FALSE 0

# define INDEX 0
# define START -1
// ================== Game =============

# define NAME "CUB"
# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 768

# define NORTH 'N'
# define SOUTH 'S'
# define WEST  'W'
# define EAST  'E'

# define X 'x'
# define Y 'y'

# define CX 0
# define CY 1

# define WX 0
# define WY 1

# define NORTH_X 0.0f
# define NORTH_Y -1.0f
# define SOUTH_X 0.0f
# define SOUTH_Y 1.0f
# define EAST_X 1.0f
# define EAST_Y 0.0f
# define WEST_X -1.0f
# define WEST_Y 0.0f

# define DIR_NORTH_HORZ 0.0f
# define DIR_SOUTH_HORZ 0.0f
# define DIR_EAST_HORZ 1.0f
# define DIR_WEST_HORZ -1.0f

# define DIR_NORTH_VERT -1.0f
# define DIR_SOUTH_VERT 1.0f
# define DIR_EAST_VERT 0.0f
# define DIR_WEST_VERT 0.0f

# define PLN_NORTH_HORZ 0.66f
# define PLN_SOUTH_HORZ -0.66f
# define PLN_EAST_HORZ 0.0f
# define PLN_WEST_HORZ 0.0f

# define PLN_NORTH_VERT 0.0f
# define PLN_SOUTH_VERT 0.0f
# define PLN_EAST_VERT 0.66f
# define PLN_WEST_VERT -0.66f

# define MOVE_SPEED 0.02f
# define ROTATION_SPEED 0.01f
# define MOUSE_SENSITIVITY 0.1f

# define DISTANCE_IN_FORWARD -0.22f
# define DISTANCE_IN_BACKWARD 0.8f
# define DISTANCE_IN_LEFT -0.15f
# define DISTANCE_IN_RIGHT 0.15f
# define MAXDOUBLE 1e30

# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_W 119
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define ESC 65307

# define UP 'W'
# define DOWN 'S'
# define LEFT 'A'
# define RIGHT 'D'
# define CAMERA_LEFT 'L'
# define CAMERA_RIGHT 'R'
# define WALL '1'

// ================== ERRORS =============

# define ALLOC_CONTAINER "Failed Allocation of container"
# define ERROR_MAP "Error\nEnter a valid number of argument\n"
# define ERROR_TEXTURES "Error In Textures\n"
// =================PARSING=====================

# ifndef MAX_LINE
#  define MAX_LINE 4096
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif
