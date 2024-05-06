/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:28:39 by tgeorge           #+#    #+#             */
/*   Updated: 2024/05/06 17:38:11 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	reset_orientation(t_root root)
{
	root.game->player_up = 0;
	root.game->player_down = 0;
	root.game->player_left = 0;
	root.game->player_right = 0;
}

int	key_press(int keycode, t_root *root)
{
	if (root->game->end_game == 0)
	{
		if (strncmp(root->game->lang, "en", 2) == 0)
			en_key_press(keycode, root);
		else
			fr_key_press(keycode, root);
	}
	if (keycode == 65307)
		winclose(keycode, root);
	return (0);
}

int	key_release(int keycode, t_root *root)
{
	if (root->game->end_game == 0)
	{
		if (strncmp(root->game->lang, "en", 2) == 0)
			en_key_release(keycode, root);
		else
			fr_key_release(keycode, root);
	}
	return (0);
}

int	cross_kill(t_root *root)
{
	free_map(root);
	exit (0);
}
