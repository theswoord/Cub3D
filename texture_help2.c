/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_help2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhali < nbouhali@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 02:44:25 by nbouhali          #+#    #+#             */
/*   Updated: 2024/02/01 03:13:27 by nbouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void textured(t_cube *cube, unsigned long *row, int polarity, int height)
{
	int colm;
	int rowm;
	double steps;
	double y;

	steps = fabs(cube->dda.endy - cube->dda.starty);
	y = cube->dda.starty;
	while (steps > 0)
	{
		y += 1;
		if (polarity == 0)
			colm = (int)(cube->v3.hx + 0.0002) % MB;
		else if (polarity == 1)
			colm = (int)(cube->v3.vy + 0.0002) % MB;
		rowm = (int)((y - cube->dda.savestarty) / cube->v3.savewallheight * height);
		if (rowm < 32)
		{
			if (cube->dda.startx >= WIDTH || y >= HEIGHT)
				return;
			// mlx_put_pixel(cube->window->img, (cube->dda.startx), y, row[((height / MB) * colm + (height * rowm))]);
		}
		steps--;
	}
}

void textured_inverted(t_cube *cube, unsigned long *row, int polarity,
					   int height)
{
	int colm;
	int rowm;
	double steps;
	double y;

	steps = fabs(cube->dda.endy - cube->dda.starty);
	y = cube->dda.starty;
	while (steps > 0)
	{
		y += 1;
		if (polarity == 0)
			colm = (int)(cube->v3.hx + 0.0002) % MB;
		else if (polarity == 1)
			colm = (int)(cube->v3.vy + 0.0002) % MB;
		rowm = (int)((y - cube->dda.savestarty) / cube->v3.savewallheight * height);
		if (rowm < 32)
		{
			if (cube->dda.startx >= WIDTH || y >= HEIGHT)
				return;
			// mlx_put_pixel(cube->window->img, round(cube->dda.startx), y,
			// 			  row[((height / MB) * 31 - colm + (height * rowm))]);
		}
		steps--;
	}
}
void mydda(t_cube *cube, unsigned long *row, int polarity,
		   int height, char color)
{
	int colm;
	int rowm;
	double steps;
	double y;

	steps = fabs(cube->dda.endy - cube->dda.starty);
	y = cube->dda.starty;
	while (steps > 0)
	{
		y += 1;
		if (polarity == 0)
			colm = (int)(cube->v3.hx + 0.0002) % MB;
		else if (polarity == 1)
			colm = (int)(cube->v3.vy + 0.0002) % MB;
		rowm = (int)((y - cube->dda.savestarty) / cube->v3.savewallheight * height);
		if (rowm < 32)
		{
			if (cube->dda.startx >= WIDTH || y >= HEIGHT)
				return;
			if (color == 'R')
			{
				SDL_SetRenderDrawColor(cube->renderer, 255, 153, 153, 255);
				// mlx_put_pixel(cube->window->img, round(cube->dda.startx), y,
				// 			  row[((height / MB) * 31 - colm + (height * rowm))]);
				SDL_RenderDrawPoint(cube->renderer,round(cube->dda.startx),y);
				SDL_SetRenderDrawColor(cube->renderer, 0, 0, 0, 0);

				/* code */
			}
			else if (color == 'B')
			{
				SDL_SetRenderDrawColor(cube->renderer, 60, 64, 209, 255);
				// mlx_put_pixel(cube->window->img, round(cube->dda.startx), y,
				// 			  row[((height / MB) * 31 - colm + (height * rowm))]);
				SDL_RenderDrawPoint(cube->renderer,round(cube->dda.startx),y);
				SDL_SetRenderDrawColor(cube->renderer, 0, 0, 0, 0);
			
			}
			else if (color == 'G')
			{
				SDL_SetRenderDrawColor(cube->renderer, 97, 205, 105, 255);
				// mlx_put_pixel(cube->window->img, round(cube->dda.startx), y,
				// 			  row[((height / MB) * 31 - colm + (height * rowm))]);
				SDL_RenderDrawPoint(cube->renderer,round(cube->dda.startx),y);
				SDL_SetRenderDrawColor(cube->renderer, 0, 0, 0, 0);
			
			}
			else if (color == 'W')
			{
				SDL_SetRenderDrawColor(cube->renderer, 255, 255, 255, 190);
				// mlx_put_pixel(cube->window->img, round(cube->dda.startx), y,
				// 			  row[((height / MB) * 31 - colm + (height * rowm))]);
				SDL_RenderDrawPoint(cube->renderer,round(cube->dda.startx),y);
				SDL_SetRenderDrawColor(cube->renderer, 0, 0, 0, 0);
			
			}
		}
		steps--;
	}
}

