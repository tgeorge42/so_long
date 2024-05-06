/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_other_pictures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:09:36 by tgeorge           #+#    #+#             */
/*   Updated: 2023/04/24 14:10:21 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	get_content_pics_1(t_root root)
{
	char	*path;
	int		x;
	int		y;

	x = 1000;
	y = 1000;
	path = "./xpm_files/rubis_floor1.xpm";
	root.game->pics->rubis1 = mlx_xpm_file_to_image(root.mlx, path, &x, &y);
	if (!root.game->pics->rubis1)
		launch_init(root);
	path = "./xpm_files/rubis_floor2.xpm";
	root.game->pics->rubis2 = mlx_xpm_file_to_image(root.mlx, path, &x, &y);
	if (!root.game->pics->rubis2)
		launch_init(root);
	path = "./xpm_files/floor1.xpm";
	root.game->pics->floor = mlx_xpm_file_to_image(root.mlx, path, &x, &y);
	if (!root.game->pics->floor)
		launch_init(root);
}

void	get_content_pics_2(t_root root)
{
	char	*path;
	int		x;
	int		y;

	x = 1000;
	y = 1000;
	path = "./xpm_files/border_tree_floor1.xpm";
	root.game->pics->tree = mlx_xpm_file_to_image(root.mlx, path, &x, &y);
	if (!root.game->pics->tree)
		launch_init(root);
	path = "./xpm_files/ladder.xpm";
	root.game->pics->ladder = mlx_xpm_file_to_image(root.mlx, path, &x, &y);
	if (!root.game->pics->ladder)
		launch_init(root);
	path = "./xpm_files/game_over.xpm";
	root.game->pics->game_over = mlx_xpm_file_to_image(root.mlx, path, &x, &y);
	if (!root.game->pics->game_over)
		launch_init(root);
}

void	get_ennemy_pics(t_root root)
{
	char	*path;
	int		x;
	int		y;

	x = 1000;
	y = 1000;
	path = "./xpm_files/face1_cac.xpm";
	root.game->pics->face1_cac = mlx_xpm_file_to_image(root.mlx, path, &x, &y);
	if (!root.game->pics->face1_cac)
		launch_init(root);
	path = "./xpm_files/cac_back.xpm";
	root.game->pics->cac_back = mlx_xpm_file_to_image(root.mlx, path, &x, &y);
	if (!root.game->pics->cac_back)
		launch_init(root);
	path = "./xpm_files/cac_d.xpm";
	root.game->pics->cac_d = mlx_xpm_file_to_image(root.mlx, path, &x, &y);
	if (!root.game->pics->cac_d)
		launch_init(root);
	path = "./xpm_files/cac_g.xpm";
	root.game->pics->cac_g = mlx_xpm_file_to_image(root.mlx, path, &x, &y);
	if (!root.game->pics->cac_g)
		launch_init(root);
}
