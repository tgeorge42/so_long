/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   root_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:44:31 by tgeorge           #+#    #+#             */
/*   Updated: 2024/05/06 17:08:16 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	pictures_first_init(t_root root)
{
	root.game->pics->game_over = NULL;
	root.game->pics->ladder = NULL;
	root.game->pics->tree = NULL;
	root.game->pics->floor = NULL;
	root.game->pics->rubis2 = NULL;
	root.game->pics->rubis1 = NULL;
	root.game->pics->face1_cac = NULL;
	root.game->pics->cac_back = NULL;
	root.game->pics->cac_d = NULL;
	root.game->pics->cac_g = NULL;
	root.game->pics->face1 = NULL;
	root.game->pics->face2 = NULL;
	root.game->pics->face3 = NULL;
	root.game->pics->back = NULL;
	root.game->pics->d1 = NULL;
	root.game->pics->d2 = NULL;
	root.game->pics->d3 = NULL;
	root.game->pics->g1 = NULL;
	root.game->pics->g2 = NULL;
	root.game->pics->g3 = NULL;
}

void	init_var(t_root *root, char *map, char **env)
{
	root->game->v_ennemies = NULL;
	root->game->h_ennemies = NULL;
	root->mlx_win = NULL;
	root->game->map = NULL;
	root->game->flooded_map = NULL;
	root->game->map_name = map;
	root->game->player_up = 0;
	root->game->player_down = 1;
	root->game->player_left = 0;
	root->game->player_right = 0;
	root->game->count_moves = 0;
	root->game->count_exit = 0;
	root->game->count_coll = 0;
	root->game->count_flood_coll = 0;
	root->game->count_flood_exit = 0;
	root->game->anim->player_frame = 300;
	root->game->anim->coll_frame = 450;
	root->game->anim->cac_frame = 600;
	root->game->framecount = 0;
	root->game->nb_v_ennemies = 0;
	root->game->nb_h_ennemies = 0;
	root->game->end_game = 0;
	root->game->height = 1;
	root->game->width = 1;
	init_lang(root, env);
}

void	root_init(t_root *root, char *map, char **env)
{
	root->game = malloc(sizeof(t_game) * 1);
	if (!root->game)
		free_map(root);
	root->game->anim = malloc(sizeof(t_anim) * 1);
	if (!root->game->anim)
		free_map(root);
	root->game->pics = malloc(sizeof(t_pictures) * 1);
	if (!root->game->pics)
		free_map(root);
	init_var(root, map, env);
	pictures_first_init(*root);
	get_pics(*root);
}
