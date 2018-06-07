/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 12:34:27 by klee              #+#    #+#             */
/*   Updated: 2017/12/02 12:34:32 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lst_elements.h"
#include <stdio.h>

int		ft_count(t_tetr *input)
{
	int	i;

	i = 0;
	while (input)
	{
		input = input->next;
		i++;
	}
	return (i - 1);
}

int		ft_sqrt(int nb)
{
	int i;
	int sq;

	i = 1;
	sq = 1;
	if (nb == 0)
		return (0);
	while (i * i < nb)
	{
		i++;
	}
	return (i);
}

void	clear_workspace(char **workspace, int wall)
{
	int i;

	i = 0;
	while (i < wall)
		ft_memset(workspace[i++], '.', wall);
}

void	right_workspace(char **workspace, int wall)
{
	int i;

	i = 0;
	while (i < wall)
		workspace[i++][wall] = '\0';
	ft_memset(workspace[wall], '\0', wall);
}

int		main(int ac, char **av)
{
	t_space_coord	workspace;
	int				i;
	int				o;

	i = 0;
	o = 0;
	if (ac != 2)
	{
		ft_putendl("usage: fillit sample.fillit");
		return (0);
	}
	if (!(ft_isvalid(read_input(av[1]))))
	{
		ft_putendl("error");
		return (0);
	}
	workspace.wall = ft_sqrt(ft_count(ft_gettetr(read_input(av[1]))) * 4);
	workspace.workspace = make_workspace();
	while (find_position(workspace, ft_gettetr(read_input(av[1])), 0, 0))
		clear_workspace(workspace.workspace, workspace.wall++);
	right_workspace(workspace.workspace, workspace.wall);
	while (workspace.workspace[i][0])
		ft_putendl(workspace.workspace[i++]);
	return (0);
}
