/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:58:23 by tgeorge           #+#    #+#             */
/*   Updated: 2023/04/26 12:13:03 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	draw_link_back(t_root root, int x_offset, int y_offset)
{
	mlx_put_image_to_window(root.mlx, root.mlx_win,
		root.game->pics->back, x_offset, y_offset);
}

void	draw_link_left(t_root root, int x_offset, int y_offset)
{
	if (root.game->framecount < root.game->anim->player_frame)
		mlx_put_image_to_window(root.mlx, root.mlx_win,
			root.game->pics->g1, x_offset, y_offset);
	else if (root.game->framecount <= root.game->anim->player_frame * 2)
		mlx_put_image_to_window(root.mlx, root.mlx_win,
			root.game->pics->g2, x_offset, y_offset);
	else
		mlx_put_image_to_window(root.mlx, root.mlx_win,
			root.game->pics->g3, x_offset, y_offset);
}

void	draw_link_right(t_root root, int x_offset, int y_offset)
{
	if (root.game->framecount < root.game->anim->player_frame)
		mlx_put_image_to_window(root.mlx, root.mlx_win,
			root.game->pics->d1, x_offset, y_offset);
	else if (root.game->framecount <= root.game->anim->player_frame * 2)
		mlx_put_image_to_window(root.mlx, root.mlx_win,
			root.game->pics->d2, x_offset, y_offset);
	else
		mlx_put_image_to_window(root.mlx, root.mlx_win,
			root.game->pics->d3, x_offset, y_offset);
}

void	draw_link_face(t_root root, int x_offset, int y_offset)
{
	if (root.game->framecount < root.game->anim->player_frame)
		mlx_put_image_to_window(root.mlx, root.mlx_win,
			root.game->pics->face1, x_offset, y_offset);
	else if (root.game->framecount <= root.game->anim->player_frame * 2)
		mlx_put_image_to_window(root.mlx, root.mlx_win,
			root.game->pics->face2, x_offset, y_offset);
	else
		mlx_put_image_to_window(root.mlx, root.mlx_win,
			root.game->pics->face3, x_offset, y_offset);
}

void	draw_link(t_root root, int x_offset, int y_offset)
{
	if (root.game->player_down == 1)
		draw_link_face(root, x_offset, y_offset);
	else if (root.game->player_up == 1)
		draw_link_back(root, x_offset, y_offset);
	else if (root.game->player_left == 1)
		draw_link_left(root, x_offset, y_offset);
	else if (root.game->player_right == 1)
		draw_link_right(root, x_offset, y_offset);
}
