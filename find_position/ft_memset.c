/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 12:28:33 by klee              #+#    #+#             */
/*   Updated: 2017/11/13 13:29:06 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*r1;

	i = 0;
	r1 = (unsigned char*)b;
	while (i < len)
		r1[i++] = (unsigned char)c;
	return (b);
}
