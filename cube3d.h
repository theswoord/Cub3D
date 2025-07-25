/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhali < nbouhali@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:27:56 by nbouhali          #+#    #+#             */
/*   Updated: 2024/02/01 03:13:51 by nbouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
#define CUBE3D_H

#define _GNU_SOURCE
#include "get_next_line.h"
// #include "./libft/libft.h"
// #include "MLX420/include/MLX42/MLX42.h"
#include "./SDL/include/SDL.h"
#include "./SDL/SDL2_image/include/SDL_image.h"
#include "stdbool.h"
#include <limits.h>
#include <math.h>
#include <signal.h>
#include <emscripten.h>
#define WIDTH 800.0	 // 1980.0
#define HEIGHT 600.0 // 1080.0
#define MB 32
#define SPEED 7.0
#define ROTSPEED 0.05
#define P1 3.1415926535
#define RAD 0.0174533
#define HORIZONTAL_FOV_DEGREES 66.0
#define HORIZONTAL_FOV_RADIANS (HORIZONTAL_FOV_DEGREES * RAD)

// emcc main_linux.cpp sand.cpp -o your_game.html -s USE_SDL=2 -s SDL2_IMAGE_FORMATS="['png','jpg']" -s USE_WEBGL2=1


enum
{
	VERTICAL = 88,
	HORIZONTAL = 99,
	PV = 1,
	PH = 0,
};

typedef struct s_textures
{
	// mlx_texture_t *ea;
	// SDL_Texture *sdlea;
SDL_Surface * ssdlea;
	// mlx_texture_t *no;
	// SDL_Texture *sdlno;
SDL_Surface * ssdlno;

	// mlx_texture_t *we;
	// SDL_Texture *sdlwe;
SDL_Surface * ssdlwe;

	// mlx_texture_t *so;
	// SDL_Texture *sdlso;
SDL_Surface * ssdlso;

} t_textures;

// typedef struct s_win
// {
// 	mlx_t *mlx;
// 	mlx_image_t *img;

// } t_win;
typedef struct s_colors
{
	int f[3];
	int c[3];
	unsigned long *ea;
	unsigned long *no;
	unsigned long *we;
	unsigned long *so;
	Uint8 *sdlea;
	Uint8 *sdlno;
	Uint8 *sdlwe;
	Uint8 *sdlso;
	unsigned long finalfloor;
	unsigned long finalceil;
	int dim[8];

} t_colors;

typedef struct s_map
{
	double max;
	double lines;
} t_map;
typedef struct s_player
{
	double x;
	double y;
	double angle;
} t_player;

typedef struct s_lines
{
	unsigned long color;
	double startx;
	double starty;
	double endx;
	double endy;
	double savestarty;
} t_lines;

typedef struct s_gatto
{
	int what;
	int side;
	double wallx;
	double wally;
	double distance;
	double deltax;
	double deltay;
	double angle;
	double rayangle;
	double rayx;
	double rayy;
	double xoffset;
	double yoffset;
	double hx;
	double hy;
	double vx;
	double vy;
	int wallheight;
	int savewallheight;

} t_gatto;

typedef struct s_bound
{
	int frontx;
	int fronty;
	int backx;
	int backy;
	int leftx;
	int lefty;
	int rightx;
	int righty;
	int bound[2];

} t_bound;

typedef struct s_cube
{
	t_gatto v3;
	t_textures *drawings;
	t_lines dda;
	int wallheight;
	t_player p;
	t_map misc;
	// t_win *window;
	t_colors *colors;
	char **textures;
	char **background;
	char **map;
	t_bound bound;
	int xp;
	int yp;
	int length;
	int width;
	int queue;
	const char *wanted;
	int fd;
	SDL_Window *win;
	SDL_Surface *screenSurface;
	SDL_Renderer *renderer;
	SDL_Event e;

	bool quit;
	int targetFPS;
	int frameDelay; // Milliseconds per frame
	Uint32 frameStart;
	int frameTime;
} t_cube;

bool found_after_space(char *str, char c);

void read_map(int fd, t_cube *cube);
void map_divider(char *textures, char *background, char *map,
				 t_cube *cube);
void free_tableau(char **tab);
void rgb_parse(char *str, t_cube *cube);
void mini_map_draw(t_cube *cube);
char *copy_and_fill(char *str, int count, char c);
void fill_map(t_cube *cube);
void pressed(void *par);
void parse_textures(t_cube *cube);
void draw_background(t_cube *cube);
void texture_set(t_cube *cube);
// unsigned long *extract_color(mlx_texture_t *texture, int *arr);
void print_error(char *str);
void set_background(t_cube *cube);
void cast_v3(t_cube *cube);
void draw_textures(t_cube *cube);
void textured(t_cube *cube, unsigned long *row, int polarity,
			  int height);
int height_extract(t_cube *cube, char *texture);
void boundaries(t_cube *cube);
void img_destroy(t_cube *cube);
void free_all(t_cube *cube);
void free_stucts(t_cube *cube);
int check_player(t_cube *cube);
void check_cub(char *str);
int check_walls(t_cube *cube);
void map_check(t_cube *cube);
void check_ft(t_cube *cube);
int toupperv2(int c);
void textured_inverted(t_cube *cube, unsigned long *row,
					   int polarity, int height);
int element_count(char *str, char c);
int sp(char *str);
void move_forward(t_cube *cube);
void strife_right(t_cube *cube);
void strife_left(t_cube *cube);
void move_backward(t_cube *cube);
void turn_right(t_cube *cube);
void turn_left(t_cube *cube);
void problem(char *str);
void horizontal_part_one(t_cube *cube);
void horizontal_rays(t_cube *cube);
void vertical_part_one(t_cube *cube);
void vertical_rays(t_cube *cube);
void cast_v3_help(t_cube *cube);
void parse_functions(t_cube *cube);
void struct_init(t_cube *cube);
void ptr_init(char **textures, char **background, char **map);
void read_map_lost(char **save_ptr, char **map);
void read_map_help(t_cube *cube, char **line, char **map);
void read_textures(t_cube *cube, char **line, char **textures);
void read_background(t_cube *cube, char **line,
					 char **background);
double vertical(t_cube *c);
double horizontal(t_cube *c);
void turn_right(t_cube *cube);
void strife_right(t_cube *cube);
void strife_left(t_cube *cube);
void move_backward(t_cube *cube);
void turn_left(t_cube *cube);
void move_forward(t_cube *cube);
void boundaries(t_cube *cube);
void init_mlx(t_cube *cube);
void parse(t_cube *cube);
void parse_west(t_cube *cube, char **tmp, int *i);
void parse_east(t_cube *cube, char **tmp, int *i);
void parse_north(t_cube *cube, char **tmp, int *i);
void parse_south(t_cube *cube, char **tmp, int *i);
void ft_calcule(t_cube *cube);
void map_check_help(t_cube *cube, int *i, int *j);
// void execute_loop(t_cube * cube , int ac , char **av , int fd);
void execute_loop(void * ptr);
void mydda(t_cube *cube, unsigned long *row, int polarity, int height, char color);
Uint8	*extract_color_sdl(SDL_Surface*texture);
void textured_sdl(t_cube *cube, Uint8 *row, int polarity, int height);
void textured_inverted_sdl(t_cube *cube, Uint8 *row, int polarity, int height);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
size_t	ft_strlengnle(char *s);
char	*ft_strjoingnle(char *s1, char *s2);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int check_map_wall(t_cube *cube, double x, double y);
#endif
