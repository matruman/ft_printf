/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conv_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matruman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:20:09 by matruman          #+#    #+#             */
/*   Updated: 2019/11/13 13:20:11 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "long_arithmetic.h"

t_float		*get_params(t_format_list *format_list, double f)
{
	t_float		*fl;

	fl = (t_float *)malloc(sizeof(t_float));
	fl->m = (*((unsigned long long *)&f) & 0x000fffffffffffff);
	fl->e = (*((unsigned long long *)&f) & 0x7ff0000000000000) >> 52;
	fl->sign = (char)((*((unsigned long long *)&f) & 0x8000000000000000) >> 63);
	return (fl);
}

void	get_fstr(t_float *fl)
{
	t_big_int	*tmp;
	t_big_int	*tmp1;
	t_big_int	*tmp2;

	tmp = readll_u(fl->m);
	tmp1 = pow_mult(tmp, 5, 52);
	big_int_del(tmp);
	tmp = readll_u(1);
	tmp2 = pow_mult(tmp, 10, 52);
	big_int_del(tmp);
	tmp = b_int_add(tmp1, tmp2);
	big_int_del(tmp1);
	big_int_del(tmp2);
	if (fl->e < 1023)
	{
		tmp1 = pow_mult(tmp, 10, 1023 - fl->e);
		big_int_del(tmp);
		tmp = tmp1;
	}
	tmp1 = pow_mult(tmp, 2, fl->e - 1023);
	fl->str = big_int_tostr(tmp1);
	big_int_del(tmp1);
	big_int_del(tmp);
}

/*
int     print_conv_float(t_format_list *format_list)
{
    char		*fstr;
	double	f;
	int			count;
	t_float		*fl;

	f = va_arg(*(format_list->ap), double);
	fl = get_params(format_list, f);
	get_fstr(fl);
	printf("%s\n", fl->str);
	return (0);
}*/