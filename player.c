/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:30:48 by yel-mens          #+#    #+#             */
/*   Updated: 2025/01/17 12:05:18 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_set_player_null(t_player *player)
{
	player->idle = NULL;
	player->run = NULL;
	player->hurt = NULL;
	player->dead = NULL;
	player->walk = NULL;
	player->jump = NULL;
}

static int	ft_init_player_imgs(t_player *player)
{
	ft_set_player_null(player);
	player->idle = malloc(sizeof(t_img *) * 12);
	if (!player->idle)
		return (0);
	player->walk = malloc(sizeof(t_img **) * 2);
	if (!player->walk)
		return (0);
	player->walk[0] = malloc(sizeof(t_img *) * 12);
	player->walk[1] = malloc(sizeof(t_img *) * 12);
	player->run = malloc(sizeof(t_img *) * 10);
	if (!player->run || !player->walk[0])
		return (0);
	player->jump = malloc(sizeof(t_img **) * 2);
	if (!player->jump || !player->walk[1])
		return (0);
	player->jump[0] = malloc(sizeof(t_img *) * 5);
	player->jump[1] = malloc(sizeof(t_img *) * 5);
	player->hurt = malloc(sizeof(t_img *) * 6);
	if (!player->hurt || !player->jump[0])
		return (0);
	player->dead = malloc(sizeof(t_img *) * 10);
	if (!player->dead || !player->jump[1])
		return (0);
	return (1);
}

static void	ft_free_player(t_player *player)
{
	if (player->idle)
		free(player->idle);
	if (player->run)
		free(player->run);
	if (player->hurt)
		free(player->hurt);
	if (player->dead)
		free(player->dead);
	if (player->walk)
	{
		if (player->walk[0])
			free(player->walk[0]);
		if (player->walk[1])
			free(player->walk[1]);
		free(player->walk);
	}
	if (player->jump)
	{
		if (player->jump[0])
			free(player->jump[0]);
		if (player->jump[1])
			free(player->jump[1]);
		free(player->jump);
	}
	free(player);
}

static int	ft_open_player_images(t_player *player, t_game *game)
{

}

int	ft_init_player(t_game *game)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (0);
	if (!ft_init_player_imgs(player))
	{
		ft_free_player(player);
		game->player = NULL;
		ft_mini_free(game);
		return (0);
	}
	ft_open_player_images(player, game);
	player->pv = 0;
	player->is_running = 0;
	player->is_jumping = 0;
	player->x = 0;
	player->y = 0;
	game->player = player;
	return (1);
}
