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

int		valid_space(char **workspace, int x, int y, char *figure, int wall)
{
	int	x1;
	int	i;
	int	d;
	
	i = 0;
	d = 0;
	x1 = (figure[0] == '.') ? (x - 1) : x;
	x = (figure[0] == '.') ? (x - 1) : x;
	while (figure[i])
	{
		if (figure[i] == '.')
			x++;
		else if (figure[i] == '\n')
		{
			x = x1;
			y++;
		}
		else if(workspace[y][x] != '.' || x++ >= wall || y >= wall)
			return (-1);
		i++;
	}
	return (0);
}

void	put_element(char **workspace, int x, int y, char *figure)
{	
	int	x1;
	int	i;
	int	d;
	
	x1 = (figure[0] == '.') ? (x - 1) : x;
	x = (figure[0] == '.') ? (x - 1) : x;
	i = 0;
	d = 0;
	while (figure[i])
	{

		if (figure[i] == '.')
			x++;
		else if (figure[i] == '\n')
		{
			x = x1;
			y++;
		}
		else
			workspace[y][x++] = figure[i];
		i++;
	}
}

char	**make_workspace()
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
					free (workspace[i]);
				free (workspace);			
			}
		else
			memset((void*)workspace[i], '.', MAX);
		workspace[i++][MAX] = '\0';
	}
	workspace[MAX + 1] = NULL;
	return (workspace);
}

int		search_xy(char *figure, char **workspace, int pst, int wall)
{
	if (!(valid_space(workspace, pst, pst, figure, wall)))
	{
		put_element(workspace, pst, pst, figure);
		return (0);
	}
	return (-1);
}

int		search_oy(char *figure, char **workspace, int pst, int wall, int ny)
{
	int	i;
	int	d;

	d = -1;
	while (d++ < ny)
	{
		i = 0;
		while (i < pst)
		{
			if (!(valid_space(workspace, pst + d, i, figure, wall)))
			{
				put_element(workspace, pst + d, i, figure);
				return (0);
			}
			i++;
		}
	}
	return (-1);
}

int		search_ox(char *figure, char **workspace, int pst, int wall, int nx)
{
	int	i;
	int	d;

	d = -1;
	while (d++ < nx)
	{
		i = 0;
		while (i < pst)
		{
			if (!(valid_space(workspace, i, pst + d, figure, wall)))
			{
				put_element(workspace, i, pst + d, figure);
				return (0);
			}
			i++;
		}
	}
	return (-1);
}

int		find_and_put(char *figure, char **workspace, int d, int wall, int nx, int ny)
{
	int	i;

	i = 0;
	while (i <= wall)
	{
		if (d == 1)
		{
			if (!(search_ox(figure, workspace, i, wall, nx)))
				return (0);
			if (!(search_oy(figure, workspace, i, wall, ny)))
				return (0);
			if (!(search_xy(figure, workspace, i, wall)))
				return (0);
		}
		if	(d == 0)
		{
			if (!(search_oy(figure, workspace, i, wall, ny)))
				return (0);
			if (!(search_ox(figure, workspace, i, wall, nx)))
				return (0);
			if (!(search_xy(figure, workspace, i, wall)))
				return (0);
		}
		i++;	
	}
	return (-1);
}

int		good_ox(char **workspace, int i)
{
	char	*test;

	test = ft_strnew(MAX + 1);
	ft_memset((void*)test, '.', MAX);
	if ((ft_strcmp(workspace[i], test)))
		return (1);
	return (0);
}

int		good_oy(char **workspace, int i)
{
	int	o;

	o = 0;
	while (o <= i)
		if (workspace[o++][i] != '.')
			return (1);
	return (0);
}

void	change_to_ltr(char **str, char chr)
{
	int	i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '#')
			(*str)[i] = chr;
		i++;
	}
}

void    swap(char **x1, char **x2)
{
    char *x;

    x = *x1;
    *x1 = *x2;
    *x2 = x;
}

void	clear_workspace(char **workspace)
{
	int i;

	i = 0;
	while (good_ox(workspace, i))
		ft_memset(workspace[i++], '.', MAX);
}

int		find_empty_space(char *figure, char **workspace, int wall)
{
	int	d;
	int	nx;
	int	ny;

	nx = 1;
	ny = 1;
	d = (figure == B2 || figure == C2 || figure == D2 || figure ==\
		E4 || figure == F2 || figure == F4 || figure == G2 || figure == G4) ? 0 : 1;
	if (figure == B2)
		ny = 3;
	else if (figure == B1)
		nx = 3;
	else if (figure == E2 || figure == F4)
		ny = 2;
	if ((find_and_put(figure, workspace, d, wall, nx, ny)))
	{
		clear_workspace(workspace);
		return (-1);
	}
	return (0);
}

int		per(char **arr, int st, int ls, char **workspace, int wall)
{
    int i;
    int k;
	int	d;

    i = 0;
    k = 0;
	d = 0;
    if(st == ls)
	{
        while(k < ls)
			if ((find_empty_space(arr[k++], workspace, wall)))
				return (1);
		return (0);
	}
    else
    {
        i = st;
        while(i < ls)
        {
            swap(arr + st, arr + i);
            if (!(per(arr, st + 1, ls, workspace, wall)))
				return (0);
            swap(arr + st, arr + i);
            i++;
        }
    }
	return (1);
}

int		main(int ac, char **av)
{
	char 	**workspace;
	char	**test;
	char	chr;
	int		i;
	int		o;
	int		wall;

	wall = 4;
	srand (time(NULL));
	i = 0;
	chr = 'A';
	test = (char**)malloc(sizeof(char*) * 26);
	test[0] = ft_strdup(A1);
	test[1] = ft_strdup(A1);
	test[2] = ft_strdup(A1);
	test[3] = ft_strdup(A1);
	test[4] = 0;
	test[5] = 0;
	workspace = make_workspace();
	i = 0;
	while (test[i])
	{
		change_to_ltr(&test[i], chr++);
		printf("%s\n\n", test[i++]);
	}
	per(test, 0, i, workspace, wall);
	printf("\n\n");
	i = 0;
	while (workspace[i])
	{
		o = 0;
		while (workspace[i][o])
			printf("%c ", workspace[i][o++]);
		printf("\n");
		i++;
	}
	printf("%s\n", av[ac - 1]);
	return (ac);
}
