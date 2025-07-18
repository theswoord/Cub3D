/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhali < nbouhali@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:28:06 by nbouhali          #+#    #+#             */
/*   Updated: 2024/02/01 03:11:51 by nbouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void sig(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		exit(1);
	}
}

void parse_functions(t_cube *cube)
{
	cube->wanted = "01EWSN ";
	read_map(cube->fd, cube);
	check_ft(cube);
	parse(cube);
	parse_textures(cube);
	// if (!cube->drawings->no || !cube->drawings->ea || !cube->drawings->we || !cube->drawings->so)
	// 	problem("Error\ncheck the PNG or read ^above^ \n");
	texture_set(cube);
	// init_mlx(cube);
	fill_map(cube);
	map_check(cube);
	if (!check_player(cube) || !check_walls(cube))
		exit(1);
	// draw_background(cube->window->img, cube);
	mini_map_draw(cube);
}
void execute_loop(t_cube *cube)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		// std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		printf("init\n");
		exit(1);
	}

	// cube->win = SDL_CreateWindow("miw", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	// if (cube->win == NULL)
	// {
	//     // std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
	//     printf("win\n");
	// 	SDL_Quit();
	//     exit(1);
	// }
	// int x = 0;
	// int y = 0;
	cube->screenSurface = SDL_GetWindowSurface(cube->win);
	cube->renderer = SDL_CreateRenderer(cube->win, 0, 0);
	SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &cube->win, &cube->renderer);

	struct_init(cube);
	parse_functions(cube);
	cube->v3.deltax = cos(cube->v3.angle) * SPEED;
	cube->v3.deltay = sin(cube->v3.angle) * SPEED;
	printf("delta x:%f y:%f \n",cube->v3.deltax,cube->v3.deltay);
	printf("wselt hnaya \n");
	while (!cube->quit)
	{
		cube->frameStart = SDL_GetTicks();
		// SDL_UpdateWindowSurface(cube->win);
		cube->frameTime = SDL_GetTicks() - cube->frameStart;
		SDL_SetRenderDrawColor(cube->renderer, 0, 0, 0, 0);
		SDL_RenderClear(cube->renderer);
		// SDL_SetRenderDrawColor(cube->renderer,255,255,0,255);
		// SDL_RenderDrawPoint(cube->renderer,200,200);
		// SDL_RenderDrawPoint(cube->renderer,220,200);
		// SDL_RenderDrawPoint(cube->renderer,210,200);
		// SDL_RenderDrawPoint(cube->renderer,230,200);
		// SDL_RenderDrawPoint(cube->renderer,240,200);
		// SDL_RenderDrawPoint(cube->renderer,250,200);
		// SDL_SetRenderDrawColor(cube->renderer,0,0,0,0);
		boundaries(cube);

		while (SDL_PollEvent(&cube->e))
		{
			// printf("Scancode: 0x%02X", cube->e->key->keysym.scancode);
			// printf("Scancode: 0x%02X\n",cube->e.key.keysym.scancode);
			// printf("code %d\n",cube->e.key.type);


			if (cube->e.type == SDL_QUIT)
			{
				cube->quit = true;
			}
			if (cube->e.key.keysym.scancode == SDL_SCANCODE_LEFT)
			{
				// printf("angle %f\n",cube->v3.angle);

				turn_left(cube);
			}
			if (cube->e.key.keysym.scancode == SDL_SCANCODE_RIGHT)
			{
				turn_right(cube);
			}
			if (cube->e.key.keysym.scancode == SDL_SCANCODE_W)
			{
				// printf("%d \n",cube->xp);
				move_forward(cube);
			}
			if (cube->e.key.keysym.scancode == SDL_SCANCODE_S)
			{
				move_backward(cube);
			}
			if (cube->e.key.keysym.scancode == SDL_SCANCODE_D)
			{
				strife_right(cube);
			}
			if (cube->e.key.keysym.scancode == SDL_SCANCODE_A)
			{
				strife_left(cube);
			}
		}

		cast_v3(cube);

		SDL_RenderPresent(cube->renderer);

		if (cube->frameDelay > cube->frameTime)
		{
			SDL_Delay(cube->frameDelay - cube->frameTime);
		}
	}
	// mlx_loop_hook(cube->window->mlx, &pressed, cube);
	// mlx_loop(cube->window->mlx);
	// mlx_terminate(cube->window->mlx);
}

int main(int ac, char **av)
{
	// int		fd;
	struct sigaction minisignols;
	minisignols.sa_handler = sig;
	sigaction(SIGINT, &minisignols, NULL);
	t_cube *cube;

	if (ac != 2)
	{
		print_error("Error\nmore or less than 2 ac\n");
		return (0);
	}
	check_cub(av[1]);
	cube = (t_cube *)malloc(sizeof(t_cube));
	memset(cube, 0, sizeof(t_cube));
	cube->fd = open(av[1], O_RDONLY);
	if (cube->fd == -1)
	{
		return (1);
	}

	execute_loop(cube);
	return (0);
}

void set_background(t_cube *cube)
{
	cube->colors->finalfloor = (cube->colors->f[0] << 24) | (cube->colors->f[1] << 16) | (cube->colors->f[2] << 8) | 0xFF;
	cube->colors->finalceil = (cube->colors->c[0] << 24) | (cube->colors->c[1] << 16) | (cube->colors->c[2] << 8) | 0xFF;
}
