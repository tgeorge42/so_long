/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:52:28 by tgeorge           #+#    #+#             */
/*   Updated: 2023/04/26 12:35:47 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_exit_flood(t_root root, int i, int j)
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

void	ft_coll_flood(t_root root, int i, int j)
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

void	ft_flood(t_root root, int i, int j)
{
	if (root.game->flooded_map[j][i - 1] == '0')
		root.game->flooded_map[j][i - 1] = '2';
	if (root.game->flooded_map[j][i + 1] == '0')
		root.game->flooded_map[j][i + 1] = '2';
	if (root.game->flooded_map[j - 1][i] == '0')
		root.game->flooded_map[j - 1][i] = '2';
	if (root.game->flooded_map[j + 1][i] == '0')
		root.game->flooded_map[j + 1][i] = '2';
	root.game->flooded_map[j][i] = '3';
	ft_coll_flood(root, i, j);
	ft_exit_flood(root, i, j);
}

int	has_a_2(t_root root)
{
	int	i;
	int	j;

	j = 0;
	while (j <= root.game->height - 1)
	{
		i = 0;
		while (i <= root.game->width)
		{
			if (root.game->flooded_map[j][i] == '2')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

void	ft_flood_all(t_root root)
{
	int	i;
	int	j;

	while (has_a_2(root) == 1)
	{
		j = 0;
		while (j <= root.game->height - 1)
		{
			i = 0;
			while (i <= root.game->width)
			{
				if (root.game->flooded_map[j][i] == '2')
				{
					ft_flood(root, i, j);
				}
				i++;
			}
			j++;
		}
	}
}
