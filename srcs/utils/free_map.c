/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:07:55 by tgeorge           #+#    #+#             */
/*   Updated: 2023/04/26 12:46:39 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_content_pics(t_root *root)
{
	if (root->game->pics->rubis1)
		mlx_destroy_image(root->mlx, root->game->pics->rubis1);
	if (root->game->pics->rubis2)
		mlx_destroy_image(root->mlx, root->game->pics->rubis2);
	if (root->game->pics->tree)
		mlx_destroy_image(root->mlx, root->game->pics->tree);
	if (root->game->pics->floor)
		mlx_destroy_image(root->mlx, root->game->pics->floor);
	if (root->game->pics->ladder)
		mlx_destroy_image(root->mlx, root->game->pics->ladder);
	if (root->game->pics->game_over)
		mlx_destroy_image(root->mlx, root->game->pics->game_over);
	if (root->game->pics->cac_back)
		mlx_destroy_image(root->mlx, root->game->pics->cac_back);
	if (root->game->pics->cac_d)
		mlx_destroy_image(root->mlx, root->game->pics->cac_d);
	if (root->game->pics->cac_g)
		mlx_destroy_image(root->mlx, root->game->pics->cac_g);
	if (root->game->pics->face1_cac)
		mlx_destroy_image(root->mlx, root->game->pics->face1_cac);
}

void	free_char_pics(t_root *root)
{
	if (root->game->pics->face1)
		mlx_destroy_image(root->mlx, root->game->pics->face1);
	if (root->game->pics->face2)
		mlx_destroy_image(root->mlx, root->game->pics->face2);
	if (root->game->pics->face3)
		mlx_destroy_image(root->mlx, root->game->pics->face3);
	if (root->game->pics->back)
		mlx_destroy_image(root->mlx, root->game->pics->back);
	if (root->game->pics->g1)
		mlx_destroy_image(root->mlx, root->game->pics->g1);
	if (root->game->pics->g2)
		mlx_destroy_image(root->mlx, root->game->pics->g2);
	if (root->game->pics->g3)
		mlx_destroy_image(root->mlx, root->game->pics->g3);
	if (root->game->pics->d1)
		mlx_destroy_image(root->mlx, root->game->pics->d1);
	if (root->game->pics->d2)
		mlx_destroy_image(root->mlx, root->game->pics->d2);
	if (root->game->pics->d3)
		mlx_destroy_image(root->mlx, root->game->pics->d3);
}

void	free_ennemies(t_root *root)
{
	int	i;

	if (root->game->v_ennemies)
	{
		i = root->game->nb_v_ennemies - 1;
		while (i >= 0)
		{
			if (root->game->v_ennemies[i])
				free(root->game->v_ennemies[i]);
			i--;
		}
		free(root->game->v_ennemies);
	}
	if (root->game->h_ennemies)
	{
		i = root->game->nb_h_ennemies - 1;
		while (i >= 0)
		{
			if (root->game->h_ennemies[i])
				free(root->game->h_ennemies[i]);
			i--;
		}
		free(root->game->h_ennemies);
	}
}

void	free_rest(t_root *root)
{
	free_content_pics(root);
	free_char_pics(root);
	if (root->game->anim)
		free(root->game->anim);
	if (root->game->pics)
		free(root->game->pics);
	free_ennemies(root);
	if (root->game)
		free(root->game);
	if (root->mlx_win)
		mlx_destroy_window(root->mlx, root->mlx_win);
	if (root->mlx)
	{
		mlx_destroy_display(root->mlx);
		free(root->mlx);
	}
}

void	free_map(t_root *root)
{
	int	i;

	i = -1;
	if (root->game->map)
	{
		while (++i < root->game->height)
		{
			if (root->game->map[i])
				free(root->game->map[i]);
		}
		free(root->game->map);
	}
	i = -1;
	if (root->game->flooded_map)
	{
		while (++i < root->game->height)
		{
			if (root->game->flooded_map[i])
				free(root->game->flooded_map[i]);
		}
		free(root->game->flooded_map);
	}
	free_rest(root);
	exit (0);
}
