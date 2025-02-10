/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:04:07 by yel-mens          #+#    #+#             */
/*   Updated: 2025/02/10 18:11:58 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (0);
	game = ft_init_game(argv);
	if (!game)
		return (EXIT_FAILURE);
	mlx_hook(game->win, KeyPress, KeyPressMask, ft_handle_input, game);
	mlx_hook(game->win, DestroyNotify, 0, mlx_loop_end, game->mlx);
	mlx_loop(game->mlx);
	ft_mini_free(game);
	return (EXIT_SUCCESS);
}
