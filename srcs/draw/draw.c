/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:57:32 by tgeorge           #+#    #+#             */
/*   Updated: 2023/04/26 12:17:41 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	draw_map(t_root root)
{
	int		i;
	int		j;

	j = -1;
	while (++j < root.game->height)
	{
		i = -1;
		while (++i < root.game->width)
		{
			if (root.game->map[j][i] == '1')
				draw_tree(root, i * 60, j * 60);
			else if (root.game->map[j][i] == 'C')
				draw_rubis(root, i * 60, j * 60);
			else if (root.game->map[j][i] == 'P')
				draw_link(root, i * 60, j * 60);
			else if (root.game->map[j][i] == 'E')
				draw_ladder(root, i * 60, j * 60);
			else if (root.game->map[j][i] == '0')
				draw_floor1(root, i * 60, j * 60);
			else if (root.game->map[j][i] == 'V')
				draw_vertical_ennemy(root, i, j);
			else if (root.game->map[j][i] == 'H')
				draw_horizontal_ennemy(root, i, j);
		}
	}
}

void	clear_number(t_root root)
{
	t_data	img;
	int		x;
	int		y;

	img.img = mlx_new_image(root.mlx, 120, 60);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	y = 0;
	while (y <= 60)
	{
		x = 0;
		while (x <= 120)
		{
			my_mlx_pixel_put(&img, x, y, 0x00000000);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(root.mlx, root.mlx_win,
		img.img, (root.game->width + 1) * 60, 60);
	mlx_destroy_image(root.mlx, img.img);
}

void	re_draw(t_root root)
{
	int		i;
	int		j;

	j = -1;
	while (++j < root.game->height)
	{
		i = -1;
		while (++i < root.game->width)
		{
			if (root.game->map[j][i] == '1')
				draw_tree(root, i * 60, j * 60);
			else if (root.game->map[j][i] == 'C')
				draw_rubis(root, i * 60, j * 60);
			else if (root.game->map[j][i] == 'P')
				draw_link(root, i * 60, j * 60);
			else if (root.game->map[j][i] == 'E')
				draw_ladder(root, i * 60, j * 60);
			else if (root.game->map[j][i] == '0')
				draw_floor1(root, i * 60, j * 60);
			else if (root.game->map[j][i] == 'V')
				draw_vertical_ennemy(root, i, j);
			else if (root.game->map[j][i] == 'H')
				draw_horizontal_ennemy(root, i, j);
		}
	}
}
