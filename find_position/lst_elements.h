/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_elements.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 12:35:23 by klee              #+#    #+#             */
/*   Updated: 2017/12/02 12:36:14 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_ELEMENTS_H
# define LST_ELEMENTS_H
# define MAX 40

typedef struct		s_spase
{
	char			**workspace;
	int				wall;
}					t_space_coord;

typedef struct		s_tetr
{
	char			order;
	int				x[4];
	int				y[4];
	struct s_tetr	*next;
}					t_tetr;

int					valid_space(t_space_coord workspace, int x, int y,
					t_tetr *figure);
void				put_element(char **workspace, int x, int y,
					t_tetr *figure);
t_tetr				*ft_gettetr(char *s);
char				*read_input(char *str);
int					find_position(t_space_coord workspace, t_tetr *input,
					int x, int y);
char				**make_workspace(void);
int					ft_isvalid(char *s);

#endif
