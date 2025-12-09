/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:45:45 by yel-mens          #+#    #+#             */
/*   Updated: 2025/10/23 12:00:21 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_free_imgs(t_game *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (i < 2 && game->player->idle[i])
			ft_free_image(game->player->idle[i], game);
		if (i < 3 && game->backgrounds[i])
			ft_free_image(game->backgrounds[i], game);
		if (i < 4)
			ft_free_image(game->player->walk[i], game);
		if (game->platforms[i])
			ft_free_image(game->platforms[i], game);
		i++;
	}
	if (game->frame)
		ft_free_image(game->frame, game);
}

static void	ft_free_mlx_win(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

static void	ft_free_map(t_game *game)
{
	int	i;

	if (!game->map)
		return ;
	i = 0;
	while (i < game->m_height)
	{
		if (game->map[i])
			free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	ft_free_all(t_game *game)
{
	if (!game)
		return ;
	ft_free_imgs(game);
	ft_free_player(game);
	ft_free_map(game);
	ft_free_mlx_win(game);
	free(game);
}

void	ft_error(char *msg, t_game *game)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	if (game)
		ft_free_all(game);
	exit(EXIT_FAILURE);
}
