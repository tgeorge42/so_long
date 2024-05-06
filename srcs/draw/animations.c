/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:30:12 by tgeorge           #+#    #+#             */
/*   Updated: 2023/04/26 14:14:22 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ennemy_move_up_or_down(t_root *root, int j)
{
	if (root->game->v_ennemies[j][2] == -1)
	{
		root->game->map[root->game->v_ennemies[j][1]]
		[root->game->v_ennemies[j][0]] = '0';
		root->game->map[root->game->v_ennemies[j][1] - 1]
		[root->game->v_ennemies[j][0]] = 'V';
		root->game->v_ennemies[j][1] -= 1;
	}
	else
	{
		root->game->map[root->game->v_ennemies[j][1]]
		[root->game->v_ennemies[j][0]] = '0';
		root->game->map[root->game->v_ennemies[j][1] + 1]
		[root->game->v_ennemies[j][0]] = 'V';
		root->game->v_ennemies[j][1] += 1;
	}
}

void	vertical_ennemy_move_2(t_root *root, int j)
{
	if (root->game->map[root->game->v_ennemies[j][1] + 1]
	[root->game->v_ennemies[j][0]] == '0')
		ennemy_move_up_or_down(root, j);
	else if (root->game->map[root->game->v_ennemies[j][1] + 1]
	[root->game->v_ennemies[j][0]] == 'P')
		ft_game_over(*root);
	else
	{
		root->game->v_ennemies[j][2] = -1;
		if (root->game->map[root->game->v_ennemies[j][1] - 1]
		[root->game->v_ennemies[j][0]] == 'P')
			ft_game_over(*root);
		else
			ennemy_move_up_or_down(root, j);
	}
}

void	vertical_ennemy_move(t_root *root, int j)
{
	if (root->game->v_ennemies[j][2] == -1)
	{
		if (root->game->map[root->game->v_ennemies[j][1] - 1]
		[root->game->v_ennemies[j][0]] == '0')
			ennemy_move_up_or_down(root, j);
		else if (root->game->map[root->game->v_ennemies[j][1] - 1]
		[root->game->v_ennemies[j][0]] == 'P')
			ft_game_over(*root);
		else
		{
			root->game->v_ennemies[j][2] = 1;
			if (root->game->map[root->game->v_ennemies[j][1] + 1]
			[root->game->v_ennemies[j][0]] == 'P')
				ft_game_over(*root);
			else
				ennemy_move_up_or_down(root, j);
		}
	}
	else
		vertical_ennemy_move_2(root, j);
}

void	vertical_ennemy_pattern(t_root *root)
{
	int	j;

	j = 0;
	while (j < root->game->nb_v_ennemies)
	{
		vertical_ennemy_move(root, j);
		j++;
	}
}

int	animations(t_root *root)
{
	if (root->game->end_game == 0)
	{
		player_animation(root);
		if (root->game->framecount == root->game->anim->cac_frame)
		{
			vertical_ennemy_pattern(root);
			horizontal_ennemy_pattern(root);
		}
		re_draw(*root);
		clear_number(*root);
		draw_text(*root);
	}
	return (1);
}
