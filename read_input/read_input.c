/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 10:39:33 by klee              #+#    #+#             */
/*   Updated: 2017/11/22 15:41:34 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"

char	*read_input(void)
{
	int		f1;
	int		ret;
	char	buf[2];
	char	*res;

	ret = 0;
	res = ft_strnew(550);
	f1 = open("sample.fillit", O_RDONLY);
	if (f1 == -1)
		return (0);
	while ((ret = read(f1, buf, 1)))
	{
		buf[ret] = '\0';
		ft_strlcat(res, buf, 550);
	}
	if (ft_strlen(res) > 546)
	{
		ft_strdel(&res);
		ft_putstr("error\n");
		return (0);
	}
	close(f1)
	return (res);
}
