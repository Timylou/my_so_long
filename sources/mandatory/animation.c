#include "so_long.h"

void	ft_walk_animation(t_game *game, int look_left, long time)
{
	float	player_x;
	float	player_y;

	player_x = game->player->x * 64 - game->cam_x;
	player_y = game->player->y * 64 - game->cam_y;
	if (time < 250)
		ft_put_image_clean(game->player->walk[0 + look_left * 4],
			player_x, player_y, game->frame);
	else if (time < 500)
		ft_put_image_clean(game->player->walk[1 + look_left * 4],
			player_x, player_y, game->frame);
	else if (time < 750)
		ft_put_image_clean(game->player->walk[2 + look_left * 4],
			player_x, player_y, game->frame);
	else
		ft_put_image_clean(game->player->walk[3 + look_left * 4],
			player_x, player_y, game->frame);
}

void	ft_idle_animation(t_game *game, int look_left, long time)
{
	float	player_x;
	float	player_y;

	player_x = game->player->x * 64 - game->cam_x;
	player_y = game->player->y * 64 - game->cam_y;
	if (time < 500)
		ft_put_image_clean(game->player->idle[0 + look_left * 2],
			player_x, player_y, game->frame);
	else
		ft_put_image_clean(game->player->idle[1 + look_left * 2],
			player_x, player_y, game->frame);
}

void	ft_run_animation(t_game *game, int look_left, long time)
{
	float	px;
	float	py;
	t_img	**run;

	run = game->player->run;
	px = game->player->x * 64 - game->cam_x;
	py = game->player->y * 64 - game->cam_y;
	if (time < 125)
		ft_put_image_clean(run[0 + look_left * 8], px, py, game->frame);
	else if (time < 250)
		ft_put_image_clean(run[1 + look_left * 8], px, py, game->frame);
	else if (time < 375)
		ft_put_image_clean(run[2 + look_left * 8], px, py, game->frame);
	else if (time < 500)
		ft_put_image_clean(run[3 + look_left * 8], px, py, game->frame);
	else if (time < 625)
		ft_put_image_clean(run[4 + look_left * 8], px, py, game->frame);
	else if (time < 750)
		ft_put_image_clean(run[5 + look_left * 8], px, py, game->frame);
	else if (time < 875)
		ft_put_image_clean(run[6 + look_left * 8], px, py, game->frame);
	else
		ft_put_image_clean(run[7 + look_left * 8], px, py, game->frame);
}

void	ft_exit_animation(t_game *game, int x, int y)
{
	long	time;

	time = get_time_ms() % 1000;
	if (time < 167)
		ft_put_image_clean(game->exit[0], x, y - 60, game->frame);
	else if (time < 333)
		ft_put_image_clean(game->exit[1], x, y - 60, game->frame);
	else if (time < 500)
		ft_put_image_clean(game->exit[2], x, y - 60, game->frame);
	else if (time < 666)
		ft_put_image_clean(game->exit[3], x, y - 60, game->frame);
	else if (time < 830)
		ft_put_image_clean(game->exit[4], x, y - 60, game->frame);
	else
		ft_put_image_clean(game->exit[5], x, y - 60, game->frame);
}

void	ft_apple_animation(t_game *game, int x, int y)
{
	long	time;

	time = get_time_ms() % 1000;
	if (time < 250)
		ft_put_image_clean(game->apple[0], x + 32, y, game->frame);
	else if (time < 500)
		ft_put_image_clean(game->apple[1], x + 32, y, game->frame);
	else if (time < 750)
		ft_put_image_clean(game->apple[2], x + 32, y, game->frame);
	else
		ft_put_image_clean(game->apple[3], x + 32, y, game->frame);
}
