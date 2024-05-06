/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lang.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:08:00 by tgeorge           #+#    #+#             */
/*   Updated: 2024/05/06 17:23:42 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	get_lang(t_root *root, char **env, int i, int j)
{
	int	k;
	int	l;

	k = j;
	l = 0;
	while (env[i][k] && env[i][k] != '=')
		k++;
	root->game->lang = malloc(sizeof(char) * (k - j + 2));
	while (env[i][j])
	{
		root->game->lang[l] = env[i][j];
		j++;
		l++;
	}
	root->game->lang[l] = '\0';
	if (ft_strlen(root->game->lang) == 0)
		return (0);
	return (1);
}

int	ft_check_lang(t_root *root, char **env)
{
	int	i;
	int	j;

	i = 0;
	while (env[i])
	{
		if (strncmp(env[i], "LANG", 4) == 0)
			break ;
		i++;
	}
	if (env[i])
	{
		i = 0;
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		j++;
	}
	return (get_lang(root, env, i, j));
}

void	init_lang(t_root *root, char **env)
{
	root->game->lang = NULL;
	if (env)
		ft_check_lang(root, env);
}
