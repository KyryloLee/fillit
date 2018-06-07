/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 12:45:42 by klee              #+#    #+#             */
/*   Updated: 2017/11/16 13:29:26 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		fk_strlen(const char *src)
{
	int i;

	i = 0;
	while (src[i])
		i++;
	return (i + 1);
}

char			*ft_strdup(const char *src)
{
	int		i;
	char	*buff;

	i = 0;
	buff = (char*)malloc(sizeof(char) * fk_strlen(src));
	if (buff == NULL)
		return (0);
	while (i < fk_strlen(src))
	{
		buff[i] = src[i];
		i++;
	}
	return (buff);
}
