/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinc <rdinc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:43:45 by rdinc             #+#    #+#             */
/*   Updated: 2023/09/13 16:48:40 by rdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_gamecntrl *game)
{
	int	line;

	line = 0;
	if (game->winpointer)
		mlx_destroy_window(game->mlxpointer, game->winpointer);
	free(game->mlxpointer);
	while (line < game->heightmap)
		free(game->map[line++]);
	free(game->map);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_gamecntrl	game;

	if (argc == 2)
	{
		ft_pathchecker(argv[1]);
		ft_imagechecker();
		ft_memset(&game, 0, sizeof(t_gamecntrl));
		map_reading(&game, argv);
		ft_mapchecker(&game);
		game.mlxpointer = mlx_init();
		game.winpointer = mlx_new_window(game.mlxpointer, (game.widthmap * 40),
				(game.heightmap * 40), "so_long");
		place_images_in_game(&game);
		place_graphics(&game);
		mlx_key_hook(game.winpointer, controls_manager, &game);
		mlx_hook(game.winpointer, 17, 0, (void *)exit, 0);
		mlx_loop(game.mlxpointer);
	}
	return (0);
}
