#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42/include/MLX42/MLX42.h"
# include "./parsing/get_next_line.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
//# include <mlx.h>

#include <math.h>
#include <limits.h>

#define PIXEL_SIZE 70
#define MAP_WIDTH 15
#define MAP_HEIGHT 11
#define WIN_WIDTH 1500
#define WIN_HEIGHT 1000
#define MATH_PI 3.14159265358979323846
#define FOV 60 * (MATH_PI / 180)
#define NUM_OF_RAYS 480 / 10
#define MINI_MAP_SCALE  0.2




typedef struct s_player
{
    float     x_position;
    float     y_position;
    int       radius;
    int       l_r_directions;
    int       b_f_directions;
    float   rotation_angle;
    int     player_move_speed;
    float   palyer_rotation_speed;


} t_player;

typedef struct s_cube
{
    t_player    *player;
    mlx_t       *mlx_win;
    mlx_image_t *image;
    char         **map;
} t_cube;

typedef struct s_ray
{
    float ray_angle;
    float wall_Hit_x;
    float wall_Hit_y;
    float distance;
    int ray_facing_down;
    int ray_facing_up;
    int ray_facing_right;
    int ray_facing_left;
    float x_step;
    float y_step;
}   t_ray;
void    cast_rays(t_cube *cube);
int     ft_pixel(int r, int g, int b, int a);
float   ft_periodic(float angle);
int     check_wall(t_cube *cube, float new_x, float new_y);
void    draw_line(t_cube *cube);
void    cast_rays(t_cube *cube);
void    render_wall(t_ray *ray, t_cube *cube, int i);
//void    draw_ray_wall_hit(t_cube *cube,t_ray *ray);


//PARSING
typedef struct s_pars_info {
	bool	north;
	bool	south;
	bool	east;
	bool	weast;
	bool	floor;
	bool	ceiling;
}	t_pars_info; 

typedef struct s_map_data {
	char		*f_color;
	char		*c_color;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	char		**map;
	char		**cub_map;
	char		direction;
	int			h;
	int			w;
	int			x;
	int			y;
	int			farr[3];
	int			carr[3];
	mlx_texture_t	textures[4]; // no_textures is 0 | south is 1 | east is 2 | west is 3;
	t_pars_info	info;
}	t_map_data;

//ERRORS
void    err_exit(char *s);
void	ft_parsing(int argc, char **argv, t_map_data *data);



#endif