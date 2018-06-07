/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recognize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 11:00:14 by dborysen          #+#    #+#             */
/*   Updated: 2017/12/01 16:08:56 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lst_elements.h"

int			ft_countfig(char *s)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (s[i])
	{
		if ((s[i] == '\n' && s[i + 1] == '\n') || s[i + 1] == '\0')
			c++;
		i++;
	}
	return (c);
}

void		ft_crdwrt(t_tetr **bl, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			(*bl)->x[j] = i / 5;
			(*bl)->y[j] = i % 5;
			j++;
		}
		i++;
	}
}

t_tetr		*ft_gettetr(char *s)
{
	int		i;
	int		g;
	char	order;
	t_tetr	*tmp;
	t_tetr	*lst;

	i = 0;
	order = 65;
	g = ft_countfig(s);
	if (!(lst = (t_tetr *)malloc(sizeof(t_tetr))))
		return (NULL);
	tmp = lst;
	while (g > 0)
	{
		tmp->order = order;
		ft_crdwrt(&tmp, ft_strsub(s, i, 20));
		if (!(tmp->next = (t_tetr *)malloc(sizeof(t_tetr))))
			return (NULL);
		tmp = tmp->next;
		i += 21;
		order++;
		g--;
	}
	tmp->next = NULL;
	return (lst);
}
