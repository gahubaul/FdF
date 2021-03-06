/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 01:42:23 by gahubaul          #+#    #+#             */
/*   Updated: 2016/04/02 03:30:15 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>

# define EXIT 53
# define BUFF_SIZE 600
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define PLUS 69
# define MINUS 78
# define M 46
# define N 45
# define B 11
# define EGAL 24
# define UNDER 27
# define I 34
# define T 17
# define R 15
# define O 31
# define Z 6

# define MAX_X 1920
# define MAX_Y 1080

# define BLUE 0x0901F7
# define BLUE_C 0x015BF7
# define SKY 0x01B5F7
# define LAGON 0x33AB9B
# define WGREEN 0x01F79D
# define RAZER 0x01F74B
# define LIMON 0xADF701
# define YELLOW 0xEFF701
# define ORANGE 0xF78C01
# define RED 0xFE4D01
# define BACKGROUND 0x4C1B1B

typedef struct				s_environ
{
	char					*name;
	void					*mlx;
	void					*win;
	void					*img;
	char					*data;
	char					*str;
	double					size_x;
	double					size_y;
	double					size_xx;
	double					size_yy;
	double					move_x;
	double					move_y;
	double					z_max;
	double					z_min;
	double					distance_z;
	int						fd;
	int						width;
	int						height;
	int						size;
	int						bpp;
	int						sl;
	int						ed;
	int						origin_x;
	int						origin_y;
	int						space;
	int						max_y;
	int						max_x;
	int						iso;
	int						background;
	int						info;
	int						tmp;
	int						verif;
	int						touch_z;
	long int				verif_atoi;
}							t_env;

typedef struct				s_bresenham
{
	int						dx;
	int						dy;
	int						i;
	int						xinc;
	int						yinc;
	int						cumul;
	int						x;
	int						y;
}							t_b;

typedef struct				s_point
{
	int						x;
	int						y;
	int						c;
}							t_p;

typedef struct				s_fdf_map
{
	double					x;
	double					y;
	double					z;
	double					zo;
	int						color;
}							t_map;

typedef struct				s_all
{
	t_map					**map;
	t_env					e;
	t_p						p1;
	t_p						p2;
	t_b						b;
	int						image;
}							t_a;

/*
**		fdf.c
*/
void						print(t_a *a);
int							main(int argc, char **argv);
void						ft_print_image_x(t_a *a, int x, int y);

/*
**		fdf_color.c
*/
void						put_color(t_a *a);
void						ft_background(t_a *a);
int							localisation_color(t_a *a, int z);
void						ft_put_info(t_a *a);

/*
**		fdf_image.c
*/
void						ft_error(char *str, t_a *a);
void						fdf_new_image(t_a *a);
void						ft_p_pixel_image(t_a *a, int y, int x, int color);
void						init(t_a *a);

/*
**		fdf_key.c
*/
int							my_fonct_key(int keycode, t_a *a);
void						ft_info(t_a *a);

/*
**		fdf_modif.c
*/
void						fdf_modif_pos(t_a *a, int keycode);
void						ft_modif_size(t_a *a, int keycode);
void						fdf_recover_size(t_a *a);

/*
**		fdf_others.c
*/
void						size_z_max_min(t_a *a);
void						ft_modif_z(t_a *a, int keycode);
int							recover_point(t_a *a, int x, int y, char c);
void						origin_z(t_a *a);

/*
**		fdf_print.c
*/
void						ft_print_to_image_bresenham(t_a *a);
void						ligne(t_a *a, int color);

/*
**		fdf_struct.c
*/
unsigned int				count_carac(char *line);
t_map						**fonction_creat_struct(t_a *a);
void						send_map_to_struct(t_a *a, char *str, int y);

#endif
