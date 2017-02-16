/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 15:55:41 by vkaminsk          #+#    #+#             */
/*   Updated: 2016/12/28 15:55:42 by vkaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/fillit.h"

t_pos		*create_stack(void)
{
	int		index;
	t_pos	*stack;

	index = 0;
	stack = (t_pos*)malloc(sizeof(t_pos) * 26);
	while (index < 26)
	{
		(stack[index]).col = 0;
		(stack[index++]).row = 0;
	}
	return (stack);
}

void		ft_remove(char c, char ***board, int size)
{
	t_pos	pos;
	int		count;

	count = 0;
	pos.row = 0;
	pos.col = 0;
	while (pos.row < size && (!(pos.col = 0)))
	{
		while (pos.col < size)
		{
			if (board[0][pos.row][pos.col] == c)
			{
				board[0][pos.row][pos.col] = '.';
				count++;
			}
			if (count == 4)
				return ;
			pos.col++;
		}
		pos.row++;
	}
}

static void	we_run_out_of_lines(int *tet, t_pos *pos, t_pos **stack)
{
	*tet = 0;
	pos->col = 0;
	pos->row = 0;
	*stack = create_stack();
}

static void	still_out_of_lines(t_pos *pos)
{
	pos->row++;
	pos->col = -1;
}

int			solve(char ***tetrimino, int num_tets, char **board, int size)
{
	int		tet;
	t_pos	pos;
	t_pos	*stack;

	we_run_out_of_lines(&tet, &pos, &stack);
	while (tet < num_tets)
		if (can_place(tetrimino[tet], &board, size, pos))
		{
			push_pos(&pos, &stack, &tet);
			line_saver(tet, num_tets, board, size);
		}
		else
		{
			if (pos.col == size)
			{
				if (pos.row == (size - 1) && tet == 0)
					return (0);
				else if (pos.row == (size - 1))
					pos = pop_pos(&stack, &tet, size, board);
				else
					still_out_of_lines(&pos);
			}
			pos.col++;
		}
	return (0);
}
