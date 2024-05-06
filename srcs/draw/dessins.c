/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dessins.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:45:36 by tgeorge           #+#    #+#             */
/*   Updated: 2023/04/26 13:03:24 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_fullblack(t_root root)
{
	t_data	img;
	int		x;
	int		y;

	img.img = mlx_new_image(root.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	y = 0;
	while (y <= 1080)
	{
		x = 0;
		while (x <= 1920)
		{
			my_mlx_pixel_put(&img, x, y, 0x00000000);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(root.mlx, root.mlx_win, img.img, 0, 0);
	mlx_destroy_image(root.mlx, img.img);
}

void	ft_gg_g(t_root root)
{
	draw_link(root, 14 * 60, 6 * 60);
	draw_link(root, 13 * 60, 6 * 60);
	draw_link(root, 12 * 60, 6 * 60);
	draw_link(root, 11 * 60, 6 * 60);
	draw_link(root, 10 * 60, 6 * 60);
	draw_link(root, 10 * 60, 7 * 60);
	draw_link(root, 10 * 60, 8 * 60);
	draw_link(root, 10 * 60, 9 * 60);
	draw_link(root, 10 * 60, 10 * 60);
	draw_link(root, 10 * 60, 11 * 60);
	draw_link(root, 10 * 60, 12 * 60);
	draw_link(root, 10 * 60, 13 * 60);
	draw_link(root, 11 * 60, 13 * 60);
	draw_link(root, 12 * 60, 13 * 60);
	draw_link(root, 13 * 60, 13 * 60);
	draw_link(root, 14 * 60, 13 * 60);
	draw_link(root, 14 * 60, 12 * 60);
	draw_link(root, 14 * 60, 11 * 60);
	draw_link(root, 14 * 60, 10 * 60);
	draw_link(root, 13 * 60, 10 * 60);
	draw_link(root, 12 * 60, 10 * 60);
}

void	ft_gg_d(t_root root)
{
	draw_link(root, 20 * 60, 6 * 60);
	draw_link(root, 19 * 60, 6 * 60);
	draw_link(root, 18 * 60, 6 * 60);
	draw_link(root, 17 * 60, 6 * 60);
	draw_link(root, 16 * 60, 6 * 60);
	draw_link(root, 16 * 60, 7 * 60);
	draw_link(root, 16 * 60, 8 * 60);
	draw_link(root, 16 * 60, 9 * 60);
	draw_link(root, 16 * 60, 10 * 60);
	draw_link(root, 16 * 60, 11 * 60);
	draw_link(root, 16 * 60, 12 * 60);
	draw_link(root, 16 * 60, 13 * 60);
	draw_link(root, 17 * 60, 13 * 60);
	draw_link(root, 18 * 60, 13 * 60);
	draw_link(root, 19 * 60, 13 * 60);
	draw_link(root, 20 * 60, 13 * 60);
	draw_link(root, 20 * 60, 12 * 60);
	draw_link(root, 20 * 60, 11 * 60);
	draw_link(root, 20 * 60, 10 * 60);
	draw_link(root, 19 * 60, 10 * 60);
	draw_link(root, 18 * 60, 10 * 60);
}

int	gg_animation(t_root *root)
{
	if (root->game->framecount <= root->game->anim->player_frame * 3)
	{
		ft_gg_g(*root);
		ft_gg_d(*root);
	}
	else
		root->game->framecount = 0;
	root->game->framecount++;
	return (1);
}
