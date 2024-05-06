/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:55:28 by tgeorge           #+#    #+#             */
/*   Updated: 2024/05/06 17:36:43 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <mlx_int.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_coord
{
	int				x;
	int				y;
}				t_coord;

typedef struct s_anim
{
	int				x;
	int				y;
	int				player_frame;
	int				coll_frame;
	int				cac_frame;
}				t_anim;

typedef struct s_pictures
{
	void	*current_char;
	void	*face1;
	void	*face2;
	void	*face3;
	void	*back;
	void	*g1;
	void	*g2;
	void	*g3;
	void	*d1;
	void	*d2;
	void	*d3;
	void	*rubis1;
	void	*rubis2;
	void	*floor;
	void	*tree;
	void	*ladder;
	void	*face1_cac;
	void	*cac_back;
	void	*cac_g;
	void	*cac_d;
	void	*game_over;
}				t_pictures;

typedef struct s_game
{
	char			*lang;
	char			**map;
	char			*map_name;
	char			**flooded_map;
	int				height;
	int				width;
	int				nb_v_ennemies;
	int				**v_ennemies;
	int				nb_h_ennemies;
	int				**h_ennemies;
	t_coord			player;
	t_anim			*anim;
	t_pictures		*pics;
	int				player_frame;
	int				framecount;
	int				player_up;
	int				player_down;
	int				player_left;
	int				player_right;
	int				player_move;
	int				player_coll;
	t_coord			exit;
	t_coord			*coll;
	int				count_coll;
	int				count_flood_coll;
	int				count_exit;
	int				count_flood_exit;
	int				count_moves;
	int				end_game;
}				t_game;

typedef struct s_root
{
	void			*mlx;
	void			*mlx_win;
	t_game			*game;

}				t_root;

char	*ft_itoa(int n);
void	draw_text(t_root root);

void	error_call();
void	free_map(t_root *root);
void	end_gnl(int fd, char *line);
int		winclose(int keycode, t_root *root);
int		cross_kill(t_root *root);
int		key_press(int keycode, t_root *root);
int		key_release(int keycode, t_root *root);

void	ft_fullblack(t_root root);
int		gg_animation(t_root *root);
void	ft_gg_g(t_root root);
void	ft_gg_d(t_root root);

void	draw_link(t_root root, int x_offset, int y_offset);
void	draw_rubis(t_root root, int x_offset, int y_offset);
void	draw_floor1(t_root root, int x_offset, int y_offset);
void	draw_tree(t_root root, int x_offset, int y_offset);
void	draw_ladder(t_root root, int x_offset, int y_offset);
void	draw_vertical_ennemy(t_root root, int x_offset, int y_offset);
void	draw_horizontal_ennemy(t_root root, int x_offset, int y_offset);
void	draw_game_over(t_root root, int x_offset, int y_offset);

int		name_verif(char *name);
void	parsing_map(t_root root);
void	is_rectangle(t_root root);
void	only_walls(t_root root);
void	only_walls_2(t_root root, int j);
void	get_player_pos(t_root root);
void	get_exit_pos(t_root root);
void	get_nb_coll(t_root root);
int		has_a_2(t_root root);
void	get_flooded_map(t_root root);
void	ft_preflood_player(t_root root);
void	ft_flood_all(t_root root);
void	ft_affiche_flooded(t_root root);
void	ft_valid_flood(t_root root);
void	map_verif(t_root root);
void	get_rectangle(t_root root);
void	get_map(t_root root);
void	draw_map(t_root root);
void	re_draw(t_root root);
void	root_init(t_root *root, char *map, char **env);
void	init_lang(t_root *root, char **env);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	any_move(t_root root, int x, int y);
void	en_key_press(int keycode, t_root *root);
void	en_key_release(int keycode, t_root *root);
void	fr_key_press(int keycode, t_root *root);
void	fr_key_release(int keycode, t_root *root);
void	reset_orientation(t_root root);

void	pictures_first_init(t_root root);
void	get_pics(t_root root);
void	launch_init(t_root root);
void	get_content_pics_1(t_root root);
void	get_content_pics_2(t_root root);
void	get_ennemy_pics(t_root root);
void	get_char_pics_1(t_root root);
void	get_char_pics_2(t_root root);
void	get_char_pics_3(t_root root);
int		animations(t_root *root);
void	clear_number(t_root root);
int		player_animation(t_root *root);
void	count_v_ennemies(t_root root);
void	set_v_ennemies_location(t_root root);
void	count_h_ennemies(t_root root);
void	set_h_ennemies_location(t_root root);
void	ennemy_move_left_or_right(t_root *root, int j);
void	horizontal_ennemy_move_2(t_root *root, int j);
void	horizontal_ennemy_move(t_root *root, int j);
void	horizontal_ennemy_pattern(t_root *root);
int		gg_animation(t_root *root);
void	ft_game_over(t_root root);

#endif