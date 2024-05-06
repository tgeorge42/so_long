/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_ennemies.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:53:08 by tgeorge           #+#    #+#             */
/*   Updated: 2023/04/26 12:18:01 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	count_v_ennemies(t_root root)
{
	int	i;
	int	j;

	j = 0;
	while (j <= root.game->height - 1)
	{
		i = 0;
		while (i <= root.game->width)
		{
			if (root.game->map[j][i] == 'V')
				root.game->nb_v_ennemies++;
			i++;
		}
		j++;
	}
}

void	set_v_ennemies_location(t_root root)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	j = 0;
	while (j <= root.game->height - 1)
	{
		i = 0;
		while (i <= root.game->width)
		{
			if (root.game->map[j][i] == 'V')
			{
				root.game->v_ennemies[k][0] = i;
				root.game->v_ennemies[k][1] = j;
				root.game->v_ennemies[k][2] = -1;
				k++;
			}
			i++;
		}
		j++;
	}
}

void	count_h_ennemies(t_root root)
{
	int	i;
	int	j;

	j = 0;
	while (j <= root.game->height - 1)
	{
		i = 0;
		while (i <= root.game->width)
		{
			if (root.game->map[j][i] == 'H')
				root.game->nb_h_ennemies++;
			i++;
		}
		j++;
	}
}

void	set_h_ennemies_location(t_root root)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	j = 0;
	while (j <= root.game->height - 1)
	{
		i = 0;
		while (i <= root.game->width)
		{
			if (root.game->map[j][i] == 'H')
			{
				root.game->h_ennemies[k][0] = i;
				root.game->h_ennemies[k][1] = j;
				root.game->h_ennemies[k][2] = 1;
				k++;
			}
			i++;
		}
		j++;
	}
}
