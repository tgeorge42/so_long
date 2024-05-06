/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preflood.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:48:43 by tgeorge           #+#    #+#             */
/*   Updated: 2023/04/26 12:34:28 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_exit_preflood(t_root root, int i, int j)
{
	if (root.game->flooded_map[j][i - 1] == 'E')
		root.game->count_flood_exit += 1;
	if (root.game->flooded_map[j][i + 1] == 'E')
		root.game->count_flood_exit += 1;
	if (root.game->flooded_map[j - 1][i] == 'E')
		root.game->count_flood_exit += 1;
	if (root.game->flooded_map[j + 1][i] == 'E')
		root.game->count_flood_exit += 1;
}

void	ft_coll_preflood(t_root root, int i, int j)
{
	if (root.game->flooded_map[j][i - 1] == 'C')
	{
		root.game->flooded_map[j][i - 1] = '2';
		root.game->count_flood_coll += 1;
	}
	if (root.game->flooded_map[j][i + 1] == 'C')
	{
		root.game->flooded_map[j][i + 1] = '2';
		root.game->count_flood_coll += 1;
	}
	if (root.game->flooded_map[j - 1][i] == 'C')
	{
		root.game->flooded_map[j - 1][i] = '2';
		root.game->count_flood_coll += 1;
	}
	if (root.game->flooded_map[j + 1][i] == 'C')
	{
		root.game->flooded_map[j + 1][i] = '2';
		root.game->count_flood_coll += 1;
	}
}

void	ft_preflood(t_root root, int i, int j)
{
	if (root.game->flooded_map[j][i - 1] == '0')
		root.game->flooded_map[j][i - 1] = '2';
	if (root.game->flooded_map[j][i + 1] == '0')
		root.game->flooded_map[j][i + 1] = '2';
	if (root.game->flooded_map[j - 1][i] == '0')
		root.game->flooded_map[j - 1][i] = '2';
	if (root.game->flooded_map[j + 1][i] == '0')
		root.game->flooded_map[j + 1][i] = '2';
	ft_coll_preflood(root, i, j);
	ft_exit_preflood(root, i, j);
	if (has_a_2(root) == 0)
	{
		error_call();
		ft_printf("Map infaisable : Sortie inatteignable\n");
		free_map(&root);
	}
}

void	ft_preflood_player(t_root root)
{
	int	i;
	int	j;

	j = 0;
	while (j <= root.game->height - 1)
	{
		i = 0;
		while (i <= root.game->width)
		{
			if (root.game->flooded_map[j][i] == 'P')
			{
				ft_preflood(root, i, j);
				break ;
			}
			i++;
		}
		j++;
	}
}
