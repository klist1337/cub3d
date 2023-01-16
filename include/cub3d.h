/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:09:40 by eassofi           #+#    #+#             */
/*   Updated: 2023/01/16 16:16:01 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H
//# include "../miniLibX/mlx.h"
# include "mlx.h"
# include <math.h>
# include <sys/time.h>
# include "../src/get_next_line/get_next_line.h"
# include "../libft/libft.h"

# define ESC 53
# define MV_RIGHT 124
# define MV_LEFT 123
# define ROT_RIGHT 2
# define ROT_LEFT 0
# define MV_FORWRD 13
# define MV_BACK 1
# define W 600
# define H 609
# define TEXT_W 64
# define TEXT_H 64
# define ON_DESTROY 17

# define GREY 0x808080
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define RED 0xFF0000

# define TRANSLATE_X 0
# define TRANSLATE_Y 50
# define CUBE_RADIUS 2
# define MINIMAP_LIMIT 20

typedef struct s_cub
{
	int		*width;
	int		height;
	int		x;
	int		y;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	raydir_x;
	double	ray_posx;
	double	ray_posy;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	side_distx;
	double	side_disty;
	double	delta_distx;
	double	delta_disty;
	double	perpwalldist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	frametime;
	double	mv_speed;
	double	rot_speed;
	int		text_num;
	double	wall_x;
	int		text_x;
	int		text_y;
	int		text_w;
	int		text_h;
	float	ray_dirx0;
	float	ray_dirx1;
	float	ray_diry0;
	float	ray_diry1;
	float	row_dist;
	float	floorx;
	float	floory;
	float	floor_stepx;
	float	floor_stepy;
	int		floor_texture;
	int		ceiling_texture;
	int		tx;
	int		ty;
}			t_cub;
typedef struct s_dda
{
	int	step_x;
	int	step_y;
	int	hit;
	int	side;
}			t_dda;

typedef struct s_img
{
	unsigned int	color;
	void			*img;
	int				*data;
	int				bpp;
	int				size_line;
	int				endian;
	void			*tex_ptr;
	int				img_width;
	int				img_height;
}						t_img;

typedef struct s_point
{
	int		x;
	int		y;
}	t_point;

typedef struct s_pointf
{
	float	x;
	float	y;
}	t_pointf;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*im;
	char	*data;
	int		**matrix;
	int		**texture;
	int		color;
	int		height;
	int		*width_tab;
	int		width;
	int		img_h;
	int		img_w;
	int		x;
	int		y;
	void	*dta;
	int		buffer[H][W];
	char	**path;	
	int		re_buff;
	int		error;
	int		flag;
	char	*floor;
	char	*celling;
	long	celling_color;
	long	floor_color;
	char	start_pos;
	int		start_x;
	int		start_y;
	int		nb_player;
	int		*nb_elemt;
	int		**map_entry;
	t_cub	cub;
	t_dda	dda;
	t_img	img;
}			t_mlx;

typedef struct s_square
{
	t_point	point;
	int		radius;
	t_mlx	*mlx;
	int		color;
	int		size;
}	t_square;

/****** RAYCASTING FUNCT ******/
unsigned long	creatergb(int r, int g, int b);
void			raycasting(t_mlx *mlx);
void			raycaster(t_mlx *mlx);
int				do_key(int key, t_mlx *mlx);
void			move_key(int key, t_mlx *mlx);
void			move_left(t_mlx *mlx);
void			move_right(t_mlx *mlx);
void			rotate_right(t_mlx *mlx);
void			rotate_left(t_mlx *mlx);
void			move_forward(t_mlx *mlx);
void			move_backward(t_mlx *mlx);
void			draw(t_mlx *mlx);
int				main_loop(t_mlx *mlx);
void			floorcast(t_mlx *mlx);

void			init_cub(t_cub *cub);
void			floorcast_color(t_mlx *mlx);
void			init_buff(t_mlx *mlx);
void			load_image(t_mlx *mlx, int *texture, char *path, t_img *img);
void			load_texture(t_mlx *mlx);
void			create_img(t_mlx *mlx);
void			init_texture(t_mlx *mlx);
void			step_texture(t_mlx *mlx, t_cub *cub, t_dda *dda, int x);
void			set_texture(t_dda *dda, t_cub *cub);
void			texture_calculation(t_cub *cub, t_mlx *mlx, t_dda *dda, int x);
void			init_dda_utils(t_cub *cub, t_mlx *mlx);
void			initial_distside_x(t_mlx *mlx, t_cub *cub, t_dda *dda);
void			initial_distside_y(t_mlx *mlx, t_cub *cub, t_dda *dda);
void			perfom_dda(t_mlx *mlx, t_dda *dda, t_cub *cub);
void			dda_algoritm(t_mlx *mlx, t_cub *cub, t_dda *dda);
/**** PARSING **********/

void			skip_six_line(char **line, int fd);
void			get_width(t_mlx *mlx, char **av);
int				fill_matrix(t_mlx *mlx, char **av);
void			player(t_mlx *mlx);
int				check_nb_elmt(t_mlx *mlx);
int				check_nb_elmt2(t_mlx *mlx);
void			fill_color2(char **matrix, int nb, char **color);
int				fill_color(char *str, char **color);
int				get_rgb(t_mlx *mlx, char *str);
int				check_nb_comma(char *s);
int				color_isdigit(char *rgbcolor);
int				convert_colorrgb(char *rgbcolor, long *color);
int				map_element(char **line, int fd);
int				get_map_elmt(t_mlx *mlx, int fd, char **line);
void			fill_map(t_mlx *mlx, char **av);
void			first_map(t_mlx *mlx, char **av);
int				check_map(t_mlx *mlx, char **av);
int				empty_map_or_directory(char **av);
int				check_file_and_extension(char **av, int fd);
void			get_height(t_mlx *mlx, char *line, int fd);
void			join_texture(char **matrix, int *flag, char **path);
int				get_tex(char *str, char **path, int *flag);
int				get_texture(t_mlx *mlx, char *line, int *j);
int				isvalid_texture(char *path);
int				check_texture(char **path);

/********  UTILS  ***************/

void			global_free(t_mlx *mlx);
void			print_error(char *s);
void			free_texture(t_mlx *mlx);
void			free_int_matrix(t_mlx *mlx, int **matrix);
void			skip_line_space(char **line, int fd);
int				ft_isspace(char c);
size_t			ft_len(char *str);
void			skip_and_fill(char *line, char *new);
char			*fill_space_by_one(char *line, t_mlx *mlx);
void			free_char_matrix(char **matrix);
void			free_int_matrix(t_mlx *mlx, int **matrix);
void			free_texture(t_mlx *mlx);
void			init_param_mlx(t_mlx *mlx);
int				maximum(int a, int b);
void			display_matrix(t_mlx *mlx);
void			print_matrix(char **matrix);
void			print_path(char **path);
int				close_window(t_mlx *mlx);
int				get_nb_of_split(char **matrix);
int				check_extension_map(char *av, char *ext);
void			copy(char *s1, char *s2, int nb);
char			*copy_path(char *s1);
void			count_elmt(t_mlx *mlx, char *str);
int				compare_element(char *str);
void			print_map(t_mlx *mlx);
void			put_pixel(t_mlx *mlx, int x, int y, int color);
float			distance(t_point p1, t_point p2);
void			draw_map(t_mlx *mlx);
void			square(t_square util);
void			put_pixel(t_mlx *mlx, int x, int y, int color);
void			dda(t_point p1, t_point p2, t_mlx *mlx, int color);
void			square_player(t_square util, t_point player, t_point translate);

#endif