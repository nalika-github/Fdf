/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptungbun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:28:15 by ptungbun          #+#    #+#             */
/*   Updated: 2023/01/29 12:28:17 by ptungbun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <mlx.h>
# include <string.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>

# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 800
# define PI 3.141592654
# define BUFFER_SIZE 42

typedef struct s_coordinate
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_coor;

typedef struct s_screen
{
	int	x;
	int	y;
	int	color;
}	t_scr;

typedef struct s_image
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_viewport
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_image	img;
}	t_vp;

typedef struct s_map
{
	int		n_row;
	int		n_col;
	int		shift_x;
	int		shift_y;
	int		is_rotate;
	int		is_shift;
	int		is_close;
	double	scale;
	double	angle_z;
	double	angle_x;
	double	angle_y;
	t_vp	viewport;
	t_coor	**metrix;
	t_scr	**scr;
}	t_map;

void	get_size(char *fdf_file, t_map *map);
t_coor	**matrix_alloc(int n_col, int n_row);
void	fill_matrix(char *fdf_file, t_map *map);
t_map	fdf_readfile(char *Fdf_file);
void	fdf_imgpixelput(t_image *img, int x, int y, int color);
void	fdf_bresenham_x(t_image *img, int *x, int *y, int color);
void	fdf_bresenham_y(t_image *img, int *x, int *y, int color);
void	fdf_drawline(t_image *img, int *x, int *y, int color);
void	fdf_getmax(t_map *map, double *max);
void	fdf_getmin(t_map *map, double *min);
double	default_scale(double *max, double *min);
void	fdf_set_default(t_map *map);
void	fdf_rotate_x(t_map *map);
void	fdf_rotate_y(t_map *map);
void	fdf_rotate_z(t_map *map);
void	fdf_rotate(t_map *map);
void	fdf_render_x(t_map *map, t_scr **scr, t_image *img);
void	fdf_render_y(t_map *map, t_scr **scr, t_image *img);
void	fdf_render(t_map *map, t_scr **scr, t_image *img);
t_scr	**fdf_plotscr(t_map *map);
void	fdf_set_center(t_map *map);
int		check_color(char **box);
int		get_color(char *hex);
void	fdf_get_data(t_map *map, char **box, int i, int j);
void	fdf_deal_shift(int key, t_map *map);
void	fdf_deal_rotate(int key, t_map *map);
int		fdf_key_hook(int key, t_map *map);
int		fdf_esc_hook(int key, t_map *map);
void	fdf_interac_filter(int key, t_map *map);
void	interac_shift(t_map *map);
void	interac_rotate(t_map *map);
int		interac_close(t_map *map);
void	fdf_cleanup(t_map *map);
int		ft_tolower(int c);
int		ft_atoi(const char *str);
void	*ft_bzero(void *b, size_t len);
void	ft_putstr(char *str);
int		ft_gnlisn_line(char *str);
size_t	ft_gnlline_len(char *stash);
size_t	ft_gnlstrlen(const char *str);
void	*ft_gnlcalloc(size_t nmemb, size_t size);
char	*ft_gnlstrcat(char *s1, char *s2);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);

#endif
