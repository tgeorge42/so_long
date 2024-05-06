/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:11:33 by tgeorge           #+#    #+#             */
/*   Updated: 2023/04/26 12:32:41 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_game_over(t_root root)
{
	ft_printf("Total moves : %d\n", root.game->count_moves);
	root.game->end_game = 1;
	mlx_destroy_window(root.mlx, root.mlx_win);
	root.mlx_win = mlx_new_window(root.mlx, 1920, 1080, "so_long");
	ft_fullblack(root);
	draw_game_over(root, 0, 0);
	mlx_hook(root.mlx_win, 2, 1L << 0, key_press, &root);
	mlx_hook(root.mlx_win, 3, 1L << 1, key_release, &root);
	mlx_hook(root.mlx_win, 17, 1L << 17, &cross_kill, &root);
	mlx_loop(root.mlx);
}
