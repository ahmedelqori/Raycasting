/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:15:54 by ael-qori          #+#    #+#             */
/*   Updated: 2024/10/25 14:23:14 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_BONUS_H
# define STRUCTURES_BONUS_H

# include "cub_bonus.h"

// ================ PARSING PART ================ //

typedef struct s_parsing
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				floor;
	int				ceil;
	char			*map[MAX_LINE];
	int				map_x;
	int				map_y;
	char			direction;
}	t_parsing;

// ================ EXECUTION PART ================ //

typedef struct s_vector
{
	double	horz;
	double	vert;
}	t_vector;

typedef struct s_parsing_helper
{
	int	no_found;
	int	so_found;
	int	ea_found;
	int	we_found;
	int	c_found;
	int	f_found;
	int	player_found;
}	t_parsing_helper;

typedef struct s_playerentity
{
	int			x;
	int			hit;
	int			mapx;
	int			mapy;
	int			side;
	int			stepy;
	int			stepx;
	int			open;
	bool		fire;
	double		camerax;
	double		perpwalldist;
	t_vector	dir;
	t_vector	pos;
	t_vector	pln;
	t_vector	ray;
	t_vector	sidedist;
	t_vector	delta;
}	t_playerentity;

typedef struct s_colorpalette
{
	int	ceil_rgb[3];
	int	floor_rgb[3];
}	t_colorpalette;

typedef struct s_texturedata
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	int		start_horz;
	int		start_vert;
}	t_texturedata;

typedef struct s_wallproperties
{
	double			wallx;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				texx;
	double			texy;
	t_texturedata	orientations[6];
	t_texturedata	door[2];
	t_texturedata	gun[6];
}	t_wallproperties;

typedef struct s_graphicsbundle
{
	t_texturedata		background;
	t_wallproperties	walls;
}	t_graphicsbundle;

typedef struct s_container
{
	void				*mlx;
	void				*win;
	bool				mouvements[8];
	bool				mouse;
	t_parsing			*data;
	int					width;
	int					height;
	t_playerentity		player;
	t_colorpalette		background;
	t_graphicsbundle	bundles;
}	t_container;

#endif
