/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:35:14 by tgeorge           #+#    #+#             */
/*   Updated: 2023/04/24 16:53:31 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	setup_v_ennemies(t_root root)
{
	int	i;

	count_v_ennemies(root);
	i = 0;
	root.game->v_ennemies = malloc(sizeof(char *) * (root.game->nb_v_ennemies));
	if (!root.game->v_ennemies)
		free_map(&root);
	while (i < root.game->nb_v_ennemies)
	{
		root.game->v_ennemies[i] = malloc(sizeof(int) * 3);
		if (!root.game->v_ennemies[i])
			free_map(&root);
		i++;
	}
	set_v_ennemies_location(root);
}

void	setup_h_ennemies(t_root root)
{
	int	i;

	count_h_ennemies(root);
	i = 0;
	root.game->h_ennemies = malloc(sizeof(char *) * (root.game->nb_h_ennemies));
	if (!root.game->h_ennemies)
		free_map(&root);
	while (i < root.game->nb_h_ennemies)
	{
		root.game->h_ennemies[i] = malloc(sizeof(int) * 3);
		if (!root.game->h_ennemies[i])
			free_map(&root);
		i++;
	}
	set_h_ennemies_location(root);
}

void	setup_ennemies(t_root root)
{
	setup_v_ennemies(root);
	setup_h_ennemies(root);
}

void	is_valid(t_root root)
{
	get_flooded_map(root);
	ft_preflood_player(root);
	ft_flood_all(root);
	ft_valid_flood(root);
}

void	map_verif(t_root root)
{
	is_rectangle(root);
	only_walls(root);
	is_valid(root);
	setup_ennemies(root);
}