int height_extract(t_cube *cube, char *texture)
{
	if (!ft_strncmp(texture, "EA", 3))
		return (cube->colors->dim[0]);
	if (!ft_strncmp(texture, "NO", 3))
		return (cube->colors->dim[2]);
	if (!ft_strncmp(texture, "WE", 3))
		return (cube->colors->dim[4]);
	if (!ft_strncmp(texture, "SO", 3))
		return (cube->colors->dim[6]);
	return (0);
}

void textured_sdl(t_cube *cube, Uint8 *row, int polarity, int height)
{
    int colm;
    int rowm;
    double steps;
    double y;

    steps = fabs(cube->dda.endy - cube->dda.starty);
    y = cube->dda.starty; 
    while (steps >= 0)
    {
        if (polarity == 0)
            colm = (int)(cube->v3.hx + 0.0002) % MB;
        else if (polarity == 1)
            colm = (int)(cube->v3.vy + 0.0002) % MB; 

        rowm = (int)(((y - cube->dda.savestarty) / cube->v3.savewallheight) * height);


        colm = colm % MB;
        if (colm < 0) colm += MB; 

        rowm = rowm % height; 
        if (rowm < 0) rowm += height;

        if (round(cube->dda.startx) < 0 || round(cube->dda.startx) >= WIDTH ||
            round(y) < 0 || round(y) >= HEIGHT)
        {

            y += 1;
            steps--;
            continue; 
        }


        int pixel_byte_index = (rowm * MB * 4) + (colm * 4);


        if (pixel_byte_index + 3 < (MB * height * 4)) 
        {
            Uint8 r = row[pixel_byte_index];
            Uint8 g = row[pixel_byte_index + 1];
            Uint8 b = row[pixel_byte_index + 2];
            Uint8 a = row[pixel_byte_index + 3];

            SDL_SetRenderDrawColor(cube->renderer, r, g, b, a);
            SDL_RenderDrawPoint(cube->renderer, round(cube->dda.startx), round(y)); // Use round(y) as well
            SDL_SetRenderDrawColor(cube->renderer, 0, 0, 0, 0);
        
		}

        y += 1;
        steps--;
    }
	
}
void textured_inverted_sdl(t_cube *cube, Uint8 *row, int polarity, int height)
{
    int colm;
    int rowm;
    double steps;
    double y;

    steps = fabs(cube->dda.endy - cube->dda.starty);
    y = cube->dda.starty; 
    while (steps >= 0)
    {
        // Get the initial column value, same as textured_sdl
        if (polarity == 0) // Horizontal wall (South wall in your case)
            colm = (int)(cube->v3.hx + 0.0002) % MB;
        else if (polarity == 1) // Vertical wall (West wall in your case)
            colm = (int)(cube->v3.vy + 0.0002) % MB; 

        // Apply the inversion here
        colm = (MB - 1) - colm; // THIS IS THE KEY INVERSION

        rowm = (int)(((y - cube->dda.savestarty) / cube->v3.savewallheight) * height);

        // Ensure colm is within bounds after inversion (important if MB-1-colm yields negative for some reason)
        colm = colm % MB;
        if (colm < 0) colm += MB; 

        rowm = rowm % height; 
        if (rowm < 0) rowm += height;

        if (round(cube->dda.startx) < 0 || round(cube->dda.startx) >= WIDTH ||
            round(y) < 0 || round(y) >= HEIGHT)
        {
            y += 1;
            steps--;
            continue; 
        }

        int pixel_byte_index = (rowm * MB * 4) + (colm * 4);

        if (pixel_byte_index + 3 < (MB * height * 4)) 
        {
            Uint8 r = row[pixel_byte_index];
            Uint8 g = row[pixel_byte_index + 1];
            Uint8 b = row[pixel_byte_index + 2];
            Uint8 a = row[pixel_byte_index + 3];

            SDL_SetRenderDrawColor(cube->renderer, r, g, b, a);
            SDL_RenderDrawPoint(cube->renderer, round(cube->dda.startx), round(y));
            SDL_SetRenderDrawColor(cube->renderer, 0, 0, 0, 0); // This line sets color back to black, might not be necessary inside the loop if only drawing points
        }

        y += 1;
        steps--;
    }
}