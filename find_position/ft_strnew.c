/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 11:57:13 by klee              #+#    #+#             */
/*   Updated: 2017/11/18 10:57:17 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*res;

	res = (char*)malloc(sizeof(char) * (size + 1));
	if (res == NULL)
		return (0);
	ft_bzero(res, size + 1);
	return (res);
}
