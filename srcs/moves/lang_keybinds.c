/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lang_keybinds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:27:29 by tgeorge           #+#    #+#             */
/*   Updated: 2024/05/06 17:37:31 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	en_key_press(int keycode, t_root *root)
{
	if (keycode == 119 || keycode == 115
		|| keycode == 97 || keycode == 100)
		reset_orientation(*root);
	if (keycode == 119)
		root->game->player_up = 1;
	if (keycode == 115)
		root->game->player_down = 1;
	if (keycode == 97)
		root->game->player_left = 1;
	if (keycode == 100)
		root->game->player_right = 1;
}

void	en_key_release(int keycode, t_root *root)
{
	if (keycode == 119 && root->game->player_up == 1)
		any_move(*root, 0, -1);
	if (keycode == 115 && root->game->player_down == 1)
		any_move(*root, 0, 1);
	if (keycode == 97 && root->game->player_left == 1)
		any_move(*root, -1, 0);
	if (keycode == 100 && root->game->player_right == 1)
		any_move(*root, 1, 0);
}

void	fr_key_press(int keycode, t_root *root)
{
	if (keycode == 122 || keycode == 115
		|| keycode == 113 || keycode == 100)
		reset_orientation(*root);
	if (keycode == 122)
		root->game->player_up = 1;
	if (keycode == 115)
		root->game->player_down = 1;
	if (keycode == 113)
		root->game->player_left = 1;
	if (keycode == 100)
		root->game->player_right = 1;
}

void	fr_key_release(int keycode, t_root *root)
{
	if (keycode == 122 && root->game->player_up == 1)
		any_move(*root, 0, -1);
	if (keycode == 115 && root->game->player_down == 1)
		any_move(*root, 0, 1);
	if (keycode == 113 && root->game->player_left == 1)
		any_move(*root, -1, 0);
	if (keycode == 100 && root->game->player_right == 1)
		any_move(*root, 1, 0);
}