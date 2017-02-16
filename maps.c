/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 15:55:32 by vkaminsk          #+#    #+#             */
/*   Updated: 2016/12/28 15:55:33 by vkaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/fillit.h"

char		***hash_to_alph(char ***alltetriminos, int num_tets)
{
	char	letter;
	int		x;
	int		y;
	int		index;

	index = 0;
	letter = 'A';
	while (index < num_tets && letter <= 'Z')
	{
		y = 0;
		while (y < 4)
		{
			x = 0;
			while (x < 4)
			{
				if (alltetriminos[index][y][x] == '#')
					alltetriminos[index][y][x] = letter;
				x++;
			}
			y++;
		}
		letter++;
		index++;
	}
	return (alltetriminos);
}

int			can_place(char **tetrimino, char ***board, int size, t_pos pos)
{
	int		emptyspace;
	int		x;
	int		y;

	emptyspace = 0;
	y = 0;
	while (y < 4 && (y + pos.row) < size)
	{
		x = 0;
		while (x < 4 && (x + pos.col) < size)
		{
			if (ft_isalpha(tetrimino[y][x])
				&& board[0][pos.row + y][pos.col + x] == '.')
				emptyspace++;
			x++;
		}
		y++;
	}
	if (emptyspace == 4)
	{
		place_tet(tetrimino, board, size, pos);
		return (1);
	}
	return (0);
}

void		place_tet(char **tetrimino, char ***board, int size, t_pos pos)
{
	int		x;
	int		y;
	int		orig_col;

	orig_col = pos.col;
	y = 0;
	while (y < 4 && pos.row < size)
	{
		x = 0;
		pos.col = orig_col;
		while (x < 4 && pos.col < size)
		{
			if (ft_isalpha(tetrimino[y][x]))
				board[0][pos.row][pos.col] = tetrimino[y][x];
			pos.col++;
			x++;
		}
		pos.row++;
		y++;
	}
}

char		**create_board(int size)
{
	char	**board;
	int		x;
	int		y;

	y = 0;
	if (!(board = (char **)malloc(sizeof(char *) * size)))
		return (0);
	while (y < size)
	{
		if (!(board[y] = (char *)malloc(sizeof(char) * size)))
			return (0);
		x = 0;
		while (x < size)
		{
			board[y][x] = '.';
			x++;
		}
		y++;
	}
	return (board);
}

void		print_map(char ***board, int size)
{
	int		x;
	int		y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			ft_putchar(board[0][y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
