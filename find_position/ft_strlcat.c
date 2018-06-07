/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 15:32:18 by klee              #+#    #+#             */
/*   Updated: 2017/11/17 17:47:25 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t	i;
	size_t	o;
	size_t	r;

	i = ft_strlen(s1);
	o = 0;
	r = i;
	if (size == 0)
		return (ft_strlen((char*)s2));
	while (i < size - 1 && (char)s2[o])
		s1[i++] = (char)s2[o++];
	s1[i] = '\0';
	return (size < ft_strlen(s1)) ? \
	(size + ft_strlen((char*)s2)) : (r + ft_strlen((char*)s2));
}
