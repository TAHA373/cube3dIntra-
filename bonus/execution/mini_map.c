/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:38:42 by tkannane          #+#    #+#             */
/*   Updated: 2024/08/18 18:19:49 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

float ft_scale_f(float prev)
{
    float new;

    new = (prev * 20) / PIXEL_SIZE;
    return (new);
}
void draw_circle(mlx_image_t *image, float center_x, float center_y, int radius)
{
    float y;
    float x;
    int color;

    color = ft_pixel(95, 209, 23, 255);
    x = -radius;
    y = -radius;
    while (y <= radius)
    {
        x = -radius;
        while (x <= radius)
        {
            if (x * x + y * y <= radius * radius)
            {
                mlx_put_pixel(image, (center_x + x), (center_y + y), color);
            }
            x++;
        }
        y++;
    }
}
void clear_img_mini(mlx_image_t *image)
{
    int x = 0;
    int y = 0;

    while (y < 200)
    {
        x = 0;
        while (x < 200)
        {
            mlx_put_pixel(image, x, y, ft_pixel(0, 0, 0, 0));
            x++;
        }
        y++;
    }
}
void mini_map(t_cube *cube)
{
    float new_x_map;
    float new_y_map;
    int i, j;
    i = 0;
    j = 0;
    int x;
    int y;
    new_y_map = 0;
    new_x_map = 0;
    x = 0;
    y = ft_scale_f(cube->player->y_position) - 100; // 100= mini_map_heigth / 2;
    while (new_y_map < 200)
    {
        new_x_map = 0;
        x = ft_scale_f(cube->player->x_position) - 100;
        while (new_x_map < 200)
        {
            // printf("[%d] [%d]", i, j);
            if (x >= 0 && y >= 0 && x < cube->map_width * 20 && y < cube->map_height * 20)
            {
                i = y / 20;
                j = x / 20;
                // printf("[%c]\n", cube->map[11][28]);
                // if (j <  cube->map_width && i < cube->map_height)
                //  printf("[i = %d j = %d]\n", i, j);
                if (j < (int)ft_strlen(cube->map[i]))
                {
                    if (cube->map[i][j] == '0' || cube->map[i][j] == ' ' || cube->map[i][j] == 'W' || cube->map[i][j] == 'E' || cube->map[i][j] == 'N' || cube->map[i][j] == 'S')
                        mlx_put_pixel(cube->mini_map, new_x_map, new_y_map, ft_pixel(0, 0, 0, 255));
                    else if (cube->map[i][j] == '1')
                        mlx_put_pixel(cube->mini_map, new_x_map, new_y_map, ft_pixel(255, 255, 255, 255));
                    else if (cube->map[i][j] == 'D')
                        mlx_put_pixel(cube->mini_map, new_x_map, new_y_map, ft_pixel(150, 255, 255, 255));
                }
                else
                {
                    mlx_put_pixel(cube->mini_map, new_x_map, new_y_map, ft_pixel(95, 209, 23, 255));
                }
            }

            new_x_map++;
            x++;
        }
        new_y_map++;
        y++;
    }
}