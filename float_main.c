#include "ft_printf.h"
#include <stdio.h>

t_float		*get_params(t_format_list *format_list, double f);
void		*get_fstr(t_float *fl);

int     main(int ac, char **av)
{
	t_format_list	*flist;
	t_float			*fl;
	double			d;

	d = 432432443232;
	fl = get_params(flist, d);
	get_fstr(fl);
	printf("%s\n", fl->str);
//	printf("%.200f\n", d);
	return (0);
}
