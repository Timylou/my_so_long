/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:36:36 by yel-mens          #+#    #+#             */
/*   Updated: 2025/02/10 18:11:29 by yel-mens         ###   ########.fr       */
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

typedef enum e_case
{
	EMPTY,
	COIN,
	WALL,
	EXIT,
	PLAYER
}			t_case;

typedef struct s_map
{
	t_case	**map;
	char	**temp_map;
	int		width;
	int		height;
}				t_map;

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

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		*background;
	t_img		*buffer;
	t_map		*map;
	int			width;
	int			height;
}				t_game;

/* * * * * *
 * Images *
 * * * * * */
int		ft_get_pixel(t_img *img, int x, int y);
void	ft_put_pixel(t_img *img, int x, int y, int color);
void	ft_put_image(t_img *img, int x_offset, int y_offset, t_img *buffer);
t_img	*ft_open_image(void	*mlx, char *name, int size[2]);
void	ft_fill_background(t_game *game);

/* * * * *
 * Game *
 * * * * */
t_game	*ft_init_game(char **argv);
void	ft_init_background(t_game *game);
void	*ft_mini_free(t_game *game);
void	ft_parse(char **argv, t_game *game);
void	ft_error(char *name, t_game *game);

/* * * * *
 * Input *
 * * * * */
int	ft_handle_input(int keysym, t_game *game);

#endif
