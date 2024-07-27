/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 21:14:07 by tkannane          #+#    #+#             */
/*   Updated: 2024/07/27 00:50:45 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int ft_pixel(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}
void display_map(t_cube *cube)
{

    int color;
    int i,j;
    int x,y;
    i = 0;
    j = 0;
    x = 0;
    y = 0;

    while (i < MAP_HEIGHT)
    {
        j = 0;
        while (j < MAP_WIDTH)
        {
            if (cube->map[i][j] == '1')
                color = ft_pixel(255, 255, 255, 255);
            else
                color = ft_pixel(0, 0, 0, 255);
            while (y < PIXEL_SIZE)
            {
                x = 0;
                while (x < PIXEL_SIZE)
                {
                    mlx_put_pixel(cube->image,( j * PIXEL_SIZE + x) * 0.2, (i * PIXEL_SIZE + y )* 0.2, color);
                    if (x == PIXEL_SIZE - 1 || y == PIXEL_SIZE - 1)
                         mlx_put_pixel(cube->image, j * PIXEL_SIZE + x, i * PIXEL_SIZE + y, ft_pixel(0, 0, 0, 255));
                     x++;
                }
                y++;
                
            }
            j++;
            y = 0;
            
        }
        i++;
    }


}
// void display_map(t_cube *cube)
// {
//     int color;
//     int i, j;
//     int x, y;
//     float scale = 0.2; // Scaling factor for the minimap
//     int scaled_pixel_size = (int)(PIXEL_SIZE * scale);

//     for (i = 0; i < MAP_HEIGHT; i++)
//     {
//         for (j = 0; j < MAP_WIDTH; j++)
//         {
//             if (cube->map[i][j] == '1')
//                 color = ft_pixel(255, 255, 255, 255);
//             else
//                 color = ft_pixel(0, 0, 0, 255);

//             // Draw the scaled tile with borders
//             for (y = 0; y <= scaled_pixel_size; y++)
//             {
//                 for (x = 0; x <= scaled_pixel_size; x++)
//                 {
//                     int scaled_x = j * scaled_pixel_size + x;
//                     int scaled_y = i * scaled_pixel_size + y;

//                     // Determine the color for the pixel
//                     if (x == 0 || y == 0 || x == scaled_pixel_size - 1  || y == scaled_pixel_size - 1)
//                     {
//                         // Border pixel
//                         mlx_put_pixel(cube->image, scaled_x, scaled_y, ft_pixel(0, 0, 0, 255));
//                     }
//                     else
//                     {
//                         // Inner pixel
//                         mlx_put_pixel(cube->image, scaled_x, scaled_y, color);
//                     }
//                 }
//             }
//         }
//     }
// }

void clear_image(mlx_image_t* image)
{
    int x = 0;
    int y = 0;

    while (y < WIN_HEIGHT)
    {
        x = 0;
        while (x < WIN_WIDTH)
        {
            mlx_put_pixel(image, x, y, ft_pixel(0, 0, 0, 0));
            x++;
        }
        y++;
    }
}
    
void ft_release(t_cube *cube)
{
    cube->player->b_f_directions = 0;
	cube->player->l_r_directions = 0;

}
int check_wall(t_cube *cube, float new_x, float new_y)
{
    int x,y;
    
    x = floor(new_x / PIXEL_SIZE);
    y = floor( new_y / PIXEL_SIZE);

    if (x >= MAP_WIDTH || y >= MAP_HEIGHT)
        return (1);
    if (cube->map[y][x] == '1')
        {
            //exit(0);
            return (0);
        }
    return (1);
}
int arround_player(t_cube *cube, float new_x, float new_y)
{
    int     i;
    float   x;
    float   y;
    (void)new_x;
    (void)new_y;
    i = 0;
    x = 0;
    y = 0;
    while (i < 360)
    {
        x = new_x +  cos(i * MATH_PI / 180) * (cube->player->radius);
        y = new_y +  sin(i * MATH_PI / 180) * (cube->player->radius);
        if (!check_wall(cube, x, y) || !check_wall(cube, new_x, new_y))
            break ;
        i++;
    }
    if (i != 360)
        return (0);
    return (1);
}
void update_player_place(t_cube *cube)
{
	int move_step;
    float new_x = 0;
    float new_y = 0;
	move_step = 0;
    cube->player->rotation_angle += cube->player->palyer_rotation_speed * cube->player->l_r_directions;
    cube->player->rotation_angle = ft_periodic(cube->player->rotation_angle);
	move_step = cube->player->b_f_directions * cube->player->player_move_speed;
	new_x = cube->player->x_position +  cos(cube->player->rotation_angle) * move_step;
	new_y = cube->player->y_position +  sin(cube->player->rotation_angle) * move_step;
    if (arround_player(cube, new_x, new_y)) //&&check_wall(cube, new_x, new_y)
    {
        cube->player->x_position = new_x;
        cube->player->y_position = new_y;
    }
   ft_release(cube);
}
void draw_circle(mlx_image_t *image, float center_x, float center_y, int radius, int color) 
{
    float y;
    float x;
    x = -radius;
    y= -radius;
    while(y <= radius)
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
void draw_line(t_cube *cube)
    {
        int i;
        float x, y;

        i = 0;
        while (i < 30)
        {
            x = cube->player->x_position + cos(cube->player->rotation_angle) * i;
            y = cube->player->y_position + sin(cube->player->rotation_angle) * i;
            mlx_put_pixel(cube->image, x * 0.2, y * 0.2,   ft_pixel(135,206,235 ,1));
            i++;

        }
    }





void key_released(void *param)
{
	    
		t_cube *cube;

        cube = (t_cube *)param;
        if (mlx_is_key_down(cube->mlx_win, MLX_KEY_UP))
        {
			cube->player->b_f_directions = 0;
        }
        if (mlx_is_key_down(cube->mlx_win, MLX_KEY_DOWN))
        {
			cube->player->b_f_directions = 0;
        }
        if (mlx_is_key_down(cube->mlx_win, MLX_KEY_LEFT))
        {
            cube->player->l_r_directions = 0;
        }
        if (mlx_is_key_down(cube->mlx_win, MLX_KEY_RIGHT))
        {
            cube->player->l_r_directions = 0;
        }
        
}


void key_press(void *param)
{
        t_cube *cube;

        cube = (t_cube *)param;
        if (mlx_is_key_down(cube->mlx_win, MLX_KEY_ESCAPE))
		{
                mlx_close_window(cube->mlx_win);
        }
        if (mlx_is_key_down(cube->mlx_win, MLX_KEY_UP))
        {
			    cube->player->b_f_directions = 1;
			    update_player_place(cube);
        }
        if (mlx_is_key_down(cube->mlx_win, MLX_KEY_DOWN))
        {
            //printf("gg\n");
			cube->player->b_f_directions = -1;
			 update_player_place(cube);
        }
        if (mlx_is_key_down(cube->mlx_win, MLX_KEY_LEFT))
        {
            cube->player->l_r_directions = -1;
             update_player_place(cube);
        }
        if (mlx_is_key_down(cube->mlx_win, MLX_KEY_RIGHT))
        {
            cube->player->l_r_directions = 1;
             update_player_place(cube);
        }
        clear_image(cube->image);
        // display_map(cube);
        // draw_circle(cube->image, cube->player->x_position *0.2, cube->player->y_position * 0.2, cube->player->radius * 0.2, ft_pixel(135,206,235 ,1));
        // draw_line(cube);
        cast_rays(cube);
        return ;
        
}

int32_t main(int argc, char **argv)
{
    t_cube cube;
    t_player player;
    mlx_image_t *black_img;
    //PARSING
    t_map_data data;
    data.no_path = NULL;
	data.so_path = NULL;
	data.ea_path = NULL;
	data.we_path = NULL;
	data.c_color = NULL;
	data.f_color = NULL;
    ft_parsing(argc, argv, &data);

    player.x_position = WIN_WIDTH / 2;
    player.y_position = WIN_HEIGHT / 2;
    player.radius = 5;
    player.l_r_directions = 0;
    player.b_f_directions = 0;
    player.rotation_angle = MATH_PI / 2;
    player.player_move_speed = 3;
    player.palyer_rotation_speed = 2 * (MATH_PI / 180);

    cube.player = &player;
    //color = 0;
    int i = 0;
    cube.map = malloc(sizeof(char *) * MAP_HEIGHT);
    while  (i < MAP_HEIGHT)
    {
        cube.map[i] = malloc(sizeof(char ) * MAP_WIDTH);
        i++;
    }
    cube.map[0] = "111111111111111";
    cube.map[1] = "100000000000101";
    cube.map[2] = "100000000000101";
    cube.map[3] = "100000000000101";
    cube.map[4] = "100000000000101";
    cube.map[5] = "100000000111101";
    cube.map[6] = "100000000100001";
    cube.map[7] = "100000000100001";
    cube.map[8] = "100000000000001";
    cube.map[9] = "111111000001111";
   cube.map[10] = "111111111111111";

    if (!(cube.mlx_win= mlx_init(WIN_WIDTH, WIN_HEIGHT, "Cube3D", false))) {
        puts(mlx_strerror(mlx_errno));
        return (EXIT_FAILURE);
    }
    black_img = mlx_new_image(cube.mlx_win, WIN_WIDTH, WIN_HEIGHT);
    for (int y = 0; y < WIN_HEIGHT; y++)
    {
        for (int x = 0; x < WIN_WIDTH; x++)
            mlx_put_pixel(black_img,  x, y, ft_pixel(0, 0, 0, 255));
    }
    mlx_image_to_window(cube.mlx_win, black_img, 0, 0);

    if (!(cube.image = mlx_new_image(cube.mlx_win, WIN_WIDTH, WIN_HEIGHT))) {
        mlx_close_window(cube.mlx_win);
        puts(mlx_strerror(mlx_errno));
        return (EXIT_FAILURE);
    }
    // display_map(&cube);
   // draw_circle(cube.image, player.x_position, player.y_position, player.radius, ft_pixel(135,206,235 ,1));
    //draw_line(&cube);
    //cast_rays(&cube);
    if (mlx_image_to_window(cube.mlx_win, cube.image, 0, 0) == -1) {
        mlx_close_window(cube.mlx_win);
        puts(mlx_strerror(mlx_errno));
        return (EXIT_FAILURE);
    }
    mlx_loop_hook(cube.mlx_win, key_press, &cube);

	//mlx_loop_hook(cube.mlx_win, key_released, &cube);
    mlx_loop(cube.mlx_win);
    mlx_terminate(cube.mlx_win);
	
    return (EXIT_SUCCESS);
}