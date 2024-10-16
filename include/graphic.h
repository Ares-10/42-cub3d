/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:21:25 by hyungcho          #+#    #+#             */
/*   Updated: 2024/10/13 16:47:12 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

# define KEY_PRESS		2
# define DESTROY_NOTIFY	17
# define ESC			53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_LEFT		123
# define KEY_RIGHT		124

# define P_SPEED			0.1
# define P_ANGULAR_SPEED	3.0

# define TEX_SIZE			128

# include <math.h>
# include "mlx.h"
# include "cub3d.h"

typedef struct s_wall
{
	int		wall_height;
	int		draw_start;
	int		draw_end;
	double	step;
	double	tex_pos;
	int		texture_index;
}	t_wall;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_player
{
	t_vector		pos;
	t_vector		dir;
	t_vector		plane;
	double			degree;
}	t_player;

typedef struct s_ray
{
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		side;
	double	perp_wall_dist;
	double	wall_x;
	int		tex_x;
}	t_ray;

typedef struct s_img
{
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_game
{
	void			*images[4];
	unsigned int	wall_color[4][128][128];
	void			*mlx;
	void			*win;
	int				win_width;
	int				win_height;
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
	char			**map;
	unsigned int	ceiling_color;
	unsigned int	floor_color;
	t_player		player;
}	t_game;

//graphic.c
void		draw(t_game *game);
int			key_press(int keycode, t_game *game);

/* graphic_init.c */
t_game		init_game(t_data *data, t_img_path img_path);
t_vector	degree_to_vector(double degree);
t_vector	dir_to_plane(t_vector dir);
void		init_player(t_game *game, t_data *data);
t_game		init_game(t_data *data, t_img_path img_path);

//init_ray
void		initialize_ray(t_game *game, t_ray *ray);

/* graphic_draw.c */
void		draw_background(t_game *game);
void		draw_wall(t_game *game);

/* graphic_utils.c */
void		my_mlx_pixel_put(t_game *game, int x, int y, int color);

//draw_texture
void		make_wall_color(t_game *game);

// calculate_texture
void		calculate_ray_direction(t_game *game, int i, t_ray *ray);
void		calculate_texture(t_ray *ray, t_game *game);
int			determine_texture_index(t_ray *ray);
void		calculate_wall_dimensions(t_game *game, t_ray *ray, t_wall *wall);

//move
void		move_forward(t_game *game);
void		move_backward(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);

//rotate
void		rotate_left(t_game *game);
void		rotate_right(t_game *game);

#endif
