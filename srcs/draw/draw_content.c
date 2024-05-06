/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:30:38 by tgeorge           #+#    #+#             */
/*   Updated: 2023/11/28 03:54:16 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	draw_rubis(t_root root, int x_offset, int y_offset)
{
	if (root.game->framecount < root.game->anim->coll_frame)
		mlx_put_image_to_window(root.mlx, root.mlx_win,
			root.game->pics->rubis1, x_offset, y_offset);
	else
		mlx_put_image_to_window(root.mlx, root.mlx_win,
			root.game->pics->rubis2, x_offset, y_offset);
}

void	draw_floor1(t_root root, int x_offset, int y_offset)
{
	mlx_put_image_to_window(root.mlx, root.mlx_win,
		root.game->pics->floor, x_offset, y_offset);
}

void	draw_tree(t_root root, int x_offset, int y_offset)
{
	mlx_put_image_to_window(root.mlx, root.mlx_win,
		root.game->pics->tree, x_offset, y_offset);
}

void	draw_ladder(t_root root, int x_offset, int y_offset)
{
	mlx_put_image_to_window(root.mlx, root.mlx_win,
		root.game->pics->ladder, x_offset, y_offset);
}

void	draw_game_over(t_root root, int x_offset, int y_offset)
{
	mlx_put_image_to_window(root.mlx, root.mlx_win,
		root.game->pics->game_over, x_offset, y_offset);
}
