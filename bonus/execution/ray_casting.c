/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:12:49 by tkannane          #+#    #+#             */
/*   Updated: 2024/08/12 21:02:47 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int check_wall2(t_cube *cube, float new_x, float new_y)
{
    int x, y;
    int len;
    x = floor(new_x / PIXEL_SIZE);
    y = floor(new_y / PIXEL_SIZE);

    if (x >= cube->map_width || y >= cube->map_height || x < 0 || y < 0)
        return (0);
    len = ft_strlen(cube->map[y]);
    if (x >= len)
        return (0);
    if (cube->map[y][x] == '1' || cube->map[y][x] == ' ' || (cube->map[y][x] == 'D')) //&& cube->map[(int)(cube->player->y_position / PIXEL_SIZE)][(int)(cube->player->x_position / PIXEL_SIZE)] != 'D'))
        {
            // if (cube->map[y][x] == 'D')
            //     exit(0);
            //printf("%c\n",cube->map[y][x]); 
            return (0); 
        }
    
    return (1);
}
float ft_periodic(float angle)
{
    while (angle < 0)
        angle += (2 * 3.14);
    while (angle > (2 * 3.14))
        angle -= (2 * 3.14);
    return angle;
}
void draw_ray_wall_hit(t_cube *cube, int x1, int y1, int x2, int y2)
{
    x1 *= 0.2;
    y1 *= 0.2;
    x2 *= 0.2;
    y2 *= 0.2;
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2 = 0;
    while (1)
    {
        mlx_put_pixel(cube->image, x1, y1, ft_pixel(180, 225, 155, 100));
        if (x1 == x2 && y1 == y2)
            break;
        e2 = err;
        if (e2 > -dx)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            y1 += sy;
        }
    }
}

void draw_rays(float ray_angle, t_cube *cube)
{
    int i;
    float x, y;

    i = 0;
    while (i < 30)
    {
        x = cube->player->x_position + cos(ray_angle) * i;
        y = cube->player->y_position + sin(ray_angle) * i;
        mlx_put_pixel(cube->image, x, y, ft_pixel(135, 206, 235, 1));
        i++;
    }
}
void initialize_tray(t_ray *ray, float ray_angle)
{
    ray->ray_angle = ray_angle;
    ray->wall_Hit_x = 0;
    ray->wall_Hit_y = 0;
    ray->distance = 0;
    if (ray_angle > 0 && ray_angle < MATH_PI)
        ray->ray_facing_down = 1;
    else
        ray->ray_facing_down = 0;
    if (!ray->ray_facing_down) //!(ray_angle > 0 && ray_angle < MATH_PI)
        ray->ray_facing_up = 1;
    else
        ray->ray_facing_up = 0;
    if (ray_angle < 0.5 * MATH_PI || ray_angle > 1.5 * MATH_PI)
        ray->ray_facing_right = 1;
    else
        ray->ray_facing_right = 0;

    if (!ray->ray_facing_right) //!(ray_angle < 0.5 * MATH_PI || ray_angle > 1.5 *MATH_PI)
        ray->ray_facing_left = 1;
    else
        ray->ray_facing_left = 0;
    ray->distance = 0;
}
float distance_Between_Points(float p_x, float p_y, float hit_x, float hit_y)
{
    return (sqrt(((hit_x - p_x) * (hit_x - p_x)) + ((hit_y - p_y) * (hit_y - p_y))));
}
float ft_cheking_up(t_ray *ray, float *y)
{
    if (ray->ray_facing_up)
        (*y)--;
    return (*y);
}
float ft_cheking_left(t_ray *ray, float *x)
{
    if (ray->ray_facing_left)
    {
        // printf("here\n");
        (*x)--;
    }
    return (*x);
}

void checkhit(t_ray *ray, t_cube *cube)
{
    int x, y;

    x = ray->wall_Hit_x / PIXEL_SIZE;
    y = ray->wall_Hit_y / PIXEL_SIZE;

    // if (x >= cube->map_width || y >= cube->map_height || x < 0 || y < 0)
    //     return;

    // int len = ft_strlen(cube->map[y]);
    // if (x >= len)
    //     return;

    if (cube->map[y][x] == '1')
    {
        ray->content = '1';
    }
    else if (cube->map[y][x] == 'D' )//&& (cube->map[y][x] == 'D' && cube->map[(int)(cube->player->y_position / PIXEL_SIZE)][(int)(cube->player->x_position / PIXEL_SIZE)] != 'D'))
    {
        ray->content = 'D';
    }
}

void check_for_H(t_ray *ray, float x_intercept, float y_intercept, t_cube *cube)
{
    float next_hor_x;
    float next_hor_y;

    next_hor_x = x_intercept;
    next_hor_y = y_intercept ;//+ (ray->ray_facing_up ? -1 : 0);
    // if (ray->ray_facing_up)
    //     next_hor_y--;
    int hit_wall = 0;

    while (next_hor_x >= 0 && next_hor_y >= 0 && next_hor_x < cube->map_width * PIXEL_SIZE && next_hor_y < cube->map_height * PIXEL_SIZE)
    {
        if (!check_wall2(cube, next_hor_x, ft_cheking_up(ray,&next_hor_y))) // 7AYDT HNA DIK LFUNCTION LIKATCHECKI BIHA (ray->ray_facing_up? -1 : 0)
        {
            // if (ray->ray_facing_up)
            //     next_hor_y--;
            ray->wall_Hit_x = next_hor_x;
            ray->wall_Hit_y = next_hor_y;
            // draw_ray_wall_hit(cube, cube->player->x_position, cube->player->y_position, ray->wall_Hit_x, ray->wall_Hit_y);
            hit_wall = 1;
            break;
        }
        else
        {
            next_hor_x += ray->x_step;
            next_hor_y += ray->y_step;
        }
    }
    if (hit_wall)
        ray->distance = distance_Between_Points(cube->player->x_position, cube->player->y_position, ray->wall_Hit_x, ray->wall_Hit_y);
    else
        ray->distance = INT_MAX;
}

void check_for_V(t_ray *ray, float x_intercept, float y_intercept, t_cube *cube)
{
    float next_ver_x;
    float next_ver_y;

    next_ver_x = x_intercept ;//+ (ray->ray_facing_left ? -1 : 0);
    next_ver_y = y_intercept;
    // if (ray->ray_facing_left)
    //     next_ver_x--;
    int hit_wall = 0;
    // Increment xstep and ystep until we find a wall
    while (next_ver_x >= 0 && next_ver_y >= 0 && next_ver_x <= cube->map_width * PIXEL_SIZE && next_ver_y <= cube->map_height * PIXEL_SIZE)
    {
        if (!check_wall2(cube, ft_cheking_left(ray, &next_ver_x), next_ver_y)) // 7AYDT HNA DIK LFUNCTION LIKATCHECKI BIHA (ray->ray_facing_left? -1 : 0);
        {
            ray->wall_Hit_x = next_ver_x;
            ray->wall_Hit_y = next_ver_y;
            hit_wall = 1;
            break;
        }
        else
        {
            next_ver_x += ray->x_step;
            next_ver_y += ray->y_step;
        }
    }
    if (hit_wall)
        ray->distance = distance_Between_Points(cube->player->x_position, cube->player->y_position, ray->wall_Hit_x, ray->wall_Hit_y);
    else
        ray->distance = INT_MAX;
    //  printf("%d\n", hit_wall);
}
void horizantal_ray(t_ray *ray, float ray_angle, t_cube *cube)
{
    float y_intercept;
    float x_intercept;

    initialize_tray(ray, ray_angle);
    // float x_step, y_step;
    /*HORIZONTAL RAY INTERSECTION CODE */

    /* FIND THE Y_COORDINATE OF THE CLOSEST HORIZANTAL GRID INTERSECTION*/
    y_intercept = floor(cube->player->y_position / PIXEL_SIZE) * PIXEL_SIZE;
    if (ray->ray_facing_down)
        y_intercept += PIXEL_SIZE;
    /* FIND THE x_COORDINATE OF THE CLOSEST HORIZANTAL GRID INTERSECTION*/

    x_intercept = cube->player->x_position + (y_intercept - cube->player->y_position) / tan(ray_angle);
    /* CALCULATE THE INCREMENT X_STEP AND THE Y_STEP*/
    ray->y_step = PIXEL_SIZE;
    if (ray->ray_facing_up)
        ray->y_step *= -1;

    ray->x_step = PIXEL_SIZE / tan(ray_angle);
    if (ray->ray_facing_left && ray->x_step > 0)
        ray->x_step *= -1;
    else
        ray->x_step *= 1;
    if (ray->ray_facing_right && ray->x_step < 0)
        ray->x_step *= -1;
    else
        ray->x_step *= 1;
    check_for_H(ray, x_intercept, y_intercept, cube);
}
void vertical_ray(t_ray *ray, float ray_angle, t_cube *cube)
{
    float y_intercept;
    float x_intercept;

    initialize_tray(ray, ray_angle);
    // float x_step, y_step;
    /*VERTICAL RAY INTERSECTION CODE */

    /* FIND THE Y_COORDINATE OF THE CLOSEST VERTICAL GRID INTERSECTION*/
    x_intercept = floor(cube->player->x_position / PIXEL_SIZE) * PIXEL_SIZE;
    if (ray->ray_facing_right)
        x_intercept += PIXEL_SIZE;
    /* FIND THE x_COORDINATE OF THE CLOSEST VERTICAL GRID INTERSECTION*/

    y_intercept = cube->player->y_position + (x_intercept - cube->player->x_position) * tan(ray_angle);
    /* CALCULATE THE INCREMENT _STEP AND THE Y_STEP*/
    ray->x_step = PIXEL_SIZE;
    if (ray->ray_facing_left)
        ray->x_step *= -1;

    ray->y_step = PIXEL_SIZE * tan(ray_angle);
    if (ray->ray_facing_up && ray->y_step > 0)
        ray->y_step *= -1;
    else
        ray->y_step *= 1;
    if (ray->ray_facing_down && ray->y_step < 0)
        ray->y_step *= -1;
    else
        ray->y_step *= 1;
    check_for_V(ray, x_intercept, y_intercept, cube);
}
t_ray cast_the_ray(t_cube *cube, float ray_angle, int i)
{
    t_ray ray_horizantal;
    t_ray ray_vertical;
    t_ray final_ray;
    horizantal_ray(&ray_horizantal, ray_angle, cube);
    vertical_ray(&ray_vertical, ray_angle, cube);
    // initialize_tray(&final_ray, ray_angle);
    // final_ray.distance = 0;
    if (ray_horizantal.distance < ray_vertical.distance)
    {
        final_ray.ray_angle = ray_horizantal.ray_angle;
        final_ray.wall_Hit_x = ray_horizantal.wall_Hit_x;
        final_ray.wall_Hit_y = ray_horizantal.wall_Hit_y;
        final_ray.distance = ray_horizantal.distance;
        final_ray.ray_facing_down = ray_horizantal.ray_facing_down;
        final_ray.ray_facing_up = ray_horizantal.ray_facing_up;
        final_ray.ray_facing_left = ray_horizantal.ray_facing_left;
        final_ray.ray_facing_right = ray_horizantal.ray_facing_right;
        final_ray.is_ver = 0;
    }
    else
    {
        final_ray.ray_facing_down = ray_vertical.ray_facing_down;
        final_ray.ray_facing_up = ray_vertical.ray_facing_up;
        final_ray.ray_facing_left = ray_vertical.ray_facing_left;
        final_ray.ray_facing_right = ray_vertical.ray_facing_right;
        final_ray.ray_angle = ray_vertical.ray_angle;
        final_ray.wall_Hit_x = ray_vertical.wall_Hit_x;
        final_ray.wall_Hit_y = ray_vertical.wall_Hit_y;
        final_ray.distance = ray_vertical.distance;
        final_ray.is_ver = 1;
    }
    // printf("%c\n", cube->map[(int)final_ray.wall_Hit_y / PIXEL_SIZE][(int)final_ray.wall_Hit_x / PIXEL_SIZE]);
    checkhit(&final_ray, cube);
    render_wall(&final_ray, cube, i);

    return (final_ray);
}

