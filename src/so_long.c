/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbinary <fbinary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:14:45 by fbinary           #+#    #+#             */
/*   Updated: 2022/06/25 14:14:48 by fbinary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(int key)
{
	(void)key;
	exit(0);
}

void	ft_extension(char *path)
{
	int	i;

	i = 0;
	while (path[i])
		i++;
	if (!(path[i - 1] == 'r' && path[i - 2] == 'e' && path[i - 3] == 'b' && \
	path[i - 4] == '.' && path[i -5] >= 48))
	{
		write(1, "check you path! -> ", 19);
		while (*path)
			write(1, path++, 1);
		write(1, "\n", 1);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		ft_extension(argv[1]);
		check_chr(argv[1]);
		check_size_map(argv[1], &game);
		read_map(argv[1], game);
		game->mlx = mlx_init();
		game->win = mlx_new_window(game->mlx, game->win_draw.x * 50, \
		game->win_draw.y * 50, "so_long");
		mlx_hook(game->win, 17, 0, ft_close, 0);
		map(game->file_map, game);
		mlx_key_hook(game->win, player_moves, &game);
		mlx_loop(game->mlx);
	}
	else
		write(1, "check your arguments!\n", 22);
	return (0);
}
