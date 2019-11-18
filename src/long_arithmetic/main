#include "long_arithmetic.h"
#include <stdio.h>

int     main(int ac, char **av)
{
    t_big_int	*b_int;
	t_big_int	*mult;
	t_big_int	*add;
	char		*str;

	double	d = 11.78678685645673546;
	unsigned long long  m;
	unsigned long long  e;
	m = (*((unsigned long long *)&d) & 0x000fffffffffffff);
	b_int = readll_u(m);
	mult = pow_mult(b_int, 10, 52);
	mult = pow_div(mult, 2, 52);
	mult = b_int_add(mult, pow_mult(readll_u(1), 10, 52));
	mult = pow_mult(mult, 2, 3);
	str = big_int_tostr(mult);
//	printf("%llu\n", m);
//	printf("%s\n", big_int_tostr(b_int));
	printf("%55s\n", str);
	printf("%.55f\n", d);
	return (0);
}