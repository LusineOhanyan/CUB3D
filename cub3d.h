/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:46:02 by lohanyan          #+#    #+#             */
/*   Updated: 2023/05/18 16:41:05 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define WIDTH			2040
# define HEIGHT			1000

# define ROTATE_SPEED	0.15
# define MOVE_SPEED		0.2

# define RIGHT			124
# define LEFT			123
# define ESC			53
# define A				0
# define S				1
# define D				2
# define W				13

# define BUFFER_SIZE 10

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

typedef struct s_vars
{
	char	**map;
	char	**col_texture;
	char	**no;
	char	**so;
	char	**we;
	char	**ea;
	char	**floor;
	char	**ceiling;
	int		f_color[3];
	int		c_color[3];
}t_vars;

typedef struct s_index
{
	int	index_no;
	int	index_so;
	int	index_ea;
	int	index_we;
	int	index_c;
	int	index_f;
}				t_index;

typedef struct s_img
{
	void	*ptr;
	char	*img;
	int		bpp;
	int		width;
	int		height;
	int		size_line;
	int		endian;
}				t_img;

typedef struct s_game
{
	int		f_color;
	int		c_color;
	int		index;
	void	*mlx;
	void	*win;
	void	*no;
	void	*so;
	void	*ea;
	void	*we;
	int		x;
	int		y;
}				t_game;

typedef struct s_raycasting
{
	double	perpwalldist;
	double	deltadistx;
	double	deltadisty;
	double	sidedistx;
	double	sidedisty;
	double	camerax;
	double	raydiry;
	double	raydirx;
	double	planex;
	double	planey;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		stepx;
	int		stepy;
	int		side;
	int		mapx;
	int		mapy;
	int		hit;
}				t_raycasting;

typedef struct s_addres
{
	t_raycasting	*rcasting;
	t_index			*index;
	t_game			*game;
	t_img			*img;
	t_vars			vars;
}				t_addres;

char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
long	ft_strlen(char *s);
char	*ft_strtrim(char *s1, char *set);
void	ft_check_wall(char **map);
void	ft_check_wall(char **map);
void	ft_check_wall1(char **map);
void	ft_check_wall2(char **map);
int		check_argv(char *str);
int		ft_strcmp(char *s1, char *s2);
int		check_path_id(t_vars *vars);
char	*ft_strchr(const char *str, int c);
char	*get_next_line(int fd);
void	parsing_utils(t_vars *vars);
void	parsing(int fd, int count, t_vars *vars);
int		get_index_map(char	**map, int count);
int		without_newline_map(char	**map, int count);
char	**get_new_map(char **map, t_vars *vars, int count);
void	check_empty_line(t_vars *vars);
int		count_map(int fd2);
int		check_argv_for_xpm(char *str);
void	check_path_argument(char **str);
void	check_texture(t_vars *vars);
int		ft_new_line(char *str);
void	ft_check_digit_floor(t_vars *vars);
void	ft_check_digit_ceiling(t_vars *vars);
int		ft_isdigit(int c);
void	get_colors(t_vars *vars);
int		ft_isalpha(int c);
int		ft_atoi(char *str);
int		check_symbol(char *str);
void	check_new_line(char *str);
int		check_arg(char **str);
int		check_argument(char **str);
int		check_xpm(char **str);
char	*ft_strrchr(const char *s, int c);
void	init_t_vars(t_vars *vars);
void	print_errors(int *num);
int		errors(t_vars *vars);
void	get_identifiers(t_vars *vars);
void	get_identifiers1(t_vars *vars);
void	get_identifiers2(t_vars *vars);
void	check_player(t_vars *vars);
int		count_player(t_vars *vars);
void	check_flag(int flag);
void	check_count_player(char *str, int *flag, int i);
char	**split_texture(char *texture);
void	check_digit(char *str);
void	utils_new_map(int count);
void	checking_character(char **map);
void	check_character(char **map);
void	checking(char **map);
// raycasting
int		create_trgb(int r, int g, int b);
void	initializer(t_addres *address);
void	init_struct_game(t_addres *address);
void	init_struct_index(t_addres *address);
void	init_struct_img(t_addres *address);
void	init_struct_raycasting(t_addres *address);
void	init_structs(t_addres *address);
void	draw_floor_and_celling(t_addres *data, char *dest);
int		ft_texx(t_addres *address, int n);
int		draw_walls(t_addres *address, char *dest, char *dest_2, int texx);
void	norm_init_win_3(t_addres *address);
float	ft_abs(float num);
char	*get_correct_arg(char *ptr);
void	init_plane(t_addres *address, double i, double j);
void	init_dir(t_addres *address, double i, double j);
void	init_player_pos(t_addres *address, int i, int j);
void	ft_get_data_addr(t_addres *address);
int		check_nwse(t_addres *address);
void	find_pos_player(t_addres *address);
void	norm_init_win_2(t_addres *address);
void	norm_init_win(t_addres *address);
void	continue_init_win(t_addres *address);
void	init_win(t_addres *address);
int		key_manager(int key, t_addres *address);
int		close_game(t_addres *address);
void	rotate_right(t_addres *address, double rotate);
void	move_left(t_addres *address);
void	move_right(t_addres *address);
void	move_up(t_addres *address);
void	move_down(t_addres *address);
void	init_structs(t_addres *address);
void	free_double(char **tmp);
void	check_param(t_vars *vars);
void	free_all(t_addres *address);
// raycasting
void	print_t_vars(t_vars *vars);

#endif
