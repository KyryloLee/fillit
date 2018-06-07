#include "libft.h"

char	*read_input(void);

int		main()
{
	char	*res;
	int		i;

	i = 0;
	res = read_input();
	ft_putstr(res);
	if (res == NULL)
		return (0);
	ft_putstr(res);

	return (0);
}
