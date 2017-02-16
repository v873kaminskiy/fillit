/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 15:55:05 by vkaminsk          #+#    #+#             */
/*   Updated: 2016/12/28 15:55:06 by vkaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/fillit.h"

void		line_saver(int tet, int num_tets, char **board, int size)
{
	if (tet == (num_tets))
	{
		print_map(&board, size);
		exit(EXIT_SUCCESS);
	}
}

int			is_valid_tetrimino(char **tetrimino)
{
	t_pos	pos;
	int		i;
	int		j;
	int		hashes_found;

	i = 0;
	while (i < 19)
	{
		j = 0;
		pos.row = -1;
		hashes_found = 0;
		while (++pos.row < 4)
		{
			pos.col = -1;
			while (++pos.col < 4)
				if (g_tetriminos[i][j++] == '#'
					&& tetrimino[pos.row][pos.col] == '#')
					hashes_found++;
			j++;
		}
		i++;
		if (hashes_found == 4)
			return (1);
	}
	return (0);
}

static	int	valid_hashes(t_list **list)
{
	t_list	*tmp;
	int		index;
	int		count;
	char	c;

	tmp = *list;
	while (tmp && (index = -1))
	{
		count = 0;
		while ((c = *(tmp->data + ++index)))
			if (c == '#')
				count++;
		if (count > 4)
			return (0);
		tmp = tmp->next;
	}
	return (count == 4);
}

static	int	valid_file(char *buffer, int chars_read)
{
	int		index;

	index = 0;
	while (index < chars_read)
	{
		if (index == 20 || (index % 5) == 4)
		{
			if (!(buffer[index] == '\n' || buffer[index] == '\0'))
			{
				return (0);
			}
		}
		else if (!(buffer[index] == '#' || buffer[index] == '.'))
		{
			return (0);
		}
		index++;
	}
	return (1);
}

int			file_read_create(char *file_name, t_list **list)
{
	char	buffer[546];
	int		fd;
	int		chars_read;

	ft_memset(buffer, '\0', 546);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		ft_error(2);
	while ((chars_read = read(fd, buffer, 21)) == 21)
		(valid_file(buffer, chars_read)) ?
			ft_list_push_back(list, ft_strndup(buffer, chars_read))
			: ft_error(2);
	if (chars_read == 20)
		if (valid_file(buffer, chars_read))
		{
			ft_list_push_back(list, ft_strndup(buffer, chars_read));
			if (!(valid_hashes(list)))
				ft_error(2);
		}
		else
			ft_error(2);
	else
		ft_error(2);
	close(fd);
	return (count_num_tets(list));
}
