/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:15:07 by yel-mens          #+#    #+#             */
/*   Updated: 2025/12/03 20:15:09 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "mlx.h"

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

typedef struct t_player
{
	float	x;
	float	y;

	int		key_up;
	int		key_down;
	int		key_left;
	int		key_right;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;

	int			w_width;
	int			w_height;
	
	char		**map;
	int			m_width;
	int			m_height;
	
	t_player	*player;
	t_img		*frame;
}				t_game;

/* * * * * *
 *  init *
 * * * * * */

t_game	*ft_init_game(void);

/* * * * * *
 *  free *
 * * * * * */

void	ft_free_all(t_game *game);
void	ft_free_image(t_img *img, t_game *game);
void	ft_error(char *msg, t_game *game);

/* * * * * *
 *  image *
 * * * * * */

int		ft_get_pixel(t_img *img, int x, int y);
void	ft_put_pixel(t_img *img, int x, int y, int color);
t_img	*ft_open_image(void *mlx, char *name, int width, int height);

/* * * * * *
 *  utils *
 * * * * * */

void	*ft_calloc(size_t nmemb, size_t size);
void	ft_putstr_fd(char *s, int fd);

 #endif
