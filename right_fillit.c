/****************************************************************************/
/*                                                                          */
/*                                                       :::      ::::::::  */
/*  find_position.c                                    :+:      :+:    :+:  */
/*                                                   +:+ +:+         +:+    */
/*  By: klee <marvin@42.fr>                        +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+          */
/*  Created: 2017/11/24 10:27:04 by klee              #+#    #+#            */
/*  Updated: 2017/11/24 10:31:43 by klee             ###   ########.fr      */
/*                                                                          */
/****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "lst_elements.h"
#include <string.h>
#include <time.h>
#include "libft.h"

int		valid_space(char **workspace, int x, int y, t_tetr *figure, int wall)
{
	int i;
	int nx;
	int ny;

	i = 0;
	nx = figure->x[0];
	ny = figure->y[0];
	while (i < 4)
	{
		printf("%d %d\n", x, y);
		if (workspace[x + (figure->x[i]) - nx][y + (figure->y[i]) - ny\
			] != '.' || (x + figure->x[i] - nx) >= wall || (y + figure->y\
			[i] - ny) >= wall || ((x + figure->x[i] - \
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
			memset((void*)workspace[i], '.', MAX);
		workspace[i++][MAX] = '\0';
	}
	workspace[MAX + 1] = NULL;
	return (workspace);
}

int		find_position(char **workspace, t_tetr *input, int x, int y, int wall)
{
	int d;

	d = 0;
	x = (y >= wall) ? (x + 1) : x;
	y = (y >= wall) ? 0 : y;
	if (x >= wall && input->next != NULL)
		return (-1);
	if (x < wall && input->next == NULL)
		return (0);
	if (x >= wall || input->next == NULL)
		return (-1);
	// printf("%d\n", valid_space(workspace, x, y, input, wall));
	if (!(valid_space(workspace, x, y, input, wall)))
	{
		put_element(workspace, x, y, input);
		d = find_position(workspace, input->next, 0, 0, wall);
		if (d)
		{
			del_element(workspace, x, y, input);
			return (find_position(workspace, input, x, y + 1, wall)) ? \
			(-1) : (0);
		}
	}
	else if ((valid_space(workspace, x, y, input, wall)))
	{
		if (find_position(workspace, input, x, y + 1, wall))
			return (-1);
	}
	return (0);
}
