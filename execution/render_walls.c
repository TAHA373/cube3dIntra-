#include "../cub3d.h"


void ft_getoff_x(t_cube *cube, t_ray *ray, int i) {

(void)i;
    if (ray->is_ver)
        cube->player->offset_x = (int)ray->wall_Hit_y % PIXEL_SIZE;
    else
        cube->player->offset_x  = (int)ray->wall_Hit_x % PIXEL_SIZE;
}
void render_wall(t_ray *ray, t_cube *cube ,int i)
{
    int wall_StripH;
    float rayDistance;
    float distance_project;
    float wall_top;
    float wall_bottom;

    int dis = 0;
    int  r, g, b, a, j;
    rayDistance = ray->distance * cos(ft_periodic(ray->ray_angle)  - cube->player->rotation_angle);

    // Calculate the distance to the projection plane
    distance_project = (WIN_WIDTH / 2) / tan(FOV / 2);
    // Project wall height
    wall_StripH = ((PIXEL_SIZE) / rayDistance) * distance_project;
    // Calculate the top and bottom of the wall strip
    wall_top = (WIN_HEIGHT / 2) - (wall_StripH / 2);
    wall_bottom = (WIN_HEIGHT / 2) + (wall_StripH / 2);


    int y = -1;
    //char **c_colors = ft_split(cube->data->c_color, ',');
    while (++y <  wall_top)
         mlx_put_pixel(cube->image,i, y, ft_pixel(cube->data->carr[0],cube->data->carr[1],cube->data->carr[2],255));

    if (wall_top < 0) wall_top = 0;
    if (wall_bottom >= WIN_HEIGHT) wall_bottom = WIN_HEIGHT - 1;
    ft_getoff_x(cube, ray, i);
    y = wall_top;
    while (y < wall_bottom)
    {
        dis = y - WIN_HEIGHT / 2 + wall_StripH / 2;
        cube->player->offset_y = (dis) * ((float)PIXEL_SIZE / wall_StripH);

        j = (cube->player->offset_x + cube->player->offset_y * PIXEL_SIZE) * 4;
   
        r = cube->east->pixels[j];
        g = cube->east->pixels[j + 1];
        b = cube->east->pixels[j + 2];
        a = cube->east->pixels[j + 3];
        
        if (ray->is_ver)
        {
            if (ray->ray_facing_left)
            {
                        r = cube->west->pixels[j];
                        g = cube->west->pixels[j + 1];
                         b = cube->west->pixels[j + 2];
                         a = cube->west->pixels[j + 3];
            }
            else {
                        r = cube->east->pixels[j];
                        g = cube->east->pixels[j + 1];
                        b = cube->east->pixels[j + 2];
                     a = cube->east->pixels[j + 3];
            }
        }
        else
        {
            if (ray->ray_facing_down)
            {
                        r = cube->south->pixels[j];
                         g = cube->south->pixels[j + 1];
                        b = cube->south->pixels[j + 2];
                        a = cube->south->pixels[j + 3];
            }
            else
            {
                        r = cube->north->pixels[j];
                        g = cube->north->pixels[j + 1];
                         b = cube->north->pixels[j + 2];
                        a = cube->north->pixels[j + 3];
            }
        }
          mlx_put_pixel(cube->image, i, y, ft_pixel(r, g, b, a * exp(-0.00007 * ray->distance)));
        y++;
    }
    y = wall_bottom;

    char **f_colors;
    f_colors = ft_split(cube->data->f_color, ',');
    while (y <  WIN_HEIGHT)
        {
           mlx_put_pixel(cube->image, i, y, ft_pixel(ft_atoi(f_colors[0]),ft_atoi(f_colors[1]),ft_atoi(f_colors[2]), 5));
                y++;
        }
          
        }




        //    printf("kkk\n");
       // mlx_put_pixel(cube->image,i, y, ft_pixel(255, 255, 255, 255* exp(-0.00008 * ray->distance)));
        // if (ray->is_ver)
        //     {
        //         if (ray->ray_facing_left)
        //             mlx_put_pixel(cube->image,i, y, ft_pixel(255, 255, 255,255));
        //         else
        //             mlx_put_pixel(cube->image,i, y, ft_pixel(102, 204, 153,100));
        //         //mlx_put_pixel(cube->image,i, y, ft_pixel(0, 255, 255, 255* exp(-0.00008 * ray->distance)));
        //     } // Drawing in white color for example * exp(-0.004 * ray->distance))
        // else    
        //     {
        //             //mlx_put_pixel(cube->image,i, y, ft_pixel(255, 0, 255, 255* exp(-0.00008 * ray->distance)));
        //         if (ray->ray_facing_down)
        //             mlx_put_pixel(cube->image,i, y, ft_pixel(4, 59, 92, 150));
        //         else
        //             mlx_put_pixel(cube->image,i, y, ft_pixel(234, 239, 44, 100));
        //     } // Drawing in white color for example * exp(-0.004 * ray->distance))