/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_help3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhali < nbouhali@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 02:33:24 by nbouhali          #+#    #+#             */
/*   Updated: 2024/02/01 03:05:22 by nbouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	read_map_help(t_cube *cube, char **line, char **map)
{
	*map = ft_strjoingnle(*map, *line);
	free(*line);
	if (ft_strnstr(*map, "11", strlen(*map)) && cube->queue != 6)
		problem("Error\nyour Map is not last\n");
}

void	read_map_lost(char **save_ptr, char **map)
{
	*save_ptr = ft_strtrim(*map, "\n");
	free(*map);
	if (ft_strnstr(*save_ptr, "\n\n", strlen(*save_ptr)))
		problem("Error\nmany newlines found in your map\n");
}

void	ptr_init(char **textures, char **background, char **map)
{
	*textures = NULL;
	*background = NULL;
	*map = NULL;
}

void	read_map(int fd, t_cube *cube)
{
	char	*textures;
	char	*background;
	char	*map;
	char	*line;
	char	*save_ptr;

	ptr_init(&textures, &background, &map);

	line = get_next_line(fd);
	// emscripten_read
	
	// line = 
	// printf("%d\n", fd );
	if (!line)
		problem("Error\nfile empty");
	while (line != NULL)
	{
		// printf("%s",line);
		if (ft_strnstr(line, "F ", strlen(line)) || ft_strnstr(line, "C ",
				strlen(line)))
			read_background(cube, &line, &background);
		else if (ft_strnstr(line, "EA ", strlen(line)) || ft_strnstr(line,
				"WE ", strlen(line)) || ft_strnstr(line, "SO ",
				strlen(line)) || ft_strnstr(line, "NO ", strlen(line)))
			read_textures(cube, &line, &textures);
		else
			read_map_help(cube, &line, &map);
		line = get_next_line(fd);
		// printf("------%s------\n",line);
	}
	read_map_lost(&save_ptr, &map);
	map_divider(textures, background, save_ptr, cube);
}

void	struct_init(t_cube *cube)
{
	
	// cube->window = (t_win *)malloc(sizeof(t_win));
	// ft_memset(cube, 0, sizeof(t_win));
	cube->colors = (t_colors *)malloc(sizeof(t_colors));
	memset(cube, 0, sizeof(t_colors));
	cube->drawings = (t_textures *)malloc(sizeof(t_textures)); //7iedto
	memset(cube, 0, sizeof(t_textures));
	cube->wanted = "01EWSN ";
	cube->quit = false;
	cube->targetFPS = 60;
	cube->frameDelay = 1000/ cube->targetFPS;
}
