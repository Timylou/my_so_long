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
# include <sys/time.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "mlx.h"

# define VELOCITY	7
# define GRAVITY	15

typedef struct s_img
{
	void	*img;
	char	*data;
	int		bpp;
	int		size_line;
	int		edn;
	int		width;
	int		height;
	long	x;
	long	y;
}				t_img;

typedef struct t_player
{
	float	x;
	float	y;
	float	velocity;

	int		key_jump;
	int		key_run;
	int		key_left;
	int		key_right;

	t_img	*idle[4];
	t_img	*walk[8];
	t_img	*run[16];
	t_img	*jump[16];
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

	float		cam_x;
	float		cam_y;

	int			coins;

	t_img		*backgrounds[3];
	t_img		*platforms[7];
	t_img		*exit[6];
	t_img		*apple[4];
	t_img		*star[4];
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
void	ft_free_mlx_win(t_game *game);
void	ft_error(char *msg, t_game *game);

/* * * * * *
 *  image *
 * * * * * */

int		ft_get_pixel(t_img *img, int x, int y);
void	ft_put_pixel_clean(t_img *img, int x, int y, int color);
void	ft_put_pixel(t_img *img, int x, int y, int color);
void	ft_put_image_clean(t_img *img, int x_off, int y_off, t_img *buff);
void	ft_put_image(t_img *img, int x_offset, int y_offset, t_img *buffer);
t_img	*ft_open_image(void *mlx, char *name, int width, int height);
void	*flip_xpm_horizontally(t_img *src, t_game *game);

/* * * * * * * * *
 *  background *
 * * * * * * * * */

void	ft_init_background(t_game *game);
void	ft_travelling_right(t_game *game);
void	ft_travelling_left(t_game *game);

/* * * * * *
 *  input *
 * * * * * */

int		ft_handle_input(int keysym, t_game *game);
int		ft_handle_release(int keysym, t_game *game);

/* * * * * * *
 *  player *
 * * * * * * */

void	ft_init_player_images(t_player *player, t_game *game, int i);
void	ft_set_pos_player(t_game *game, int x, int y);
void	ft_move_player(t_game *game, float dt);
void	ft_move_camera(t_game *game, float speed);
float	ft_jump(t_game *game, float dt);
int		ft_check_mouvement(char block);

/* * * * * * * * *
 *  animation *
 * * * * * * * * */

void	ft_walk_animation(t_game *game, int look_left, long time);
void	ft_idle_animation(t_game *game, int look_left, long time);
void	ft_run_animation(t_game *game, int look_left, long time);
void	ft_exit_animation(t_game *game, int x, int y);
void	ft_apple_animation(t_game *game, int x, int y);
void	ft_star_animation(t_game *game, int x, int y);
void	ft_jump_animation(t_game *game, int left);

/* * * * * *
 *  loop *
 * * * * * */

void	ft_clear_frame(t_game *game);
void	ft_draw_platforms(t_game *game);
void	ft_draw_player(t_game *game, long time);
int		ft_loop(t_game *game);

/* * * * * *
 *  parse *
 * * * * * */

void	ft_parse(t_game *game, char *filemap);
void	ft_change_map(t_game *game);

/* * * * * * * *
 *  platform *
 * * * * * * * */

void	ft_init_platforms(t_game *game);
t_img	*ft_get_tile(t_img *tileset, int tilesize, int tilenum, t_game *game);

/* * * * * *
 *  time *
 * * * * * */

long	get_time_ms(void);
float	get_delta_time(void);

/* * * * * *
 *  utils *
 * * * * * */

void	*ft_calloc(size_t nmemb, size_t size);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(char *str);

#endif
