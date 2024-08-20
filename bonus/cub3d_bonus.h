/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:17:04 by soel-bou          #+#    #+#             */
/*   Updated: 2024/08/20 11:18:51 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "./parsing/get_next_line.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <math.h>
# include <limits.h>

# define PIXEL_SIZE 1024
# define WIN_WIDTH 1900
# define WIN_HEIGHT 1080
# define MATH_PI 3.14159265358979323846
# define FOV	1.0472

// Parsing
typedef struct s_pars_info
{
	bool	north;
	bool	south;
	bool	east;
	bool	west;
	bool	floor;
	bool	ceiling;
}	t_pars_info;

typedef struct s_map_data
{
	char			*f_color;
	char			*c_color;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	char			**map;
	char			**cub_map;
	char			direction;
	int				h;
	int				w;
	int				x;
	int				y;
	int				farr[3];
	int				carr[3];
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	mlx_texture_t	*west;
	mlx_texture_t	textures[4];
	t_pars_info		info;
}	t_map_data;

// Errors
void	freemap(char **map);
void	err_exit(char *s);
int		parsmap(t_map_data *data);
void	ft_parsing(int argc, char **argv, t_map_data *data);

// Player
typedef struct s_player
{
	float	x_position;
	float	y_position;
	int		radius;
	int		l_r_directions;
	int		b_f_directions;
	float	rotation_angle;
	int		player_move_speed;
	float	player_rotation_speed;
	int		offset_x;
	int		offset_y;
	float	key_a;
	float	key_d;
}	t_player;

// Colors
typedef struct s_colors
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_colors;
//mini_map

typedef struct s_mini_map
{
	float	new_x_map;
	float	new_y_map;
	int		x;
	int		y;
}	t_mini_map;
// Cube
typedef struct s_cube
{
	t_player		*player;
	mlx_t			*mlx_win;
	mlx_image_t		*mini_map;
	mlx_image_t		*image;
	char			**map;
	mlx_texture_t	*test;
	mlx_image_t		*east;
	mlx_image_t		*west;
	mlx_image_t		*north;
	mlx_image_t		*south;
	int				map_height;
	int				map_width;
	t_map_data		*data;
	mlx_image_t		*frame;
	int				mouse_x;
	int				mouse_y;
	mlx_texture_t	*t_door;
	mlx_image_t		*i_door;
	mlx_texture_t	*texture[4];
	int				door_x;
	int				door_y;
	bool			isfacingdoor;
	int				i;
	int				j;
	int				mini_x;
	int				mini_y;
	int				mini_x_p;
	int				mini_y_p;
}	t_cube;

// Ray
typedef struct s_ray
{
	float		ray_angle;
	float		wall_hit_x;
	float		wall_hit_y;
	float		distance;
	int			ray_facing_down;
	int			ray_facing_up;
	int			ray_facing_right;
	int			ray_facing_left;
	float		x_step;
	float		y_step;
	int			is_ver;
	int			wall_striph;
	float		raydistance;
	float		distance_project;
	float		wall_top;
	float		wall_bottom;
	t_colors	colors;
	char		content;
}	t_ray;

// Function prototypes
void	initialize_data(t_map_data *data);
void	initialize_cube(t_cube *cube, t_map_data *data, t_player *player);
void	animation(void *input);
void	cast_rays(t_cube *cube);
int		ft_pixel(int r, int g, int b, int a);
float	ft_periodic(float angle);
int		check_wall(t_cube *cube, float new_x, float new_y);
void	draw_line(t_cube *cube);
void	render_wall(t_ray *ray, t_cube *cube, int i);
void	display_map(t_cube *cube);
void	update_player_place(t_cube *cube);
void	update_player_place_right(t_cube *cube);
void	update_player_place_left(t_cube *cube);
int		mlx_initialize(t_cube *cube);
void	initialize_image(t_cube *cube);
void	clear_image(mlx_image_t *image);
void	key_press(void *param);
void	ft_release(t_cube *cube);
void	textures_delete(t_cube *cube);
void	image_delete(t_cube *cube);
void	ft_getoff_x(t_cube *cube, t_ray *ray);
void	draw_ceiling(t_cube *cube, int x, int wall_top);
void	draw_floor(t_cube *cube, int x, int wall_bottom);
float	distance_between_points(float p_x, float p_y, float hit_x, float hit_y);
float	ft_cheking_up(t_ray *ray, float *y);
float	ft_cheking_left(t_ray *ray, float *x);
void	initialize_tray(t_ray *ray, float ray_angle);
void	check_for_v(t_ray *ray, float x_intercept, float y_intercept,
			t_cube *cube);
void	check_for_h(t_ray *ray, float x_intercept, float y_intercept,
			t_cube *cube);
void	horizontal_ray(t_ray *ray, float ray_angle, t_cube *cube);
void	vertical_ray(t_ray *ray, float ray_angle, t_cube *cube);
void	get_distance(t_ray *ray, int hit_wall, t_cube *cube);
void	draw_circle(mlx_image_t *image, float center_x, float center_y,
			int radius);
float	ft_scale_f(float prev);
void	clear_img_mini(mlx_image_t *image);
void	mini_map(t_cube *cube);
int		check_wall2(t_cube *cube, float new_x, float new_y);
void	ft_mouse(t_cube *data);
#endif
