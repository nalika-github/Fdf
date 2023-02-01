/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_readfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:50:25 by ptungbun          #+#    #+#             */
/*   Updated: 2023/01/27 15:03:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_size(char *fdf_file, t_map *map)
{
	char	**split;
	char	*line;
	int		fd;

	fd = open(fdf_file, O_RDONLY);
	map->n_row = -1;
	map->n_col = 0;
	line = "start";
	while (line)
	{
		line = get_next_line(fd);
		if (map->n_row == -1)
		{
			split = ft_split(line, ' ');
			while (split[map->n_col])
			{
				free(split[map->n_col]);
				map->n_col = map->n_col + 1;
			}
			free(split);
		}
		map->n_row = map->n_row + 1;
		free(line);
	}
	close(fd);
}

t_coor	**matrix_alloc(int n_col, int n_row)
{
	t_coor	**metrix;
	int		i;

	metrix = (t_coor **)malloc(sizeof(t_coor *) * n_row);
	i = 0;
	while (i < n_row)
	{
		metrix[i] = (t_coor *)malloc(sizeof(t_coor) * n_col);
		i++;
	}
	return (metrix);
}

void	fill_matrix(char *fdf_file, t_map *map)
{
	int		i[3];
	char	*line;
	char	**split;
	char	**box;

	i[0] = open(fdf_file, O_RDONLY);
	i[1] = -1;
	while (i[1]++ < map->n_row - 1)
	{
		line = get_next_line(i[0]);
		split = ft_split(line, ' ');
		i[2] = -1;
		while (i[2]++ < map->n_col - 1)
		{
			box = ft_split(split[i[2]], ',');
			fdf_get_data(map, box, i[1], i[2]);
			map->metrix[i[1]][i[2]].x = i[2] * 10;
			map->metrix[i[1]][i[2]].y = i[1] * 10;
			free(box);
			free(split[i[2]]);
		}
		free(line);
		free(split);
	}
	close(i[0]);
}

t_map	fdf_readfile(char *fdf_file)
{
	t_map	map;

	get_size(fdf_file, &map);
	map.metrix = matrix_alloc(map.n_col, map.n_row);
	fill_matrix(fdf_file, &map);
	return (map);
}
