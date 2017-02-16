/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 15:56:10 by vkaminsk          #+#    #+#             */
/*   Updated: 2016/12/28 15:56:10 by vkaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLIT_H

# define _FILLIT_H
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

typedef struct	s_pos
{
	int row;
	int col;
}				t_pos;

extern			char g_tetriminos[19][20];
char			**convert_1d_to_2d(char *tetrimino1d);
void			shift_origin(char **tetrimino);
int				*chars_between_hashes(t_list *list);
int				is_valid_tetrimino(char **tetrimino);
char			**create_board(int size);
int				can_place(char **tetrimino, char ***board, int size, t_pos pos);
void			place_tet(char **tetrimino, char ***board, int size, t_pos pos);
char			*ft_strndup(char *s, size_t n);
void			print_map(char ***board, int size);
int				size_map(int size, int num_tets);
int				solve(char ***tetrimino, int num_tets, char **board, int size);
char			***hash_to_alph(char ***alltetriminos, int num_tets);
void			push_pos(t_pos *pos, t_pos **stack, int *index);
t_pos			pop_pos(t_pos **stack, int *index, int size, char **board);
void			ft_remove(char c, char ***board, int size);
void			ft_error(int ac);
int				count_num_tets(t_list **curr);
int				file_read_create(char *file_name, t_list **list);
void			line_saver(int tet, int num_tets, char **board, int size);
t_pos			*create_stack(void);

#endif
