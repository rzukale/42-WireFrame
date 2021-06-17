/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 21:47:17 by rzukale           #+#    #+#             */
/*   Updated: 2020/07/28 15:01:06 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <math.h>

typedef struct	s_vector
{
	int			z;
	int			color;
	int			x;
	int			y;
}				t_vector;

typedef struct	s_lst
{
	t_vector	*data;
	void		*next;
}				t_lst;

typedef struct	s_camera
{
	int			iso;
	int			zoom;
	double		alpha;
	double		beta;
	double		gamma;
	float		z_value;
	int			x_offset;
	int			y_offset;
}				t_camera;

typedef struct	s_map
{
	t_lst		*list;
	int			height;
	int			width;
	int			min;
	int			max;
}				t_map;

typedef struct	s_delta
{
	float	x;
	float	y;
}				t_delta;

typedef struct	s_line
{
	float		x;
	float		y;
	int			z;
	int			color;
}				t_line;

typedef struct	s_colors
{
	int		base_color;
	int		mid_color;
	int		top_color;
}				t_color;

typedef	struct	s_image
{
	void		*image;
	char		*buffer;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_image;

typedef struct	s_env
{
	void		*mlx;
	void		*window;
	t_image		*image;
	t_color		colors;
	t_map		*map;
	t_camera	*camera;
	int			width;
	int			height;
}				t_env;

double			get_percentage(int current, int start, int end);
float			ft_max(float a, float b);
float			get_sign(float i);
int				get_color(t_line current, t_line start,
						t_line end, t_delta delta);
int				count_words(char *str);
int				validate_word(char *str);
int				check_for_color(char *str, int *i);
int				ft_min(int a, int b);
int				get_gradient(int start, int end, double percentage);
int				read_input(int key, t_env *env);
int				choose_random_color(void);
t_camera		*init_camera(t_env *env);
t_env			*initialise_env(void);
t_line			setup_line(t_vector *vector, t_env *env);
t_lst			*ft_create_elem(void *data);
t_lst			*fill_map(char *str, int y);
t_lst			*join_lists(t_lst **list1, t_lst *list2);
t_vector		*new_vector(int y, int x, int z, int color);
t_vector		*get_vector(int x, int y, t_lst **list);
void			free_list(t_lst **begin_list);
void			parse_file(char *argv, t_env *env);
void			ft_list_push_back(t_lst **begin_list, t_vector *data);
void			cleanup(char **array);
void			display_error(int nbr);
void			find_min_max(t_map *map);
void			fill_colors(t_env *env, int random);
void			setup_window(t_env **env, char *title);
void			free_all(t_env *env);
void			render(t_env *env);
void			isometric(float *x, float *y, int z);
void			rotate_x(float *y, int *z, double alpha);
void			rotate_y(float *x, int *z, double beta);
void			rotate_z(float *x, float *y, double gamma);
void			draw_line(t_line start, t_line end, t_env *env);
void			print_menu(t_env *env);
void			switch_projection(t_env *env);
void			reset_camera(t_env *env);
void			assign_color(t_lst **temp, t_env *env, int random);
void			reset_camera(t_env *env);
void			zoom_image(int key, t_env *env);
void			rotate_image(int key, t_env *env);
void			modify_height(int key, t_env *env);
void			move_image(int key, t_env *env);
void			random_color(t_env *env);
void			clear_image(t_env *env);
void			pixel_put(t_env *env, int x, int y, int color);

#endif
