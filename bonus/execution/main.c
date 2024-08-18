/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 21:14:07 by tkannane          #+#    #+#             */
/*   Updated: 2024/08/18 18:19:46 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"


// int ft_pixel(int r, int g, int b, int a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

// float ft_scale_f(float prev)
// {
//     float new;

//     new = (prev * 20) / PIXEL_SIZE;
//     return (new);
// }



// void clear_image(mlx_image_t *image)
// {
//     int x = 0;
//     int y = 0;

//     while (y < WIN_HEIGHT)
//     {
//         x = 0;
//         while (x < WIN_WIDTH)
//         {
//             mlx_put_pixel(image, x, y, ft_pixel(0, 0, 0, 0));
//             x++;
//         }
//         y++;
//     }
// }

// void ft_release(t_cube *cube)
// {
//     cube->player->b_f_directions = 0;
//     cube->player->l_r_directions = 0;
//     cube->player->key_a = 0;
// }
// int check_wall(t_cube *cube, float new_x, float new_y)
// {
//     int x, y;
//     int len;
//     x = floor(new_x / PIXEL_SIZE);
//     y = floor(new_y / PIXEL_SIZE);

//     if (x >= cube->map_width || y >= cube->map_height || x < 0 || y < 0)
//         return (0);
//     len = ft_strlen(cube->map[y]);
//     if (x >= len)
//         return (0);
//     if (cube->map[y][x] == '1' || cube->map[y][x] == ' ')
//         {
//             return (0); 
//         }
    
//     return (1);
// }
// int arround_player(t_cube *cube, float new_x, float new_y)
// {
//     int i;
//     float x;
//     float y;
//     (void)new_x;
//     (void)new_y;
//     i = 0;
//     x = 0;
//     y = 0;
//     while (i < 360)
//     {
//         x = new_x + cos(i * MATH_PI / 180) * 200;
//         y = new_y + sin(i * MATH_PI / 180) * 200;
//         if (!check_wall(cube, x, y) || !check_wall(cube, new_x, new_y))
//             break;
//         i++;
//     }
//     if (i != 360)
//         return (0);
//     return (1);
// }

// void update_player_place(t_cube *cube)
// {
//     int move_step;
//     float new_x = 0;
//     float new_y = 0;
//     move_step = 0;
//     cube->player->rotation_angle += cube->player->palyer_rotation_speed * cube->player->l_r_directions;
//     cube->player->rotation_angle = ft_periodic(cube->player->rotation_angle);
//     move_step = cube->player->b_f_directions * cube->player->player_move_speed;
//     new_x = cube->player->x_position + cos(cube->player->rotation_angle) * move_step;
//     new_y = cube->player->y_position + sin(cube->player->rotation_angle) * move_step;
//     if (arround_player(cube, new_x, new_y))
//     {
//         cube->player->x_position = new_x;
//         cube->player->y_position = new_y;
//     }
//     ft_release(cube);
// }

// void update_player_place_left(t_cube *cube)
// {

//     float new_x = 0;
//     float new_y = 0;

//     new_x = cube->player->x_position + cos(cube->player->rotation_angle - MATH_PI / 2) * cube->player->player_move_speed;
//     new_y = cube->player->y_position + sin(cube->player->rotation_angle - MATH_PI / 2) * cube->player->player_move_speed;
//     if (arround_player(cube, new_x, new_y)) //&&check_wall(cube, new_x, new_y)
//     {
//         cube->player->x_position = new_x;
//         cube->player->y_position = new_y;
//     }
//     ft_release(cube);
// }
// void update_player_place_rigth(t_cube *cube)
// {

//     float new_x = 0;
//     float new_y = 0;

//     new_x = cube->player->x_position + cos(cube->player->rotation_angle + MATH_PI / 2) * cube->player->player_move_speed;
//     new_y = cube->player->y_position + sin(cube->player->rotation_angle + MATH_PI / 2) * cube->player->player_move_speed;
//     if (arround_player(cube, new_x, new_y))
//     {
//         cube->player->x_position = new_x;
//         cube->player->y_position = new_y;
//     }
//     ft_release(cube);
// }

// void draw_line(t_cube *cube)
// {
//     int i;
//     float x, y;

//     i = 0;
//     while (i < 30)
//     {
//         x = cube->player->x_position + cos(cube->player->rotation_angle) * i;
//         y = cube->player->y_position + sin(cube->player->rotation_angle) * i;
//         mlx_put_pixel(cube->image, x * 0.2, y * 0.2, ft_pixel(135, 206, 235, 1));
//         i++;
//     }
// }

// void key_released(void *param)
// {

//     t_cube *cube;

//     cube = (t_cube *)param;
//     if (mlx_is_key_down(cube->mlx_win, MLX_KEY_UP))
//     {
//         cube->player->b_f_directions = 0;
//     }
//     if (mlx_is_key_down(cube->mlx_win, MLX_KEY_DOWN))
//     {
//         cube->player->b_f_directions = 0;
//     }
//     if (mlx_is_key_down(cube->mlx_win, MLX_KEY_LEFT))
//     {
//         cube->player->l_r_directions = 0;
//     }
//     if (mlx_is_key_down(cube->mlx_win, MLX_KEY_RIGHT))
//     {
//         cube->player->l_r_directions = 0;
//     }
// }

// void key_press(void *param)
// {
//     t_cube *cube;

//     cube = (t_cube *)param;
//     if (mlx_is_key_down(cube->mlx_win, MLX_KEY_ESCAPE))
//     {
//         mlx_close_window(cube->mlx_win);
//     }
//     if (mlx_is_key_down(cube->mlx_win, MLX_KEY_UP) || mlx_is_key_down(cube->mlx_win, MLX_KEY_W))
//     {
//         cube->player->b_f_directions = 1;
//         update_player_place(cube);
//     }
//     if (mlx_is_key_down(cube->mlx_win, MLX_KEY_DOWN))
//     {
//         cube->player->b_f_directions = -1;
//         update_player_place(cube);
//     }
//     if (mlx_is_key_down(cube->mlx_win, MLX_KEY_LEFT))
//     {
//         cube->player->l_r_directions = -1;
//         update_player_place(cube);
//     }
//     if (mlx_is_key_down(cube->mlx_win, MLX_KEY_RIGHT))
//     {
//         cube->player->l_r_directions = 1;
//         update_player_place(cube);
//     }
//     if (mlx_is_key_down(cube->mlx_win, MLX_KEY_A))
//     {

//         update_player_place_left(cube);
//     }
//     if (mlx_is_key_down(cube->mlx_win, MLX_KEY_D))
//     {
//         update_player_place_rigth(cube);
//     }
//     clear_image(cube->image);
//     // display_map(cube);
//     clear_img_mini(cube->mini_map);
//     mini_map(cube);
//     draw_circle(cube->mini_map, 100, 100, cube->player->radius, ft_pixel(95, 209, 23, 255));
//     // draw_circle(cube->mini_map, cube->player->x_position *0.2, cube->player->y_position * 0.2, cube->player->radius * 0.2, ft_pixel(255,255,255,255 ));
//     // draw_line(cube);
//     cast_rays(cube);
//     return;
// }

// int main(int argc, char **argv)
// {
// 	t_cube		cube;
// 	t_player	player;
// 	t_map_data	data;

// 	initialize_data(&data);
// 	ft_parsing(argc, argv, &data);
// 	initialize_cube(&cube, &data, &player);
// 	if (mlx_initialize(&cube))
// 		return (textures_delete (&cube), free(data.cub_map), (EXIT_FAILURE));
// 	initialize_image(&cube);
//     if (!(cube.mini_map = mlx_new_image(cube.mlx_win, 200, 200)))
//     {
//         mlx_close_window(cube.mlx_win);
//         puts(mlx_strerror(mlx_errno));
//         return (EXIT_FAILURE);
//     }
//     if (mlx_image_to_window(cube.mlx_win, cube.mini_map, 0, 0) == -1)
//     {
//         mlx_close_window(cube.mlx_win);
//         puts(mlx_strerror(mlx_errno));
//         return (EXIT_FAILURE);
//     }


//     cube.t_door = mlx_load_png("d.png");
//     cube.i_door = mlx_texture_to_image(cube.mlx_win, cube.t_door);
//     cube.isfacingdoor = false;
//     cube.door_x = -1;
//     cube.door_y = -1;
//     mlx_set_cursor_mode(cube.mlx_win, MLX_MOUSE_HIDDEN);
//     mlx_get_mouse_pos(cube.mlx_win, &cube.mouse_x, &cube.mouse_y);
//     mlx_loop_hook(cube.mlx_win, key_press, &cube);
//     mlx_loop_hook(cube.mlx_win, animation, &cube);
//     mlx_loop_hook(cube.mlx_win, key_released, &cube);
//     mlx_loop(cube.mlx_win);
//     mlx_terminate(cube.mlx_win);

//     return (EXIT_SUCCESS);
// }

int	main(int argc, char **argv)
{
	t_cube		cube;
	t_player	player;
	t_map_data	data;

	initialize_data(&data);
	ft_parsing(argc, argv, &data);
	initialize_cube(&cube, &data, &player);
	if (mlx_initialize(&cube))
		return (textures_delete (&cube), (EXIT_FAILURE));
	initialize_image(&cube);
	mlx_set_cursor_mode(cube.mlx_win, MLX_MOUSE_HIDDEN);
	mlx_get_mouse_pos(cube.mlx_win, &cube.mouse_x, &cube.mouse_y);
	mlx_loop_hook(cube.mlx_win, key_press, &cube);
	mlx_loop_hook(cube.mlx_win, animation, &cube);
	mlx_loop(cube.mlx_win);
	mlx_terminate(cube.mlx_win);
	image_delete(&cube);
}
