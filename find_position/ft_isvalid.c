/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is4hesh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:01:12 by dborysen          #+#    #+#             */
/*   Updated: 2017/12/01 12:13:59 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_elements.h"
#include "libft.h"

int	heshc(char *s, int i, int k)
{
	if (s[i] == '#')
		k++;
	return (k);
}

int	symbc(char *s, int i, int d)
{
	if (s[i] == '.' || s[i] == '#')
		d++;
	return (d);
}

int	ft_is4hesh(char *s)
{
	int i;
	int k;
	int d;

	d = 0;
	k = 0;
	i = 0;
	if (!*s)
		return (0);
	while (s[i])
	{
		k = heshc(s, i, k);
		d = symbc(s, i, d);
		if (((s[i] == '\n' && s[i + 1] == '\n') || s[i + 1] == '\0'))
		{
			if (k != 4 || d != 16)
				return (0);
			k = 0;
			d = 0;
		}
		if (s[i] != '\n' && s[i + 1] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int	nbhelp(char *s, int i, int tet, int nb)
{
	if (s[i] == '#')
	{
		if (s[i + 1] == '#')
			nb++;
		if (s[i - 1] == '#')
			nb++;
		if (tet + 5 <= 19)
			if (s[i + 5] == '#')
				nb++;
		if (tet - 5 >= 0)
			if (s[i - 5] == '#')
				nb++;
	}
	return (nb);
}

int	ft_isvalid(char *s)
{
	int i;
	int nb;
	int tet;

	i = 0;
	nb = 0;
	tet = 0;
	if (ft_is4hesh(s) != 0)
	{
		while (s[i])
		{
			nb = nbhelp(s, i, tet, nb);
			if ((s[i] == '\n' && s[i + 1] == '\n') || s[i + 1] == '\0')
			{
				if (nb != 6 && nb != 8)
					return (0);
				nb = 0;
				tet = 0;
			}
			i++;
			tet++;
		}
		return (1);
	}
	return (0);
}
