/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 15:55:17 by vkaminsk          #+#    #+#             */
/*   Updated: 2016/12/28 15:55:18 by vkaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/fillit.h"

void		ft_error(int ac)
{
	if (ac != 2)
		ft_putstr("usage: fillit input_file\n");
	else
		ft_putstr("error\n");
	exit(EXIT_FAILURE);
}

char		**convert_1d_to_2d(char *tetrimino1d)
{
	char	**new;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	new = (char **)malloc(sizeof(char *) * 4);
	while (i < 4)
	{
		j = 0;
		new[i] = (char *)malloc(sizeof(char) * 4);
		while (j < 4)
		{
			new[i][j] = tetrimino1d[k];
			k++;
			j++;
		}
		k++;
		i++;
	}
	return (new);
}

void		shift_origin(char **tet)
{
	t_pos	pos;
	t_pos	min;

	pos.col = -1;
	pos.row = -1;
	min.col = 4;
	min.row = 4;
	while (++(pos.row) < 4 && (pos.col = -1))
		while (++(pos.col) < 4)
		{
			if (tet[pos.row][pos.col] == '#' && pos.col < min.col)
				min.col = pos.col;
			if (tet[pos.row][pos.col] == '#' && pos.row < min.row)
				min.row = pos.row;
		}
	pos.row = -1;
	while (++(pos.row) < 4 && (pos.col = -1) &&
		((min.col != 0) || (min.row != 0)))
		while (++(pos.col) < 4)
			if (tet[pos.row][pos.col] == '#')
			{
				tet[pos.row - min.row][pos.col - min.col] = '#';
				tet[pos.row][pos.col] = '.';
			}
}

void		push_pos(t_pos *pos, t_pos **stack, int *tet)
{
	if (*tet >= 26)
		ft_error(2);
	(stack[0][*tet]) = *pos;
	*tet += 1;
	pos->row = 0;
	pos->col = 0;
}

t_pos		pop_pos(t_pos **stack, int *tet, int size, char **board)
{
	t_pos	res;

	if (*tet == -1)
		ft_error(2);
	*tet -= 1;
	res = stack[0][*tet];
	stack[0][*tet].col = 0;
	stack[0][*tet].row = 0;
	ft_remove(('A' + *tet), &board, size);
	return (res);
}
