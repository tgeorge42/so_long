/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:07:22 by tgeorge           #+#    #+#             */
/*   Updated: 2023/04/24 17:09:23 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	get_player_pos(t_root root)
{
	int		i;
	int		j;
	int		nb_player;

	j = -1;
	nb_player = 0;
	while (++j < root.game->height)
	{
		i = -1;
		while (++i < root.game->width)
		{
			if (root.game->map[j][i] == 'P')
			{
				nb_player += 1;
				root.game->player.x = i;
				root.game->player.y = j;
			}
		}
	}
	if (nb_player != 1)
	{
		ft_printf("Error\nPas ou trop de personnage(s)");
		free_map(&root);
	}
}

void	get_exit_pos(t_root root)
{
	int		i;
	int		j;
	int		nb_exit;

	nb_exit = 0;
	j = -1;
	while (++j < root.game->height)
	{
		i = -1;
		while (++i < root.game->width)
		{
			if (root.game->map[j][i] == 'E')
			{
				nb_exit += 1;
				root.game->exit.x = i;
				root.game->exit.y = j;
			}
		}
	}
	if (nb_exit != 1)
	{
		ft_printf("Error\nPas ou trop de sortie(s)");
		free_map(&root);
	}
}

void	get_nb_coll(t_root root)
{
	int		i;
	int		j;

	j = 0;
	while (j < root.game->height)
	{
		i = 0;
		while (i < root.game->width)
		{
			if (root.game->map[j][i] == 'C')
				root.game->count_exit += 1;
			i++;
		}
		j++;
	}
	if (root.game->count_exit < 1)
	{
		error_call();
		ft_printf("Pas assez d'items");
		free_map(&root);
	}
}
