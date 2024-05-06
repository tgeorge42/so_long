/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:21:20 by tgeorge           #+#    #+#             */
/*   Updated: 2023/04/26 16:15:46 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	floor_or_coll_move(t_root root, int x, int y)
{
	if (root.game->map[root.game->player.y + y]
		[root.game->player.x + x] == 'C')
		root.game->count_coll += 1;
	root.game->map[root.game->player.y][root.game->player.x] = '0';
	root.game->map[root.game->player.y + y]
	[root.game->player.x + x] = 'P';
	root.game->player.x += x;
	root.game->player.y += y;
	root.game->count_moves += 1;
	re_draw(root);
	clear_number(root);
	draw_text(root);
	ft_printf("Move count : %d\r", root.game->count_moves);
}

void	win_move(t_root root, int x, int y)
{
	root.game->map[root.game->player.y][root.game->player.x] = '0';
	root.game->map[root.game->player.y + y]
	[root.game->player.x + x] = 'P';
	root.game->player.x += x;
	root.game->player.y += y;
	root.game->count_moves += 1;
	root.game->end_game = 1;
	ft_printf("Total moves : %d\n", root.game->count_moves);
	mlx_destroy_window(root.mlx, root.mlx_win);
	root.mlx_win = mlx_new_window(root.mlx, 1920, 1080, "so_long");
	ft_fullblack(root);
	root.game->anim->player_frame = 900;
	reset_orientation(root);
	root.game->player_down = 1;
	mlx_loop_hook(root.mlx, gg_animation, &root);
	mlx_hook(root.mlx_win, 2, 1L << 0, key_press, &root);
	mlx_hook(root.mlx_win, 3, 1L << 1, key_release, &root);
	mlx_hook(root.mlx_win, 17, 1L << 17, &cross_kill, &root);
	mlx_loop(root.mlx);
}

void	any_move(t_root root, int x, int y)
{
	if (!(root.game->player.x == root.game->exit.x
			&& root.game->player.y == root.game->exit.y))
	{
		if (root.game->map[root.game->player.y + y]
			[root.game->player.x + x] == '0'
			|| root.game->map[root.game->player.y + y]
			[root.game->player.x + x] == 'C')
		{
			floor_or_coll_move(root, x, y);
		}
		else if (root.game->map[root.game->player.y + y]
			[root.game->player.x + x] == 'V'
			|| root.game->map[root.game->player.y + y]
			[root.game->player.x + x] == 'H')
			ft_game_over(root);
		else if (root.game->map[root.game->player.y + y]
			[root.game->player.x + x] == 'E'
			&& root.game->count_exit == root.game->count_coll)
		{
			win_move(root, x, y);
		}
	}
}
