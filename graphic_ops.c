/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinc <rdinc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:42:50 by rdinc             #+#    #+#             */
/*   Updated: 2023/09/13 16:48:06 by rdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_images_in_game(t_gamecntrl *game)
{
	int	i;
	int	j;

	game->f_image = mlx_xpm_file_to_image(game->mlxpointer,
			"images/floor.xpm", &i, &j);
	game->b_image = mlx_xpm_file_to_image(game->mlxpointer,
			"images/wall.xpm", &i, &j);
	game->p_image = mlx_xpm_file_to_image(game->mlxpointer,
			"images/player.xpm", &i, &j);
	game->e_image = mlx_xpm_file_to_image(game->mlxpointer,
			"images/exit.xpm", &i, &j);
	game->c_image = mlx_xpm_file_to_image(game->mlxpointer,
			"images/collectable.xpm", &i, &j);
}

void	place_graphics(t_gamecntrl *game)
{
	int	height;
	int	width;

	game->collectables = 0;
	height = 0;
	while (height < game->heightmap)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == '1')
				place_barrier(game, height, width);
			if (game->map[height][width] == 'C')
				place_collectable(game, height, width);
			if (game->map[height][width] == 'P')
				place_player(game, height, width);
			if (game->map[height][width] == 'E')
				place_exit(game, height, width);
			if (game->map[height][width] == '0')
				place_floor(game, height, width);
			width++;
		}
		height++;
	}
}
