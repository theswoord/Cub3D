/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhali < nbouhali@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 02:31:57 by nbouhali          #+#    #+#             */
/*   Updated: 2024/02/01 03:09:20 by nbouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	texture_set(t_cube *cube)
{
	int	i;

	i = 0;
	// cube->colors->ea = extract_color(cube->drawings->ea, cube->colors->dim);
	// cube->colors->no = extract_color(cube->drawings->no, cube->colors->dim);
	// cube->colors->we = extract_color(cube->drawings->we, cube->colors->dim);
	// cube->colors->so = extract_color(cube->drawings->so, cube->colors->dim);
	cube->colors->sdlea = extract_color_sdl(cube->drawings->ssdlea);

	cube->colors->sdlno = extract_color_sdl(cube->drawings->ssdlno);
	cube->colors->sdlwe = extract_color_sdl(cube->drawings->ssdlwe);
	cube->colors->sdlso = extract_color_sdl(cube->drawings->ssdlso);

	// while (i < 8)
	// {
	// 	if (cube->colors->dim[i] != 32)
	// 		problem("Error\nmore or less than 32 bit\n");
	// 	i++;
	// }
}
Uint8	*extract_color_sdl(SDL_Surface *texture)
{

	Uint8 *colors = (Uint8*)texture->pixels;
	// for (size_t i = 0; i < 1024; i+=4)
	// {
	// 	printf("%d %d %d %d \n",colors[i],colors[i+1],colors[i+2],colors[i+3]);
	// 	/* code */
	// }
	
	return (colors);
}

// unsigned long	*extract_color(mlx_texture_t *texture, int *arr)
// {
// 	int				i;
// 	int				j;
// 	static int		k;
// 	int				total;
// 	unsigned long	*tmp;

// 	i = 0;
// 	j = 0;
// 	total = texture->height * texture->width;
// 	tmp = malloc((texture->height * texture->width) * sizeof(unsigned long));
// 	if (!tmp)
// 		return (NULL);
// 	arr[k] = texture->height;
// 	arr[k + 1] = texture->width;
// 	k += 2;
// 	while (i < total)
// 	{
// 		tmp[i] = (texture->pixels[j] << 24) | (texture->pixels[j
// 				+ 1] << 16) | (texture->pixels[j + 2] << 8) | (texture->pixels[j
// 				+ 3]);
// 		j += texture->bytes_per_pixel;
// 		i++;
// 	}
// 	mlx_delete_texture(texture);
// 	return (tmp);
// }

void	init_mlx(t_cube *cube)
{
	// cube->window->mlx = mlx_init(WIDTH, HEIGHT, "almoka3ab", false);
	// cube->window->img = mlx_new_image(cube->window->mlx, WIDTH, HEIGHT);
	// mlx_image_to_window(cube->window->mlx, cube->window->img, 0, 0);
}

void	draw_background( t_cube *cube)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		while (y < HEIGHT / 2)
		{
			// mlx_put_pixel(img, x, y, cube->colors->finalceil);
			Uint8 r = cube->colors->c[0];
			Uint8 g = cube->colors->c[1];
			Uint8 b = cube->colors->c[2];

			SDL_SetRenderDrawColor(cube->renderer,r,g,b,255);
			SDL_RenderDrawPoint(cube->renderer,x,y);
			SDL_SetRenderDrawColor(cube->renderer,0,0,0,0);

			y++;
		}

		while (y < HEIGHT)
		{
			Uint8 r = cube->colors->f[0];
			Uint8 g = cube->colors->f[1];
			Uint8 b = cube->colors->f[2];
			// mlx_put_pixel(img, x, y, cube->colors->finalfloor);
			SDL_SetRenderDrawColor(cube->renderer,r,g,b,255);
			SDL_RenderDrawPoint(cube->renderer,x,y);
			SDL_SetRenderDrawColor(cube->renderer,0,0,0,0);

			y++;
		}
		y = 0;
		x++;
	}
}

void	map_divider(char *textures, char *background, char *map, t_cube *cube)
{
	if (cube->queue < 6)
		problem("Error\nSomething wrong with the map");
	cube->background = ft_split(background, '\n');
	if (element_count(background, ',') > 4)
		problem("Error\ncheck the RGB params");
	free(background);
	cube->textures = ft_split(textures, '\n');
	free(textures);
	cube->map = ft_split(map, '\n');
	free(map);
}
