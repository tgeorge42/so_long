/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pictures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:05:25 by tgeorge           #+#    #+#             */
/*   Updated: 2023/04/24 17:10:18 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	launch_init(t_root root)
{
	free_map(&root);
}

void	get_pics(t_root root)
{
	get_content_pics_1(root);
	get_content_pics_2(root);
	get_ennemy_pics(root);
	get_char_pics_1(root);
	get_char_pics_2(root);
	get_char_pics_3(root);
}
