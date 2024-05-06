/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:04:13 by tgeorge           #+#    #+#             */
/*   Updated: 2024/05/06 16:55:06 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_call(void)
{
	ft_printf("Error\n");
}

int	winclose(int keycode, t_root *root)
{
	(void)keycode;
	free_map(root);
	exit (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	launch_game(t_root *root, char *av, char **env)
{
	root_init(root, av, env);
	get_rectangle(*root);
	parsing_map(*root);
}

int	main(int ac, char **av, char **env)
{
	t_root	root;

	if (ac == 2 && name_verif(av[1]) == 0)
	{
		root.mlx = mlx_init();
		if (!root.mlx)
			exit (0);
		launch_game(&root, av[1], env);
		root.mlx_win = mlx_new_window(root.mlx,
				60 * (root.game->width + 2) + 30,
				60 * (root.game->height), "so_long");
		draw_map(root);
		draw_text(root);
		mlx_loop_hook(root.mlx, animations, &root);
		mlx_hook(root.mlx_win, 2, 1L << 0, key_press, &root);
		mlx_hook(root.mlx_win, 3, 1L << 1, key_release, &root);
		mlx_hook(root.mlx_win, 17, 1L << 17, &cross_kill, &root);
		mlx_loop(root.mlx);
	}
	else
		ft_printf("Rentrer un nom de map valide (ex : map1.ber)\n");
}
