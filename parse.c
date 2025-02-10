/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:58:33 by yel-mens          #+#    #+#             */
/*   Updated: 2025/02/10 19:25:22 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

static void	ft_check_name(char *name, t_game *game)
{
	int len;

	len = 0;
	while (name[len])
		len++;
	if (len < 4)
		ft_error("map name too short", game);
	if (name[len - 4] == '.' && name[len - 3] == 'b' && name[len - 2] == 'e'
		&& name [len - 1] == 'r')
		return ;
	ft_error("The map must be a .ber", game);
}

static void	ft_read_map(t_map *map, int height, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		map->height = height;
		map->temp_map = malloc(sizeof(char *) * height);
		return ;
	}
	ft_read_map(map, height + 1, fd);
	map->temp_map[height] = line;
}

static void	ft_fill_map(t_game *game, int fd)
{
	t_map	*map;
	int		i;

	map = malloc(sizeof(t_map));
	if (!map)
		ft_error("malloc map", game);
	map->map = NULL;
	map->temp_map = NULL;
	game->map = map;
	ft_read_map(map, 0, fd);
	if (!map->temp_map[0])
		ft_error("read map error", game);
	i = 0;
	while (map->temp_map[0][i])
		i++;
	map->width = i - 1;
}

void	ft_parse(char **argv, t_game *game)
{
	int	fd;

	ft_check_name(argv[1], game);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error(argv[1], game);
	ft_fill_map(game, fd);
}

