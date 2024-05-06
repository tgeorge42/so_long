/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:13:49 by tgeorge           #+#    #+#             */
/*   Updated: 2023/04/27 13:09:37 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	end_gnl(int fd, char *line)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

void	get_flooded_map(t_root root)
{
	int		fd;
	int		j;
	char	*line;

	root.game->flooded_map = malloc(sizeof(char *) * (root.game->height));
	if (!root.game->flooded_map)
		free_map(&root);
	fd = open(root.game->map_name, O_RDONLY);
	if (fd < 0)
		free_map(&root);
	j = 0;
	line = get_next_line(fd);
	while (j < root.game->height)
	{
		root.game->flooded_map[j] = line;
		root.game->flooded_map[j][ft_strlen(line)] = '\0';
		line = get_next_line(fd);
		j++;
	}
	end_gnl(fd, line);
	close(fd);
	if (fd == -1)
		free_map(&root);
}

void	ft_valid_flood(t_root root)
{
	if (root.game->count_flood_coll != root.game->count_exit)
	{
		error_call();
		ft_printf("Map infaisable : Certains objets inatteignables\n");
		free_map(&root);
	}
	if (root.game->count_flood_exit == 0)
	{
		error_call();
		ft_printf("Map infaisable : Sortie inatteignable\n");
		free_map(&root);
	}
}
