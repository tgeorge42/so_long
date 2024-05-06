/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_pictures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:40:53 by tgeorge           #+#    #+#             */
/*   Updated: 2023/04/24 14:12:00 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	get_char_pics_1(t_root root)
{
	char	*path;
	int		x;
	int		y;

	x = 1000;
	y = 1000;
	path = "./xpm_files/face1.xpm";
	root.game->pics->face1 = mlx_xpm_file_to_image(root.mlx, path, &x, &y);
	if (!root.game->pics->face1)
		launch_init(root);
	path = "./xpm_files/face2.xpm";
	root.game->pics->face2 = mlx_xpm_file_to_image(root.mlx, path, &x, &y);
	if (!root.game->pics->face2)
		launch_init(root);
	path = "./xpm_files/face3.xpm";
	root.game->pics->face3 = mlx_xpm_file_to_image(root.mlx, path, &x, &y);
	if (!root.game->pics->face3)
		launch_init(root);
	path = "./xpm_files/link_back.xpm";
	root.game->pics->back = mlx_xpm_file_to_image(root.mlx, path, &x, &y);
	if (!root.game->pics->back)
		launch_init(root);
}

void	get_char_pics_2(t_root root)
{
	char	*path;
	int		x;
	int		y;

	x = 1000;
	y = 1000;
	path = "./xpm_files/link_g1.xpm";
	root.game->pics->g1 = mlx_xpm_file_to_image(root.mlx, path, &x, &y);
	if (!root.game->pics->g1)
		launch_init(root);
	path = "./xpm_files/link_g2.xpm";
	root.game->pics->g2 = mlx_xpm_file_to_image(root.mlx, path, &x, &y);
	if (!root.game->pics->g2)
		launch_init(root);
	path = "./xpm_files/link_g3.xpm";
	root.game->pics->g3 = mlx_xpm_file_to_image(root.mlx, path, &x, &y);
	if (!root.game->pics->g3)
		launch_init(root);
	path = "./xpm_files/link_d1.xpm";
	root.game->pics->d1 = mlx_xpm_file_to_image(root.mlx, path, &x, &y);
	if (!root.game->pics->d1)
		launch_init(root);
}

void	get_char_pics_3(t_root root)
{
	char	*path;
	int		x;
	int		y;

	x = 1000;
	y = 1000;
	path = "./xpm_files/link_d2.xpm";
	root.game->pics->d2 = mlx_xpm_file_to_image(root.mlx, path, &x, &y);
	if (!root.game->pics->d2)
		launch_init(root);
	path = "./xpm_files/link_d3.xpm";
	root.game->pics->d3 = mlx_xpm_file_to_image(root.mlx, path, &x, &y);
	if (!root.game->pics->d3)
		launch_init(root);
	root.game->pics->current_char = root.game->pics->face1;
}
