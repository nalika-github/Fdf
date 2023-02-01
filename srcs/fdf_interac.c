/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_interac.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:53:50 by ptungbun          #+#    #+#             */
/*   Updated: 2023/02/01 10:01:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_replotscr(t_map *map, t_scr **scr)
{
	int		i;
	int		j;
	t_coor	**met;

	met = map->metrix;
	i = 0;
	while (i < map->n_row)
	{
		j = 0;
		while (j < map->n_col)
		{
			scr[i][j].x = (int)(met[i][j].x * map->scale) + map->shift_x;
			scr[i][j].y = (int)(met[i][j].y * map->scale) + map->shift_y;
			scr[i][j].color = met[i][j].color;
			j++;
		}
		i++;
	}
}

void	interac_shift(t_map *map)
{
	t_vp		vp;

	vp = map->viewport;
	map->is_shift = 0;
	fdf_replotscr(map, map->scr);
	ft_bzero(vp.img.addr, WINDOW_WIDTH * WINDOW_HEIGHT * vp.img.bpp / 8);
	fdf_render(map, map->scr, &vp.img);
	mlx_clear_window(vp.mlx_ptr, vp.win_ptr);
	mlx_put_image_to_window(vp.mlx_ptr, vp.win_ptr, vp.img.mlx_img, 0, 0);
}

void	interac_rotate(t_map *map)
{
	t_vp		vp;

	vp = map->viewport;
	map->is_rotate = 0;
	fdf_rotate(map);
	fdf_replotscr(map, map->scr);
	ft_bzero(vp.img.addr, WINDOW_WIDTH * WINDOW_HEIGHT * vp.img.bpp / 8);
	fdf_render(map, map->scr, &vp.img);
	mlx_clear_window(vp.mlx_ptr, vp.win_ptr);
	mlx_put_image_to_window(vp.mlx_ptr, vp.win_ptr, vp.img.mlx_img, 0, 0);
}

int	interac_close(t_map *map)
{
	t_vp	vp;

	vp = map->viewport;
	mlx_clear_window(vp.mlx_ptr, vp.win_ptr);
	mlx_destroy_window(vp.mlx_ptr, vp.win_ptr);
	mlx_destroy_image(vp.mlx_ptr, vp.img.mlx_img);
	fdf_cleanup(map);
	exit(0);
	return (0);
}

void	fdf_interac_filter(int key, t_map *map)
{
	if (key >= 65361 && key <= 65364)
		map->is_shift = 1;
	if (key == 105 || key == 111)
		map->is_shift = 1;
	if (key == 97 || key == 115 || key == 100 || key == 119)
		map->is_rotate = 1;
	if (key == 113 || key == 101)
		map->is_rotate = 1;
	if (key == 65307)
		map->is_close = 1;
}