bool checkplayer(t_cube *data)
{
	if (data->door_y > 0 && data->door_x > 0 && data->map[data->door_y][data->door_x] == 'C')
	{
		if (data->map[data->door_y][data->door_x + 1] == 'W'
			|| data->map[data->door_y][data->door_x - 1] == 'W'
			|| data->map[data->door_y + 1][data->door_x] == 'W'
			|| data->map[data->door_y - 1][data->door_x] == 'W')
		return true;
	}
    return false;
}

void cast_rays(t_cube *cube)
{
    float ray_angle;
    float limit_angle;
    bool check = false;
    t_ray ray;
    t_ray *max_door_ray = (t_ray*)malloc(sizeof(t_ray));
    max_door_ray->distance = 0;
    int i = 0;

    ray_angle = cube->player->rotation_angle - (FOV / 2);
    ray_angle = ft_periodic(ray_angle);
    limit_angle = cube->player->rotation_angle + (FOV / 2);
    limit_angle = ft_periodic(limit_angle);
    while (i < WIN_WIDTH)
    {
        ray_angle = ft_periodic(ray_angle);
        ray = cast_the_ray(cube, ray_angle, i);
        if (ray.distance > max_door_ray->distance && ray.content == 'D')
        {
            max_door_ray = &ray;
            check = true;
        }
        // draw_ray_wall_hit(cube, cube->player->x_position , cube->player->y_position ,  ray.wall_Hit_x ,  ray.wall_Hit_y );
        ray_angle += FOV / (WIN_WIDTH);

        i++;
    }
    if (max_door_ray->distance < 10 && max_door_ray->content == 'D')
    {
        cube->isfacingdoor = true;
        cube->door_x = max_door_ray->wall_Hit_x / PIXEL_SIZE;
        cube->door_y = max_door_ray->wall_Hit_y / PIXEL_SIZE;
    }
    else
        cube->isfacingdoor = false;
    //checkplayer(cube);
        
    //  display_map(cube);
    // draw_rays(limit_angle, cube);
}
