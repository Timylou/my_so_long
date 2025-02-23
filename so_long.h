/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:36:36 by yel-mens          #+#    #+#             */
/*   Updated: 2025/02/20 17:50:17 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "minilibx-linux/mlx.h"

typedef enum e_direction
{
	UP,
	DOWN,
	RIGHT,
	LEFT
}			t_direction;

typedef enum e_case
{
	EMPTY,
	COIN,
	WALL,
	EXIT,
	PLAYER
}			t_case;

typedef struct s_img
{
	void	*img;
	char	*data;
	int		bpp;
	int		size_line;
	int		edn;
	int		width;
	int		height;
	int		x;
	int		y;
}				t_img;

typedef struct s_map
{
	t_case	**map;
	char	**temp_map;
	int		width;
	int		height;
}				t_map;

typedef struct s_player
{
	int			x;
	int			y;
	int			coins;
	t_direction	dir;
	t_img		*img_up;
	t_img		*img_down;
	t_img		*img_right;
	t_img		*img_left;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		*ground;
	t_img		*wall;
	t_img		*img_coin;
	t_img		*exit;
	t_img		*buffer;
	t_map		*map;
	t_player	*player;
	int			width;
	int			height;
	int			coins;
	int			steps;
}				t_game;

/* * * * * *
 * Images *
 * * * * * */
int		ft_get_pixel(t_img *img, int x, int y);
void	ft_put_pixel(t_img *img, int x, int y, int color);
void	ft_put_image(t_img *img, int x_offset, int y_offset, t_img *buffer);
t_img	*ft_open_image(void	*mlx, char *name, int size[2]);
void	ft_map_to_buffer(t_game *game);

/* * * * *
 * Game *
 * * * * */
t_game	*ft_init_game(char **argv);
void	ft_init_game_images(t_game *game);
void	*ft_mini_free(t_game *game);
void	ft_parse(char **argv, t_game *game);
void	ft_translate_map(t_map *map, t_game *game);
void	ft_error(char *name, t_game *game);
void    ft_print_steps(int steps);
void    ft_win(t_game *game);

/* * * * * *
 * Player *
 * * * * * */
void	ft_init_player(t_game *game);
void	ft_player_mouvement(t_player *player, t_game *game, t_direction dir);

/* * * * *
 * Input *
 * * * * */
int		ft_handle_input(int keysym, t_game *game);

#endif
