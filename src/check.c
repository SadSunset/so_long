/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbinary <fbinary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:13:22 by fbinary           #+#    #+#             */
/*   Updated: 2022/06/25 14:13:24 by fbinary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_size_map2(char *line, int j, int fd, t_game *game)
{
	int	length;

	while (line)
	{
		if (line != NULL)
		{
			if (line[ft_strlen(line) - 1] == '\n')
				length = ft_strlen(line) - 1;
			else
				length = ft_strlen(line);
			if (game->win_draw.x != length)
			{
				write(1, "check line length!\n", 19);
				exit(0);
			}
			line = get_next_line(fd);
			free(line);
		}
		j++;
	}
	game->win_draw.y = j;
}

void	check_chr(char *path)
{
	int		fd;
	int		i;
	char	*line;

	line = NULL;
	fd = fd_open(path);
	while (fd > 0)
	{
		i = 0;
		line = get_next_line(fd);
		if (!line)
			break ;
		while (line[i] && line[i] != '\n')
		{
			if (line[i] != '1' && line[i] != '0' && line[i] != 'P' && line[i] \
			!= 'E' && line[i] != 'C' && line[i] != 'A')
			{
				write(1, "check character! \n", 17);
				exit (0);
			}
			i++;
		}
		free(line);
	}
}

void	check_size_map(char *path, t_game **game)
{
	int		fd;
	char	*line;
	int		j;

	*game = malloc(sizeof(t_game));
	line = NULL;
	fd = fd_open(path);
	j = 0;
	line = get_next_line(fd);
	(*game)->win_draw.x = ft_strlen(line) - 1;
	check_size_map2(line, j, fd, *game);
	free(line);
}

void	read_map(char *path, t_game *game)
{
	int	fd;
	int	i;

	game->score = 0;
	i = 0;
	game->file_map = NULL;
	game->file_map = malloc(sizeof(t_game) * game->win_draw.y);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit(0);
	game->file_map[i] = get_next_line(fd);
	while (game->file_map[i])
	{
		i++;
		game->file_map[i] = get_next_line(fd);
	}
	game->chr.player = 0;
	game->chr.exit = 0;
	search_chr(game);
}
