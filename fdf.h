/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 01:42:23 by gahubaul          #+#    #+#             */
/*   Updated: 2016/03/05 01:42:25 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft/includes/libft.h"
#include <mlx.h>
#include <fcntl.h>

#define BUFF_SIZE 600
#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124
#define MOUSE_UP 4

#define GREEN 9
#define BLUE 11
#define RED 15
#define EXIT 53

typedef struct	s_mlxstore
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int 	size_y;
	int 	size_x;
	int 	fd;
	unsigned max_line;
	unsigned nb_caract;

}				t_mlxstore;

typedef struct	s_fdfstore
{
	double			y;
	double			x;
	double			z;
	int 	color;
}				t_fdfpoint;


void		ft_error(char *str);
void		print_map_to_win(t_mlxstore *MLX, char *line, int y);
int			count_carac(char *line);
t_fdfpoint	**fonction_creat_struct(t_fdfpoint **mlxmap, int max_line, int nb_caract);
void		send_map_to_struct(t_fdfpoint **mlxmap, char *str, int y, t_mlxstore mlx);
void		ft_print_struct(t_fdfpoint **mlxmap, int max_line, int nb_caract);
int		my_fonct_key(int keycode, t_mlxstore *mlx);

#endif
