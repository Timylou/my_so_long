/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:36:36 by yel-mens          #+#    #+#             */
/*   Updated: 2025/01/16 12:37:02 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "minilibx-linux/mlx.h"

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

typedef struct s_player
{
	t_img	**idle;
	t_img	***walk;
	t_img	**run;
	t_img	***jump;
	t_img	**hurt;
	t_img	**dead;
	int		pv;
	int		is_running;
	int		is_jumping;
	int		x;
	int		y;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		**backgrounds;
	t_img		**platform;
	t_img		*buffer;
	t_player	*player;
	int			width;
	int			height;
}				t_game;

/* * * * * *
 * Images *
 * * * * * */
int		ft_get_pixel(t_img *img, int x, int y);
void	ft_put_pixel(t_img *img, int x, int y, int color);
void	ft_put_image(t_img *img, int x_offset, int y_offset, t_img *buffer);
t_img	*ft_get_tile(t_img *src, int coor[2], int size[2], void *mlx);
t_img	*ft_open_image(void	*mlx, char *name, int size[2], int y);

/* * * * *
 * Game *
 * * * * */
t_game	*ft_init_game(void);
int		ft_init_background(t_game *game);
int		ft_init_buffer(t_game *game);
int		ft_init_platform(t_game *game);
int		ft_init_player(t_game *game);
void	*ft_mini_free(t_game *game);

/* * * * *
 * Input *
 * * * * */
int		ft_handle_input(int keysym, t_game *game);
void	ft_travelling_right(t_game *game);
void	ft_travelling_left(t_game *game);
#endif
