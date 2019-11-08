#include "libft.h"

size_t		ft_putstrn(const char *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
