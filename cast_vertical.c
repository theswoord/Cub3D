/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_vertical.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhali < nbouhali@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:50:43 by nbouhali          #+#    #+#             */
/*   Updated: 2024/02/01 03:13:51 by nbouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void vertical_part_one(t_cube *cube)
{
	double tanges;

	tanges = -tan(cube->v3.rayangle);
	if (cube->v3.rayangle > M_PI / 2 && cube->v3.rayangle < 3 * M_PI / 2)
	{
		cube->v3.rayx = ((int)cube->p.x / MB) * MB - 0.0001;
		cube->v3.rayy = ((int)cube->p.x - cube->v3.rayx) * tanges + (int)cube->p.y;
		cube->v3.xoffset = -MB;
		cube->v3.yoffset = -cube->v3.xoffset * tanges;
	}
	if (cube->v3.rayangle < M_PI / 2 || cube->v3.rayangle > 3 * M_PI / 2)
	{
		cube->v3.rayx = ((int)cube->p.x / MB * MB) + MB;
		cube->v3.rayy = ((int)cube->p.x - cube->v3.rayx) * tanges + (int)cube->p.y;
		cube->v3.xoffset = MB;
		cube->v3.yoffset = -cube->v3.xoffset * tanges;
	}
	if (cube->v3.rayangle == M_PI / 2)
		cube->v3.yoffset = MB;
	if (cube->v3.rayangle == 3 * M_PI / 2)
		cube->v3.yoffset = -MB;
}

void vertical_rays(t_cube *cube)
{
	cube->v3.vx = cube->v3.rayx;
	cube->v3.vy = cube->v3.rayy;
}

double vertical(t_cube *c)
{
	int mapy;
	int mapx;

	vertical_part_one(c);
	while (1)
	{
		mapy = (int)c->v3.rayy / MB;
		mapx = (int)c->v3.rayx / MB;
		if ((mapy >= c->misc.lines || mapx >= c->misc.max) || (mapy <= 0 || mapx <= 0) || c->map[mapy][mapx] == '1')
			break;
		else
		{
			if (c->v3.rayy < (c->misc.lines * MB) && c->v3.rayy > 0)
				c->v3.rayy += c->v3.yoffset;
			else
				return (9999988999);
			if (c->v3.rayx < (c->misc.max * MB) && c->v3.rayx > 0)
				c->v3.rayx += c->v3.xoffset;
			else
				return (9999988979);
		}
	}
	vertical_rays(c);
	return (sqrt(pow(c->v3.vx - c->p.x, 2) + pow(c->v3.vy - c->p.y, 2)));
}

void cast_v3_help(t_cube *cube)
{
	double dh;
	double dv;

	if (cube->v3.rayangle <= 0)
		cube->v3.rayangle += 2 * M_PI;
	if (cube->v3.rayangle >= 2 * M_PI)
		cube->v3.rayangle -= 2 * M_PI;
	dh = horizontal(cube);
	dv = vertical(cube);
	cube->v3.wallheight = (HEIGHT * MB) / cube->v3.distance;
	cube->v3.savewallheight = cube->v3.wallheight;
	if (cube->v3.wallheight > HEIGHT)
		cube->v3.wallheight = HEIGHT;
	if (dh < dv)
	{
		cube->v3.distance = dh;
		cube->v3.side = 0;
	}
	else
	{
		cube->v3.distance = dv;
		cube->v3.side = 1;
	}
}

void draw_textures(t_cube *cube)
{
	if (cube->v3.side == PH)
	{
		if (cube->v3.rayangle < M_PI){
			// textured_inverted(cube, cube->colors->so, cube->v3.side,
			// 				  height_extract(cube, "SO"));
			// mydda(cube,cube->colors->so, cube->v3.side,32,'R');

			textured_inverted_sdl(cube,cube->colors->sdlso,cube->v3.side,32);

			// SDL_SetRenderDrawColor(cube->renderer,255,0,0,255);
			// SDL_RenderDrawLine(cube->renderer,cube->dda.startx,cube->dda.starty,cube->dda.endx,cube->dda.endy);
			// SDL_SetRenderDrawColor(cube->renderer,0,0,0,0);

			// SDL_RenderDrawPoint(cube->renderer,x,y);

		}
		else
		{
			// mydda(cube,cube->colors->so, cube->v3.side,32,'G');

			textured_sdl(cube,cube->colors->sdlno,cube->v3.side,32);

			// SDL_SetRenderDrawColor(cube->renderer,0,255,0,255);
			// SDL_RenderDrawLine(cube->renderer,cube->dda.startx,cube->dda.starty,cube->dda.endx,cube->dda.endy);
			// SDL_SetRenderDrawColor(cube->renderer,0,0,0,0);

		}

			// textured(cube, cube->colors->no, cube->v3.side, height_extract(cube, "NO"));
	}
	else
	{
		if (cube->v3.rayangle > 3 * M_PI / 2 || cube->v3.rayangle < M_PI / 2)
			{
			// mydda(cube,cube->colors->so, cube->v3.side,32,'B');
			textured_sdl(cube,cube->colors->sdlea,cube->v3.side,32);

			// SDL_SetRenderDrawColor(cube->renderer,0,0,255,255);
			// SDL_RenderDrawLine(cube->renderer,cube->dda.startx,cube->dda.starty,cube->dda.endx,cube->dda.endy);
			// SDL_SetRenderDrawColor(cube->renderer,0,0,0,0);
			}
		// textured(cube, cube->colors->ea, cube->v3.side, height_extract(cube, "EA"));
		else
		{
			// mydda(cube,cube->colors->so, cube->v3.side,32,'W');
			textured_inverted_sdl(cube,cube->colors->sdlwe,cube->v3.side,32);

			// SDL_SetRenderDrawColor(cube->renderer,255,255,255,255);
			// SDL_RenderDrawLine(cube->renderer,cube->dda.startx,cube->dda.starty,cube->dda.endx,cube->dda.endy);
			// SDL_SetRenderDrawColor(cube->renderer,0,0,0,0);
		}
			// textured_inverted(cube, cube->colors->we, cube->v3.side,
			// 				  height_extract(cube, "WE"));
	}
}

// void textured_sdl(t_cube *cube, Uint8 *row, int polarity, int height)
// {
// 	int colm;
// 	int rowm;
// 	double steps;
// 	double y;

// 	steps = fabs(cube->dda.endy - cube->dda.starty);
// 	y = cube->dda.starty;
// 	while (steps > 0)
// 	{
// 		y += 1;
// 		if (polarity == 0)
// 			colm = (int)(cube->v3.hx + 0.0002) % MB;
// 		else if (polarity == 1)
// 			colm = (int)(cube->v3.vy + 0.0002) % MB;
// 		rowm = (int)((y - cube->dda.savestarty) / cube->v3.savewallheight * height);
// 		if (rowm <= 128)
// 		{
// 			if (cube->dda.startx >= WIDTH || y >= HEIGHT)
// 				return;
			

// 				SDL_SetRenderDrawColor(cube->renderer, row[((height / MB) * colm + (height * rowm))], row[((height / MB) * colm + (height * rowm))]+1,row[((height / MB) * colm + (height * rowm))]+2,row[((height / MB) * colm + (height * rowm))]+3);
// 				// mlx_put_pixel(cube->window->img, round(cube->dda.startx), y,
// 				// 			  row[((height / MB) * 31 - colm + (height * rowm))]);
// 				SDL_RenderDrawPoint(cube->renderer,round(cube->dda.startx),y);
// 				SDL_SetRenderDrawColor(cube->renderer, 0, 0, 0, 0);	
// 			// printf("%d %d %d %d  \n", row[((height / MB) * colm + (height * rowm))] , (row[((height / MB) * colm + (height * rowm))])+1 ,(row[((height / MB) * colm + (height * rowm))])+2,(row[((height / MB) * colm + (height * rowm))])+3);
// 			printf("%d %d \n", ((height / MB) * colm + (height * rowm)) ,((height / MB) * colm + (height * rowm))+1 );

// 			// mlx_put_pixel(cube->window->img, (cube->dda.startx), y, row[((height / MB) * colm + (height * rowm))]);
// 		}
// 		steps--;
// 	}
// }