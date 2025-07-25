/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhali < nbouhali@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 02:33:32 by nbouhali          #+#    #+#             */
/*   Updated: 2024/02/01 02:50:16 by nbouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"


int check_map_wall(t_cube *cube, double x, double y)
{
    // Ensure coordinates are within map bounds to prevent crashes
    int map_x = (int)(x / MB);
    int map_y = (int)(y / MB);

    if (map_x < 0 || map_x >= cube->misc.max || map_y < 0 || map_y >= cube->misc.lines)
        return 1; // Treat out-of-bounds as a wall

    return cube->map[map_y][map_x] == '1';
}

void	turn_left(t_cube *cube)
{
	// cube->v3.angle -= ROTSPEED;
	// if (cube->v3.angle < 0)
	// {
	// 	cube->v3.angle += 2 * M_PI;
	// }

	    cube->v3.angle -= ROTSPEED;
    if (cube->v3.angle < 0)
    {
        cube->v3.angle += 2 * M_PI; // Use M_PI or P1 consistently
    }


	// cube->v3.deltax = cos(cube->v3.angle) * SPEED;
	// cube->v3.deltay = sin(cube->v3.angle) * SPEED;
}

void	move_backward(t_cube *cube)
{
	//     double current_deltax = cos(cube->v3.angle) * SPEED;
    // double current_deltay = sin(cube->v3.angle) * SPEED;

    // // Same logic as forward, but negate deltas
    // double next_p_x = cube->p.x - current_deltax;
    // double next_p_y = cube->p.y - current_deltay;

    // int target_map_x = (int)(next_p_x) / MB;
    // int target_map_y = (int)(next_p_y) / MB;

    // // Separate X and Y movement for sliding
    // int test_x_map_x = (int)(cube->p.x - current_deltax) / MB;
    // int test_x_map_y = (int)(cube->p.y) / MB;
    // if (cube->map[test_x_map_y][test_x_map_x] != '1') {
    //     cube->p.x -= current_deltax;
    // }

    // int test_y_map_x = (int)(cube->p.x) / MB;
    // int test_y_map_y = (int)(cube->p.y - current_deltay) / MB;
    // if (cube->map[test_y_map_y][test_y_map_x] != '1') {
    //     cube->p.y -= current_deltay;
    // }

    double move_dx = cos(cube->v3.angle) * SPEED;
    double move_dy = sin(cube->v3.angle) * SPEED;

    // Separate X-axis movement and collision check (negative dx)
    double next_p_x_test = cube->p.x - move_dx;
    if (!check_map_wall(cube, next_p_x_test, cube->p.y))
    {
        cube->p.x = next_p_x_test;
    }

    // Separate Y-axis movement and collision check (negative dy)
    double next_p_y_test = cube->p.y - move_dy;
    if (!check_map_wall(cube, cube->p.x, next_p_y_test))
    {
        cube->p.y = next_p_y_test;
    }

	// if (cube->map[cube->bound.backy][(int)cube->p.x / MB] != '1'
	// 	&& cube->map[(int)cube->p.y / MB][cube->bound.backx] != '1')
	// {
	// 	if (cube->map[cube->bound.backy][cube->bound.backx] != '1')
	// 	{
	// 		cube->p.y -= round(cube->v3.deltay);
	// 		cube->p.x -= round(cube->v3.deltax);
	// 	}
	// }
}

void	strife_right(t_cube *cube)
{

	    double strafe_dx = -sin(cube->v3.angle) * SPEED;
    double strafe_dy = cos(cube->v3.angle) * SPEED;

    // Separate X-axis movement and collision check
    double next_p_x_test = cube->p.x + strafe_dx;
    if (!check_map_wall(cube, next_p_x_test, cube->p.y))
    {
        cube->p.x = next_p_x_test;
    }

    // Separate Y-axis movement and collision check
    double next_p_y_test = cube->p.y + strafe_dy;
    if (!check_map_wall(cube, cube->p.x, next_p_y_test))
    {
        cube->p.y = next_p_y_test;
    }

	// if (cube->map[cube->bound.lefty][(int)cube->p.x / MB] != '1'
	// 	&& cube->map[(int)cube->p.y / MB][cube->bound.leftx] != '1')
	// {
	// 	if (cube->map[cube->bound.lefty][cube->bound.leftx] != '1')
	// 	{
	// 		cube->p.x += round(cube->v3.deltay);
	// 		cube->p.y -= round(cube->v3.deltax);
	// 	}
	// }
}

void	strife_left(t_cube *cube)
{
	// if (cube->map[cube->bound.righty][(int)cube->p.x / MB] != '1'
	// 	&& cube->map[(int)cube->p.y / MB][cube->bound.rightx] != '1')
	// {
	// 	if (cube->map[cube->bound.righty][cube->bound.rightx] != '1')
	// 	{
	// 		cube->p.x -= round(cube->v3.deltay);
	// 		cube->p.y += round(cube->v3.deltax);
	// 	}
	// }
	    double strafe_dx = sin(cube->v3.angle) * SPEED;
    double strafe_dy = -cos(cube->v3.angle) * SPEED;

    // Separate X-axis movement and collision check
    double next_p_x_test = cube->p.x + strafe_dx;
    if (!check_map_wall(cube, next_p_x_test, cube->p.y))
    {
        cube->p.x = next_p_x_test;
    }

    // Separate Y-axis movement and collision check
    double next_p_y_test = cube->p.y + strafe_dy;
    if (!check_map_wall(cube, cube->p.x, next_p_y_test))
    {
        cube->p.y = next_p_y_test;
    }
}

void	turn_right(t_cube *cube)
{
	// cube->v3.angle += ROTSPEED;
	// if (cube->v3.angle >= 2 * M_PI)
	// {
	// 	cube->v3.angle -= 2 * M_PI;
	// }

	    cube->v3.angle += ROTSPEED;
    if (cube->v3.angle >= 2 * M_PI)
    {
        cube->v3.angle -= 2 * M_PI; // Use M_PI or P1 consistently
    }


	// cube->v3.deltax = cos(cube->v3.angle) * SPEED;
	// cube->v3.deltay = sin(cube->v3.angle) * SPEED;
}
