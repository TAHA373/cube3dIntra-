/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 21:14:07 by tkannane          #+#    #+#             */
/*   Updated: 2024/08/14 22:35:02 by soel-bou         ###   ########.fr       */
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
    int len = 0;
    int i,j;
    int x,y;
    i = 0;
    j = 0;
    x = 0;
    y = 0;
    len = ft_strlen (cube->map[i]);
    while (i < cube->map_height)
    {
        j = 0;
        
        len = ft_strlen (cube->map[i]);
        while (j < cube->map_width && j < len)
        {
            if (cube->map[i][j] == '1')
                color = ft_pixel(255, 255, 255, 255);
            else
                color = ft_pixel(0, 0, 0, 50);
            while (y < PIXEL_SIZE)
            {
                x = 0;
                while (x < PIXEL_SIZE)
                {
                    if (i >=0 && j >= 0 && (( j * PIXEL_SIZE + x) * 0.2) < 300 && ((i * PIXEL_SIZE + y ) * 0.2) < 200)
                        mlx_put_pixel(cube->mini_map,( j * PIXEL_SIZE + x) * 0.2 , (i * PIXEL_SIZE + y ) * 0.2, color);
                    // if (x == PIXEL_SIZE - 1 || y == PIXEL_SIZE - 1)
                    //      mlx_put_pixel(cube->image, j * PIXEL_SIZE + x, i * PIXEL_SIZE + y, ft_pixel(0, 0, 0, 255));
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
float	ft_scale_f(float prev)
{
	float	new;

	new = (prev * 20) / PIXEL_SIZE;
	return (new);
}

void    mini_map(t_cube *cube)
{
    float new_x_map;
    float new_y_map;
    int i , j;
     i =0;
     j = 0;
    int x;
    int y;
    new_y_map = 0;
    new_x_map = 0;
    x = 0;
    y = ft_scale_f(cube->player->y_position)  - 100 ;//100= mini_map_heigth / 2;
    while (new_y_map < 200)
    {
        new_x_map = 0;
        x = ft_scale_f(cube->player->x_position) - 100;
        while (new_x_map < 200)
        {
            //printf("[%d] [%d]", i, j);
            if (x >= 0 && y >= 0 && x < cube->map_width * 20 && y < cube->map_height * 20)
            {
                i = y / 20;
                j = x / 20;
               // printf("[%c]\n", cube->map[11][28]);
                // if (j <  cube->map_width && i < cube->map_height)
              //  printf("[i = %d j = %d]\n", i, j);
            if (j < (int)ft_strlen (cube->map[i]))
            {
                if (cube->map[i][j] == '0' ||cube-> map[i][j] == ' ' ||cube-> map[i][j] == 'W' ||cube-> map[i][j] == 'E' ||cube-> map[i][j] == 'N' ||cube-> map[i][j] == 'S' )
                mlx_put_pixel(cube->mini_map, new_x_map, new_y_map, ft_pixel(0, 0, 0, 255));
            else if (cube->map[i][j] == '1' )
                mlx_put_pixel(cube->mini_map, new_x_map, new_y_map, ft_pixel(255, 255, 255, 255));
            }
            else {
                mlx_put_pixel(cube->mini_map, new_x_map, new_y_map,ft_pixel(95, 209, 23, 255));
            }
            }
            
            new_x_map++;
            x++;
        }
        new_y_map++;
        y++;
    }
}


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
    void clear_img_mini(mlx_image_t* image)
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
void ft_release(t_cube *cube)
{
    cube->player->b_f_directions = 0;
	cube->player->l_r_directions = 0;
    cube->player->key_a = 0;
}
int check_wall(t_cube *cube, float new_x, float new_y)
{
    int x,y;
    int len;
    x = floor(new_x / PIXEL_SIZE);
    y = floor( new_y / PIXEL_SIZE);

    if (x >= cube->map_width || y >= cube->map_height || x < 0 || y < 0)
        return (0);
    len = ft_strlen(cube->map[y]);
    if (x >= len)
        return (0);  
    if (cube->map[y][x] == '1'  || cube->map[y][x] == ' ')
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
        x = new_x +  cos(i * MATH_PI / 180) * 200;
        y = new_y +  sin(i * MATH_PI / 180) * 200;
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
    if (arround_player(cube, new_x, new_y))
    {
        cube->player->x_position = new_x;
        cube->player->y_position = new_y;
    }
   ft_release(cube);
}
void update_player_place_left(t_cube *cube)
{

    float new_x = 0;
    float new_y = 0;

	new_x = cube->player->x_position +  cos(cube->player->rotation_angle - MATH_PI/2) * cube->player->player_move_speed;
	new_y = cube->player->y_position +  sin(cube->player->rotation_angle - MATH_PI/2) * cube->player->player_move_speed;
    if (arround_player(cube, new_x, new_y)) //&&check_wall(cube, new_x, new_y)
    {
        cube->player->x_position = new_x;
        cube->player->y_position = new_y;
    }
   ft_release(cube);
}
void update_player_place_rigth(t_cube *cube)
{

    float new_x = 0;
    float new_y = 0;

	new_x = cube->player->x_position +  cos(cube->player->rotation_angle + MATH_PI/2) * cube->player->player_move_speed;
	new_y = cube->player->y_position +  sin(cube->player->rotation_angle + MATH_PI/2) * cube->player->player_move_speed;
    if (arround_player(cube, new_x, new_y))
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
        if (mlx_is_key_down(cube->mlx_win, MLX_KEY_UP) || mlx_is_key_down(cube->mlx_win, MLX_KEY_W))
        {
			    cube->player->b_f_directions = 1;
			    update_player_place(cube);
        }
        if (mlx_is_key_down(cube->mlx_win, MLX_KEY_DOWN))
        {
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
        if (mlx_is_key_down(cube->mlx_win, MLX_KEY_A))
        {

                update_player_place_left(cube);
        }
        if (mlx_is_key_down(cube->mlx_win, MLX_KEY_D))
        {
            update_player_place_rigth(cube);
        }
        clear_image(cube->image);
       // display_map(cube);
        clear_img_mini(cube->mini_map);
        mini_map(cube);
        draw_circle(cube->mini_map, 100, 100, cube->player->radius, ft_pixel(95, 209, 23, 255) );
        //draw_circle(cube->mini_map, cube->player->x_position *0.2, cube->player->y_position * 0.2, cube->player->radius * 0.2, ft_pixel(255,255,255,255 ));
        //draw_line(cube);
        cast_rays(cube);
        return ;
        
}

int main(int argc, char **argv)
{
    t_cube cube;
    t_player player;
    // PARSING
    t_map_data data;
    data.no_path = NULL;
    data.so_path = NULL;
    data.ea_path = NULL;
    data.we_path = NULL;
    data.c_color = NULL;
    data.f_color = NULL;
    data.map = NULL;
    data.cub_map = NULL;
    cube.data = &data;
    ft_parsing(argc, argv, cube.data);
    // printf("[%c]\n", data.direction);
    if (data.direction == 'S')
        player.rotation_angle = MATH_PI / 2;
    else if (data.direction == 'N')
        player.rotation_angle = 3 * MATH_PI / 2;
    else if (data.direction == 'W')
        player.rotation_angle = MATH_PI;
    else
        player.rotation_angle = 2 * MATH_PI;

    player.x_position = data.x * PIXEL_SIZE + PIXEL_SIZE / 2;
    player.y_position = data.y * PIXEL_SIZE + PIXEL_SIZE / 2;
    player.radius = 5;
    player.l_r_directions = 0;
    player.b_f_directions = 0;
    // player.rotation_angle = MATH_PI / 2;
    player.player_move_speed = 180;
    player.palyer_rotation_speed = 2 * (MATH_PI / 180);

    cube.player = &player;
    int i = 0;

    cube.map = data.cub_map;
    int width = 0;
    width = ft_strlen(cube.map[0]);
    while (cube.map[i])
    {
        // printf("{%c}", cube.map[0][22]);
        if (width < (int)ft_strlen(cube.map[i]))
            width = ft_strlen(cube.map[i]);
        i++;
    }
    cube.map_height = i;
    cube.map_width = width;
    if (!(cube.mlx_win = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Cube3D", false)))
    {
        puts(mlx_strerror(mlx_errno));
        return (EXIT_FAILURE);
    }

    if (!(cube.image = mlx_new_image(cube.mlx_win, WIN_WIDTH, WIN_HEIGHT)))
    {
        mlx_close_window(cube.mlx_win);
        puts(mlx_strerror(mlx_errno));
        return (EXIT_FAILURE);
    }
    if (mlx_image_to_window(cube.mlx_win, cube.image, 0, 0) == -1)
    {
        mlx_close_window(cube.mlx_win);
        puts(mlx_strerror(mlx_errno));
        return (EXIT_FAILURE);
    }
    if (!(cube.mini_map = mlx_new_image(cube.mlx_win, 200, 200)))
    {
        mlx_close_window(cube.mlx_win);
        puts(mlx_strerror(mlx_errno));
        return (EXIT_FAILURE);
    }
    if (mlx_image_to_window(cube.mlx_win, cube.mini_map, 0, 0) == -1)
    {
        mlx_close_window(cube.mlx_win);
        puts(mlx_strerror(mlx_errno));
        return (EXIT_FAILURE);
    }
    cube.south = mlx_texture_to_image(cube.mlx_win, data.south);
    cube.east = mlx_texture_to_image(cube.mlx_win, data.east);
    cube.west = mlx_texture_to_image(cube.mlx_win, data.west);
    cube.north = mlx_texture_to_image(cube.mlx_win, data.north);
    if (!cube.south || !cube.east || !cube.north || !cube.west)
        exit(1);
    // cube.texture[0] = mlx_load_png("./execution/5.png");
    // if (!cube.texture[0])
    // {
    //     printf("hiit\n");
    //     exit(1);
    // }
    // cube.east = mlx_texture_to_image(cube.mlx_win, cube.texture[0]);
    // cube.texture[1] = mlx_load_png("./execution/5.png");
    // if (!cube.texture[1])
    // {
    //     printf("shiit\n");
    //     exit(1);
    // }
    // cube.west = mlx_texture_to_image(cube.mlx_win, cube.texture[1]);

    // cube.texture[2] = mlx_load_png("./execution/5.png");
    // if (!cube.texture[2])
    // {
    //     printf("shiit\n");
    //     exit(1);
    // }
    // cube.south = mlx_texture_to_image(cube.mlx_win, cube.texture[2]);
    // cube.texture[3] = mlx_load_png("./execution/5.png");
    // if (!cube.texture[3])
    // {
    //     printf("shiit\n");
    //     exit(1);
    // }
    // cube.north = mlx_texture_to_image(cube.mlx_win, cube.texture[3]);

    // cube.isfacingdoor = false;
    // cube.door_x = -1;
    // cube.door_y = -1;
    mlx_set_cursor_mode(cube.mlx_win, MLX_MOUSE_HIDDEN);
    mlx_get_mouse_pos(cube.mlx_win, &cube.mouse_x, &cube.mouse_y);
    mlx_loop_hook(cube.mlx_win, key_press, &cube);
    mlx_loop(cube.mlx_win);
    mlx_terminate(cube.mlx_win);

    return (EXIT_SUCCESS);
}