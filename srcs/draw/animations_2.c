/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:13:25 by tgeorge           #+#    #+#             */
/*   Updated: 2023/04/26 14:14:28 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ennemy_move_left_or_right(t_root *root, int j)
{
	if (root->game->h_ennemies[j][2] == -1)
	{
		root->game->map[root->game->h_ennemies[j][1]]
		[root->game->h_ennemies[j][0]] = '0';
		root->game->map[root->game->h_ennemies[j][1]]
		[root->game->h_ennemies[j][0] - 1] = 'H';
		root->game->h_ennemies[j][0] -= 1;
	}
	else
	{
		root->game->map[root->game->h_ennemies[j][1]]
		[root->game->h_ennemies[j][0]] = '0';
		root->game->map[root->game->h_ennemies[j][1]]
		[root->game->h_ennemies[j][0] + 1] = 'H';
		root->game->h_ennemies[j][0] += 1;
	}
}

void	horizontal_ennemy_move_2(t_root *root, int j)
{
	if (root->game->map[root->game->h_ennemies[j][1]]
	[root->game->h_ennemies[j][0] + 1] == '0')
		ennemy_move_left_or_right(root, j);
	else if (root->game->map[root->game->h_ennemies[j][1]]
	[root->game->h_ennemies[j][0] + 1] == 'P')
		ft_game_over(*root);
	else
	{
		root->game->h_ennemies[j][2] = -1;
		if (root->game->map[root->game->h_ennemies[j][1]]
		[root->game->h_ennemies[j][0] - 1] == 'P')
			ft_game_over(*root);
		else
			ennemy_move_left_or_right(root, j);
	}
}

void	horizontal_ennemy_move(t_root *root, int j)
{
	if (root->game->h_ennemies[j][2] == -1)
	{
		if (root->game->map[root->game->h_ennemies[j][1]]
		[root->game->h_ennemies[j][0] - 1] == '0')
			ennemy_move_left_or_right(root, j);
		else if (root->game->map[root->game->h_ennemies[j][1]]
		[root->game->h_ennemies[j][0] - 1] == 'P')
			ft_game_over(*root);
		else
		{
			root->game->h_ennemies[j][2] = 1;
			if (root->game->map[root->game->h_ennemies[j][1]]
			[root->game->h_ennemies[j][0] + 1] == 'P')
				ft_game_over(*root);
			else
				ennemy_move_left_or_right(root, j);
		}
	}
	else
		horizontal_ennemy_move_2(root, j);
}

void	horizontal_ennemy_pattern(t_root *root)
{
	int	j;

	j = 0;
	while (j < root->game->nb_h_ennemies)
	{
		horizontal_ennemy_move(root, j);
		j++;
	}
}

int	player_animation(t_root *root)
{
	if (root->game->framecount <= root->game->anim->player_frame * 3)
		draw_link(*root, root->game->player.x * 60, root->game->player.y * 60);
	else
		root->game->framecount = 0;
	root->game->framecount++;
	return (1);
}
