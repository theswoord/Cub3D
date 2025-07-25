/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_related.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhali < nbouhali@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:28:18 by nbouhali          #+#    #+#             */
/*   Updated: 2024/02/01 02:41:10 by nbouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	boundaries(t_cube *cube)
{
	cube->bound.frontx = (cube->p.x + 3 * round(cube->v3.deltax)) / MB;
	cube->bound.fronty = (cube->p.y + 3 * round(cube->v3.deltay)) / MB;
	cube->bound.backx = (cube->p.x - 3 * round(cube->v3.deltax)) / MB;
	cube->bound.backy = (cube->p.y - 3 * round(cube->v3.deltay)) / MB;
	cube->bound.righty = (cube->p.y + 3 * round(cube->v3.deltax)) / MB;
	cube->bound.rightx = (cube->p.x - 3 * round(cube->v3.deltay)) / MB;
	cube->bound.lefty = (cube->p.y - 3 * round(cube->v3.deltax)) / MB;
	cube->bound.leftx = (cube->p.x + 3 * round(cube->v3.deltay)) / MB;
}

void	pressed(void *par)
{
	t_cube	*cube;

	cube = par;
	boundaries(cube);
	// if (mlx_is_key_down(cube->window->mlx, MLX_KEY_W))
	// 	move_forward(cube);
	// if (mlx_is_key_down(cube->window->mlx, MLX_KEY_LEFT))
	// 	turn_left(cube);
	// if (mlx_is_key_down(cube->window->mlx, MLX_KEY_S))
	// 	move_backward(cube);
	// if (mlx_is_key_down(cube->window->mlx, MLX_KEY_RIGHT))
	// 	turn_right(cube);
	// if (mlx_is_key_down(cube->window->mlx, MLX_KEY_ESCAPE))
	// {
	// 	free_all(cube);
	// 	printf("the game exited\n");
	// 	exit(0);
	// }
	// if (mlx_is_key_down(cube->window->mlx, MLX_KEY_D))
	// 	strife_right(cube);
	// if (mlx_is_key_down(cube->window->mlx, MLX_KEY_A))
	// 	strife_left(cube);
	cast_v3(cube);
}

void	move_forward(t_cube *cube)
{
	//     double current_deltax = cos(cube->v3.angle) * SPEED;
    // double current_deltay = sin(cube->v3.angle) * SPEED;
	// double next_p_x = cube->p.x + current_deltax;
    // double next_p_y = cube->p.y + current_deltay;
	// int target_map_x = (int)(next_p_x) / MB;
    // int target_map_y = (int)(next_p_y) / MB;
	// int test_x_map_x = (int)(cube->p.x + current_deltax) / MB;
    // int test_x_map_y = (int)(cube->p.y) / MB;
	//     if (cube->map[test_x_map_y][test_x_map_x] != '1') {
    //     cube->p.x += current_deltax;
    // }
	//  int test_y_map_x = (int)(cube->p.x) / MB; // Use updated X
    // int test_y_map_y = (int)(cube->p.y + current_deltay) / MB;
    // if (cube->map[test_y_map_y][test_y_map_x] != '1') {
    //     cube->p.y += current_deltay;
    // }

    double move_dx = cos(cube->v3.angle) * SPEED;
    double move_dy = sin(cube->v3.angle) * SPEED;

    // Separate X-axis movement and collision check
    double next_p_x_test = cube->p.x + move_dx;
    // Check if moving to this X position would hit a wall
    // You might want to check the corners of the player's bounding box instead of just the center point
    // For a simple player-is-a-point:
    if (!check_map_wall(cube, next_p_x_test, cube->p.y))
    {
        cube->p.x = next_p_x_test;
    }

    // Separate Y-axis movement and collision check
    double next_p_y_test = cube->p.y + move_dy;
    // Check if moving to this Y position (using potentially updated X) would hit a wall
    if (!check_map_wall(cube, cube->p.x, next_p_y_test))
    {
        cube->p.y = next_p_y_test;
    }



	// if (cube->map[cube->bound.fronty][(int)cube->p.x / MB] != '1'
	// 	&& cube->map[(int)cube->p.y / MB][cube->bound.frontx] != '1')
	// {
	// 	if (cube->map[cube->bound.fronty][cube->bound.frontx] != '1')
	// 	{
	// 		cube->p.y += round(cube->v3.deltay);
	// 		cube->p.x += round(cube->v3.deltax);
	// 	}
	// }
}
