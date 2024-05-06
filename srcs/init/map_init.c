/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:35:01 by tgeorge           #+#    #+#             */
/*   Updated: 2023/04/27 13:09:29 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	get_rectangle(t_root root)
{
	int		fd;
	int		j;
	char	*line;

	j = 0;
	fd = open(root.game->map_name, O_RDONLY);
	if (fd < 0)
		free_map(&root);
	line = get_next_line(fd);
	root.game->width = ft_strlen(line) - 1;
	while (line && line[0] != '\n' && ++j != -1)
	{
		free(line);
		line = get_next_line(fd);
	}
	root.game->height = j;
	end_gnl(fd, line);
	if (close(fd) == -1)
		free_map(&root);
	if ((root.game->height < 3 && root.game->width < 5)
		|| (root.game->height < 5 && root.game->width < 3))
	{
		ft_printf("Error\nMap invalide (trop petite)\n");
		free_map(&root);
	}
}

void	get_map(t_root root)
{
	int		fd;
	int		j;
	char	*line;

	root.game->map = malloc(sizeof(char *) * (root.game->height));
	if (!root.game->map)
		free_map(&root);
	fd = open(root.game->map_name, O_RDONLY);
	if (fd < 0)
		free_map(&root);
	j = 0;
	line = get_next_line(fd);
	while (j < root.game->height)
	{
		root.game->map[j] = line;
		root.game->map[j][ft_strlen(line)] = '\0';
		line = get_next_line(fd);
		j++;
	}
	end_gnl(fd, line);
	close(fd);
	if (fd == -1)
		free_map(&root);
}

int	check_char(char c)
{
	if (c != '0' && c != '1' && c != 'P' && c != 'E' && c != 'C'
		&& c != 10 && c != 0 && c != 'V' && c != 'H')
		return (1);
	return (0);
}

void	check_string(t_root root)
{
	int	i;
	int	j;

	j = 0;
	while (j < root.game->height)
	{
		i = 0;
		while (i < root.game->width)
		{
			if (check_char(root.game->map[j][i]) == 1)
			{
				error_call();
				ft_printf("Caractere non autorise sur la map.\n");
				free_map(&root);
			}
			i++;
		}
		j++;
	}
}

void	parsing_map(t_root root)
{
	get_map(root);
	check_string(root);
	get_player_pos(root);
	get_exit_pos(root);
	get_nb_coll(root);
	map_verif(root);
}
