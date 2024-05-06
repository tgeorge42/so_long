/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:49:12 by tgeorge           #+#    #+#             */
/*   Updated: 2023/04/26 17:38:35 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	name_verif(char *name)
{
	int	i;

	if (ft_strlen(name) < 5)
		return (1);
	i = ft_strlen(name);
	if (name[i - 1] != 'r' || name[i - 2] != 'e'
		|| name[i - 3] != 'b' || name[i - 4] != '.')
		return (1);
	return (0);
}

void	is_rectangle(t_root root)
{
	int	i;

	i = 0;
	while (i < root.game->height)
	{
		if ((int)ft_strlen(root.game->map[i]) != root.game->width + 1)
		{
			error_call();
			ft_printf("La map n'est pas rectangle\n");
			free_map(&root);
		}
		i++;
	}
}

void	only_walls_2(t_root root, int j)
{
	if (root.game->map[j][0] != '1'
		|| root.game->map[j][root.game->width - 1] != '1')
	{
		error_call();
		ft_printf("Pas que des murs\n");
		free_map(&root);
	}
}

void	only_walls(t_root root)
{
	int	i;
	int	j;

	j = 0;
	while (j < root.game->height)
	{
		i = 0;
		if (j == 0 || j == root.game->height - 1)
		{
			while (root.game->map[j][i] != '\n')
			{
				if (root.game->map[j][i] != '1')
				{
					ft_printf("Error\nPas que des murs\n");
					free_map(&root);
				}
				i++;
			}
		}
		else
		{
			only_walls_2(root, j);
		}
		j++;
	}			
}
