/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptungbun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:21:41 by ptungbun          #+#    #+#             */
/*   Updated: 2023/02/01 12:15:19 by ptungbun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	argc_check(int argc)
{
	if (argc < 2 || argc > 2)
	{
		ft_putstr("Error: invalid arguments.\n");
		return (1);
	}
	return (0);
}

int	openfile_check(char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Error:");
		ft_putstr(strerror(errno));
		ft_putstr("\n");
		return (1);
	}
	close(fd);
	return (0);
}

int	file_ext_check(char **argv)
{
	int		i;
	int		j;
	char	*fdf_text;

	fdf_text = "fdf.";
	i = 0;
	while (argv[1][i])
		i++;
	j = 0;
	while (fdf_text[j])
	{
		if (argv[1][i - 1] != fdf_text[j])
		{
			ft_putstr("Error: invalid file extension.\n");
			return (1);
		}
		j++;
		i--;
	}
	return (0);
}

int	fdf_handle_error(int argc, char **argv)
{
	if (argc_check(argc))
		return (1);
	if (openfile_check(argv))
		return (1);
	if (file_ext_check(argv))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map		map;
	t_vp		*vp;

	if (fdf_handle_error(argc, argv))
		return (0);
	map = fdf_readfile(argv[1]);
	vp = &map.viewport;
	vp->mlx_ptr = mlx_init();
	vp->win_ptr = mlx_new_window(vp->mlx_ptr, WINDOW_WIDTH, \
	WINDOW_HEIGHT, "fdf");
	vp->img.mlx_img = mlx_new_image(vp->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	vp->img.addr = mlx_get_data_addr(vp->img.mlx_img, &vp->img.bpp, \
	&vp->img.line_len, &vp->img.endian);
	fdf_set_default(&map);
	map.scr = fdf_plotscr(&map);
	fdf_render(&map, map.scr, &vp->img);
	mlx_put_image_to_window(vp->mlx_ptr, vp->win_ptr, vp->img.mlx_img, 0, 0);
	mlx_hook(vp->win_ptr, 2, 1L << 0, fdf_key_hook, &map);
	mlx_key_hook(vp->win_ptr, fdf_esc_hook, &map);
	mlx_hook(vp->win_ptr, 17, 0L, interac_close, &map);
	mlx_loop(vp->mlx_ptr);
	return (0);
}
