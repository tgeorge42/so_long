/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_content_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:14:44 by tgeorge           #+#    #+#             */
/*   Updated: 2023/04/26 17:11:44 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	draw_vertical_ennemy(t_root root, int x_offset, int y_offset)
{
	int	i;

	i = 0;
	while (i < root.game->nb_v_ennemies)
	{
		if (root.game->v_ennemies[i][0] == x_offset
			&& root.game->v_ennemies[i][1] == y_offset)
			break ;
		i++;
	}
	if (root.game->v_ennemies[i][2] == 1)
		mlx_put_image_to_window(root.mlx, root.mlx_win,
			root.game->pics->face1_cac, x_offset * 60, y_offset * 60);
	else
		mlx_put_image_to_window(root.mlx, root.mlx_win,
			root.game->pics->cac_back, x_offset * 60, y_offset * 60);
}

void	draw_horizontal_ennemy(t_root root, int x_offset, int y_offset)
{
	int	i;

	i = 0;
	while (i < root.game->nb_h_ennemies)
	{
		if (root.game->h_ennemies[i][0] == x_offset
			&& root.game->h_ennemies[i][1] == y_offset)
			break ;
		i++;
	}
	if (root.game->h_ennemies[i][2] == -1)
		mlx_put_image_to_window(root.mlx, root.mlx_win,
			root.game->pics->cac_g, x_offset * 60, y_offset * 60);
	else
		mlx_put_image_to_window(root.mlx, root.mlx_win,
			root.game->pics->cac_d, x_offset * 60, y_offset * 60);
}

void	draw_text(t_root root)
{
	char	*str;

	str = ft_itoa(root.game->count_moves);
	mlx_string_put(root.mlx, root.mlx_win,
		(root.game->width) * 60 + 20,
		60,
		-1, "Nombre de moves :");
	if (root.game->count_coll < root.game->count_exit)
		mlx_string_put(root.mlx, root.mlx_win,
			(root.game->width + 1) * 60,
			100,
			-1, str);
	else if (root.game->count_exit == root.game->count_coll)
		mlx_string_put(root.mlx, root.mlx_win,
			(root.game->width + 1) * 60,
			100,
			15921152, str);
	free(str);
}
