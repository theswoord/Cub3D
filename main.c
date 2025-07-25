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

static t_cube *g_cube = NULL;
static int g_ui_has_focus = 0;



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
void execute_loop(void *ptr)
{

	t_cube *cube;
	cube = (t_cube*) ptr;
	// cube->v3.deltax = cos(cube->v3.angle) * SPEED;
	// cube->v3.deltay = sin(cube->v3.angle) * SPEED;
		cube->frameStart = SDL_GetTicks();
		cube->frameTime = SDL_GetTicks() - cube->frameStart;
		SDL_SetRenderDrawColor(cube->renderer, 0, 0, 0, 0);
		SDL_RenderClear(cube->renderer);
		// boundaries(cube);

		    if (!g_ui_has_focus) // <-- ADD THIS CHECK
    {
		while (SDL_PollEvent(&cube->e))
		{


			if (cube->e.type == SDL_QUIT)
			{
				cube->quit = true;
			}

			// if (g_ui_has_focus)
    		// {
    		//     continue;
    		// }

			if (cube->e.key.keysym.scancode == SDL_SCANCODE_LEFT)
			{

				turn_left(cube);
			}
			if (cube->e.key.keysym.scancode == SDL_SCANCODE_RIGHT)
			{
				turn_right(cube);
			}
			if (cube->e.key.keysym.scancode == SDL_SCANCODE_W)
			{
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
	}

		cast_v3(cube);

		SDL_RenderPresent(cube->renderer);

		if (cube->frameDelay > cube->frameTime)
		{
			SDL_Delay(cube->frameDelay - cube->frameTime);
		}
}

// extern "C" {
//   EMSCRIPTEN_KEEPALIVE
//   void cleanup() {
//     //   printf("C++ cleanup function called directly!\n");

//     SDL_DestroyWindow(wasm->window);
//     SDL_Quit();
//     emscripten_cancel_main_loop();
//     delete wasm;
//       fflush(stdout); // Force output to flush to the console

//     //   SDL_DestroyRenderer(renderer);

//   }
// }


int main(int ac, char **av)
{
	// int		fd;
	// struct sigaction minisignols;
	// minisignols.sa_handler = sig;
	// sigaction(SIGINT, &minisignols, NULL);
	t_cube *cube;

	// if (ac != 2)
	// {
	// 	print_error("Error\nmore or less than 2 ac\n");
	// 	return (0);
	// }
	// check_cub(av[1]);
	cube = (t_cube *)malloc(sizeof(t_cube));
	memset(cube, 0, sizeof(t_cube));

	g_cube = cube;


	cube->fd = open("assets/block.cub", O_RDONLY);
	    SDL_SetHint(SDL_HINT_EMSCRIPTEN_KEYBOARD_ELEMENT, "#canvas");
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		// std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		printf("init\n");
		exit(1);
	}
	cube->screenSurface = SDL_GetWindowSurface(cube->win);
	cube->renderer = SDL_CreateRenderer(cube->win, 0, 0);
	SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &cube->win, &cube->renderer);


	struct_init(cube);

	parse_functions(cube);

	if (cube->fd == -1)
	{
		print_error("Error\n not opened\n");
		return (1);
	}

	// execute_loop(cube);
	emscripten_set_main_loop_arg(execute_loop, cube, cube->targetFPS, 1);
	return (0);
}

void set_background(t_cube *cube)
{
	cube->colors->finalfloor = (cube->colors->f[0] << 24) | (cube->colors->f[1] << 16) | (cube->colors->f[2] << 8) | 0xFF;
	cube->colors->finalceil = (cube->colors->c[0] << 24) | (cube->colors->c[1] << 16) | (cube->colors->c[2] << 8) | 0xFF;
}


  EMSCRIPTEN_KEEPALIVE
  void set_ui_focus(int has_focus) {
    g_ui_has_focus = has_focus;
};
  EMSCRIPTEN_KEEPALIVE
  void cleanup() {

	printf("khdemt cleanup\n");
    // SDL_DestroyWindow(g_cube->win);
	// SDL_DestroyRenderer(g_cube->renderer);
	free_all(g_cube);
    SDL_Quit();
    emscripten_cancel_main_loop();

    // SDL_DestroyRenderer(renderer);
  }