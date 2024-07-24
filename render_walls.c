#include "execution.h"

void render_wall(t_ray *ray, t_cube *cube)
{
    float wall_StripH;
    float rayDistance;
    float distance_project;
    int wall_top;
    int wall_bottom;
    int wall_x_start = ray->wall_Hit_x; // The starting x-coordinate on the screen where the wall strip starts
    int wall_x_end = wall_x_start + 200; // The ending x-coordinate based on the strip width

    rayDistance = ray->distance;
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
//int i = 0;
    // Draw the wall strip as a rectangle
    for (int x = wall_x_start; x < wall_x_end; x++)
    {
        for (int y = wall_top; y <= wall_bottom; y++)
            mlx_put_pixel(cube->image, x, y, ft_pixel(255, 255, 255, 255)); // Drawing in white color for example
        }
    }

// void rende_wall(t_ray *ray, t_cube *cube)
// {
//     float wall_StripH;
//     float rayDistance;
//     float distance_project;
//    int wall_top;
//     int wall_bottom;
//    // int i = 0;
//     //int wall_x; 
//     rayDistance = ray->distance;
//     printf("%f\n", rayDistance);
//     // Calculate the distance to the projection plane 
//     distance_project = (WIN_WIDTH / 2) / tan(FOV / 2);
//     //project Wall height
//     wall_StripH = (PIXEL_SIZE / rayDistance) * distance_project;
//         // Calculate the top and bottom of the wall strip
//     wall_top = (WIN_HEIGHT / 2) - (wall_StripH / 2);
//     wall_bottom = (WIN_HEIGHT / 2) + (wall_StripH / 2);

//     // Ensure wall strip is within screen bounds
//     if (wall_top < 0) wall_top = 0;
//     if (wall_bottom >= WIN_HEIGHT) wall_bottom = WIN_HEIGHT - 1;

//     // Draw the wall strip
//     for (int y = wall_top; y <= wall_bottom; y++)
//     {
//        // if (i < WIN_WIDTH)
//             mlx_put_pixel(cube->image, 200 , y, ft_pixel(255, 255, 255, 255));
//         //i++; // Drawing in white color for example
//     }

// }