/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 21:14:04 by tkannane          #+#    #+#             */
/*   Updated: 2024/07/23 17:00:31 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../MLX42/include/MLX42/MLX42.h"
#include <math.h>
#include <limits.h>

#define MAP_WIDTH 15
#define MAP_HEIGHT 11
#define WIN_WIDTH MAP_WIDTH * PIXEL_SIZE 
#define WIN_HEIGHT  MAP_HEIGHT * PIXEL_SIZE 
#define PIXEL_SIZE 32
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
void    render_wall(t_ray *ray, t_cube *cube);
//void    draw_ray_wall_hit(t_cube *cube,t_ray *ray);
