#include "../cub3d.h"
#include <math.h>

void render_wall(t_ray *ray, t_cube *cube ,int i)
{
    int wall_StripH;
    float rayDistance;
    float distance_project;
    int wall_top;
    int wall_bottom;




    rayDistance = ray->distance * cos(ft_periodic(ray->ray_angle)  - ft_periodic(cube->player->rotation_angle));

    // Calculate the distance to the projection plane
    distance_project = (WIN_WIDTH / 2) / tan(FOV / 2);
    // Project wall height
    wall_StripH = (PIXEL_SIZE / rayDistance) * distance_project;
    // Calculate the top and bottom of the wall strip
    wall_top = (WIN_HEIGHT / 2) - (wall_StripH / 2);
    wall_bottom = (WIN_HEIGHT / 2) + (wall_StripH / 2);

    // Ensure wall strip is within screen bounds
    if (wall_top < 0) wall_top = 0;
    if (wall_bottom >= WIN_HEIGHT) wall_bottom = WIN_HEIGHT - 1;

        for (int y = wall_top; y <= wall_bottom; y++)
            mlx_put_pixel(cube->image,i, y, ft_pixel(255, 255, 255, 255 * exp(-0.004 * ray->distance))); // Drawing in white color for example

     }