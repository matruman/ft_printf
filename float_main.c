#include "ft_printf.h"
#include <stdio.h>

t_float		*get_params(t_format_list *format_list, double f);
void		*get_fstr(t_float *fl);

int     main(int ac, char **av)
{
	t_format_list	*flist;
	t_float			*fl;
	double			d;

	d = 0.00000000000000000000000000000000000000000000000000000000000000432432443232;
	fl = get_params(flist, d);
	get_fstr(fl);
	printf("%202.138s\n", fl->str);
	printf("%.200f\n", d);
	return (0);
}