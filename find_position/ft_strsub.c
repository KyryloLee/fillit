/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:29:01 by klee              #+#    #+#             */
/*   Updated: 2017/11/20 11:36:23 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*subs;
	char	*src;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	src = (char*)s;
	if (start > (unsigned int)ft_strlen(src) \
		|| len + start > (unsigned int)ft_strlen(src))
		return (0);
	subs = ft_strnew(len);
	if (!subs)
		return (0);
	src = (char*)s + start;
	while (i++ < len && (*subs++ = *src++))
		;
	return (subs - len);
}
