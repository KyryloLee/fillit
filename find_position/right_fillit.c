/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_fillit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 12:29:00 by klee              #+#    #+#             */
/*   Updated: 2017/12/02 12:29:04 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_elements.h"
#include "libft.h"

int		valid_space(t_space_coord workspace, int x, int y, t_tetr *figure)
{
	int i;
	int nx;
	int ny;

	i = 0;
	nx = figure->x[0];
	ny = figure->y[0];
	while (i < 4)
	{
		if (workspace.workspace[x + (figure->x[i]) - nx]\
			[y + (figure->y[i]) - ny] != '.' || (x + figure->x[i] - \
				nx) >= workspace.wall || (y + figure->y\
			[i] - ny) >= workspace.wall || ((x + figure->x[i] - \
				nx) < 0) || ((y + figure->y[i] - ny) < 0))
			return (-1);
		i++;
	}
	return (0);
}

void	put_element(char **workspace, int x, int y, t_tetr *figure)
{
	int i;
	int nx;
	int ny;

	i = 0;
	nx = figure->x[0];
	ny = figure->y[0];
	while (i < 4)
	{
		workspace[x + (figure->x[i]) - nx][y + (figure->y[i]) - ny\
			] = figure->order;
		i++;
	}
}

void	del_element(char **workspace, int x, int y, t_tetr *figure)
{
	int i;
	int nx;
	int ny;

	i = 0;
	nx = figure->x[0];
	ny = figure->y[0];
	while (i < 4)
	{
		workspace[x + (figure->x[i]) - nx][y + (figure->y[i]) - ny\
		] = '.';
		i++;
	}
}

char	**make_workspace(void)
{
	char	**workspace;
	int		i;
	int		d;

	i = 0;
	d = 1;
	if (!(workspace = (char**)malloc(sizeof(char*) * (MAX + 1))))
		return (0);
	while (i < MAX)
	{
		if (!(workspace[i] = (char*)malloc(sizeof(char) * MAX)))
		{
			while (i-- >= 0)
				free(workspace[i]);
			free(workspace);
		}
		else
			ft_memset((void*)workspace[i], '.', MAX);
		workspace[i++][MAX] = '\0';
	}
	workspace[MAX + 1] = NULL;
	return (workspace);
}

int		find_position(t_space_coord workspace, t_tetr *input, int x, int y)
{
	x = (y >= workspace.wall) ? (x + 1) : x;
	y = (y >= workspace.wall) ? 0 : y;
	if (x >= workspace.wall && input->next != NULL)
		return (-1);
	if (x < workspace.wall && input->next == NULL)
		return (0);
	if (x >= workspace.wall || input->next == NULL)
		return (-1);
	if (!(valid_space(workspace, x, y, input)))
	{
		put_element(workspace.workspace, x, y, input);
		if (find_position(workspace, input->next, 0, 0))
		{
			del_element(workspace.workspace, x, y, input);
			return (find_position(workspace, input, x, y + 1)) ? \
			(-1) : (0);
		}
	}
	else if ((valid_space(workspace, x, y, input)))
	{
		if (find_position(workspace, input, x, y + 1))
			return (-1);
	}
	return (0);
}
