/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:44:48 by yel-mens          #+#    #+#             */
/*   Updated: 2025/02/04 13:58:27 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_init_map(t_game *game)
{
	int	*map;
	int	len;
	int	i;

	len = game->width * game->height;
	map = malloc(sizeof(int) * len);
	if (!map)
		return (0);
	i = 0;
	while (i < len)
		map[i++] = EMPTY;
	
}
