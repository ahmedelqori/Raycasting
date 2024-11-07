/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relhamma <relhamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:15:54 by ael-qori          #+#    #+#             */
/*   Updated: 2024/09/16 13:15:54 by relhamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "cub.h"

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
	bool				mouvements[6];
	t_parsing			*data;
	t_playerentity		player;
	t_colorpalette		background;
	t_graphicsbundle	bundles;
}	t_container;

#endif
